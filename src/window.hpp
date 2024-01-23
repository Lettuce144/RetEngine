#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <functional>
#include <vector>

#include "glm/ext.hpp"

#include "gl.hpp"
#include "input_events.hpp"
#include "Framebuffer.h"


class Window {

public:
	std::function<void(InputEvent*)> inputCallback = nullptr;

	Window(int, int, const char*, GLFWmonitor*);
	~Window();

	GLFWwindow* glfw() const;

	void makeCurrent() const;
	void swapBuffers() const;

	//void window_size_callback(FrameBuffer* buffer, int width, int height);

	bool isOpen() const;
	void close() const;
	void destroy() const;

	glm::ivec2 size() const;
	glm::vec2 cursorPos() const;

	int inputMode(int) const;
	void setInputMode(int, int) const;

	//void setCursorFollow() const;

	void UnlockCursor();

	bool IsFocused() const;
	void setFocus();
	bool isKeyPressed(int) const;
	bool isKeyReleased(int key) const;

private:
	GLFWwindow* m_glfw = nullptr;

	//The focus is for the ImGui window and not the game
	bool m_bisFocused = false;

	std::vector<int> m_pressedKeys {};

};

#endif // __WINDOW_HPP__
