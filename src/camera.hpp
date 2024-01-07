#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "glm/ext.hpp"

#include "node.hpp"

class Camera : public Node {

public:

  Camera();
  ~Camera();

  //Setup the projection matrix
  glm::mat4 proj();

  virtual void SetFov(float fov) { fov = m_flFov; }
  void Resize(float width, float height);

  //Returns the viewdir of the camera based of the viewmatrix
  glm::vec3 viewDir();

  glm::mat4 cameraMatrix = glm::mat4(1.0f);


private:
	glm::mat4 m_projection;

	float m_flFov = glm::radians(60.0f);
	float m_flzNear = 0.01f;
	float m_flzFar = 100.0f;

};

#endif // __CAMERA_HPP__
