#include <iostream>
#include "gl.hpp"

#pragma once

/*!
* This class is used to create a framebuffer object and a texture to render to.
* Feel free to modify incase you want to attach other buffers as well
*/
class FrameBuffer
{
public:
	FrameBuffer(int width, int height);
	~FrameBuffer();

	unsigned int getFrameBuffer();
	unsigned int getFrameTexture();
	void RescaleFrameBuffer(uint32_t width, uint32_t height);
	void Bind() const;
	void Unbind() const;

private:
	unsigned int fbo;
	unsigned int texture;
	unsigned int rbo;
};

