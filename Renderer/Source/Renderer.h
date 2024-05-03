#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Renderer
{
public:
	Renderer();
	~Renderer();

	// For resizing the window
	static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

	// Initialize the renderer
	virtual void RenderInit(const int& height, const int& width);

	// Render loop
	virtual void Render(GLFWwindow* window);
};
