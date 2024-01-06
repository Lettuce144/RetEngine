#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "ImGuiFileDialog.h"

#include <iostream>
#include <thread>
#include <chrono>

#include "gl.hpp"
#include "window.hpp"
#include "game.hpp"
#include "Framebuffer.h"
#include "Engine.h"

//Move me to a seperate namespace!

#define WND_WIDTH 1280
#define WND_HEIGHT 800
#define WND_TITLE "game"
#define WND_MONITOR glfwGetPrimaryMonitor()

#define PSEUDO_NOSTALGIC_LOADING_DURATION 0000

void DrawTree(const Node* n)
{
	//Set the class name of the node to the hiearchy
	if (ImGui::TreeNode(n->name.c_str())) {
		for (const Node* child : n->children())
			DrawTree(child);
		ImGui::TreePop();
	}
}


int main(int argc, char* argv[]) {
	if (!glfwInit()) {
		std::cerr << "failed to init glfw" << std::endl;
		exit(1);
	}

	const GLFWvidmode* videoMode = glfwGetVideoMode(WND_MONITOR);

	int wWidth = videoMode->width;
	int wHeight = videoMode->height;
	GLFWmonitor* wMonitor = WND_MONITOR;

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		if (arg == "-w" || arg == "--windowed") {
			wWidth = WND_WIDTH;
			wHeight = WND_HEIGHT;
			wMonitor = nullptr;
		}
	}

	Game::window = new Window(wWidth, wHeight, WND_TITLE, wMonitor);
	Game::window->makeCurrent();
	Game::window->inputCallback = Game::input;

	FrameBuffer* buffer = new FrameBuffer(wWidth, wHeight);

	unsigned int sleepFor = PSEUDO_NOSTALGIC_LOADING_DURATION;
	std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
		std::cout << "Framebuffer is complete" << std::endl;

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Game::start();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
	//io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; 
	ImGui::StyleColorsDark();
	ImGui_ImplGlfw_InitForOpenGL(Game::window->glfw(), true);
	ImGui_ImplOpenGL3_Init("#version 330");

	PhysicsObject* obj = nullptr;
	glm::vec2 viewportSize;


	while (Game::window->isOpen()) {
		glfwPollEvents();

		// Update window size and aspect ratio
		int newWidth, newHeight;
		glfwGetFramebufferSize(Game::window->glfw(), &newWidth, &newHeight);

		//buffer->RescaleFrameBuffer(newWidth, newHeight);

		glViewport(0, 0, newWidth, newHeight);

		//Imgui:
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		ImGui::DockSpaceOverViewport();

		ImGui::Begin("Model Importer");
			// open Dialog Simple
			if (ImGui::Button("Open new model"))
				ImGuiFileDialog::Instance()->OpenDialog("ChooseFileDlgKey", "Choose File", ".obj,", ".");

			// display
			if (ImGuiFileDialog::Instance()->Display("ChooseFileDlgKey"))
			{
				// action if OK
				if (ImGuiFileDialog::Instance()->IsOk())
				{
					std::string modelName = ImGuiFileDialog::Instance()->GetCurrentFileName();
					if(obj != nullptr)
						Game::removeObjThing();
						obj = nullptr;
						
					
					obj = Game::spawnObj(modelName);

				}

				// close
				ImGuiFileDialog::Instance()->Close();
			}
		ImGui::End();

		if (obj != nullptr)
		{
			ImGui::Begin("Model Transform");
				ImGui::Text("Model Transform");
				float x, y, z;
				ImGui::SliderFloat("X", &x, -10.0f, 10.0f);
				ImGui::SliderFloat("Y", &y, -10.0f, 10.0f);
				ImGui::SliderFloat("Z", &z, -10.0f, 10.0f);

				Game::setObjThingPos({ x, y, z });
			ImGui::End();
		}

		ImGui::ShowDemoWindow();
		ImGui::Begin("GameWindow");
		{

			// Get the size of the child (i.e. the whole draw size of the windows).
			ImVec2 viewportPanelSize = ImGui::GetContentRegionAvail();
			//What in gods name does this even mean?
			if (viewportSize != *((glm::vec2*)&viewportPanelSize))
			{
				buffer->RescaleFrameBuffer(viewportPanelSize.x, viewportPanelSize.y);
				viewportSize = { viewportPanelSize.x, viewportPanelSize.y };
				PRINT_CONSOLE("Rescaling framebuffer");
				
				//Default player call here
			}

			ImGui::Image((ImTextureID)buffer->getFrameTexture(), ImVec2{viewportSize.x, viewportSize.y}, ImVec2(0, 1), ImVec2(1, 0));
		}
		ImGui::End();

		
		ImGui::Begin("Scene Graph");
			DrawTree(&Game::rootNode);
		ImGui::End();
		

		//Start with capturing the scene here
		buffer->Bind();
		//-------------------------------

		glClearColor(Game::clearColor.r, Game::clearColor.g, Game::clearColor.b,
			Game::clearColor.a);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		Game::update();
		Game::rootNode.draw();

		//-------------------------------
		//And close the framebuffer here
		buffer->Unbind();

		//Draw this above everything else
		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		Game::window->swapBuffers();
	}

	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	buffer->~FrameBuffer();
	Game::end();

	delete Game::window;
	glfwTerminate();

	return 0;
}


