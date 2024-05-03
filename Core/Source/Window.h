#pragma once
#include "Renderer.h"
#include <iostream>

#ifndef WINDOW_H
#define WINDOW_H

class Window
{
public:
	Window(const std::string& name, const int& height, const int& width);
	~Window();

	GLFWwindow* GetWindow() { return m_glfw; }
	bool IsOpen() { return !glfwWindowShouldClose(m_glfw); }

private:
	GLFWwindow* m_glfw = nullptr;
};

#endif