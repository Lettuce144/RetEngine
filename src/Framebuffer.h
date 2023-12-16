#include <iostream>
#include "gl.hpp"

#pragma once
class FrameBuffer
{
public:
	FrameBuffer(float width, float height);
	~FrameBuffer();

	unsigned int getFrameBuffer();
	unsigned int getFrameTexture();
	void RescaleFrameBuffer(float width, float height);
	void Bind() const;
	void Unbind() const;

private:
	unsigned int fbo;
	unsigned int texture;
	unsigned int rbo;
};

