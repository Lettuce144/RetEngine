#include "Window.h"

Window::Window(const std::string& name, const int& height, const int& width)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_glfw = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
	if (m_glfw == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
	}
	glfwMakeContextCurrent(m_glfw);
}

Window::~Window()
{
}