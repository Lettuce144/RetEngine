#include "camera.hpp"

#include "glm/ext.hpp"

#include "game.hpp"

Camera::Camera() {}
Camera::~Camera() {}

glm::mat4 Camera::proj() {
  Window *wnd = Game::window;

  auto aspect = (float)(wnd->size().x) / (float)wnd->size().y;

  glm::mat4 projection = glm::perspective(fov, aspect, zNear, zFar);
  glm::mat4 view = Game::player->view();

  cameraMatrix = projection * view;
  
  return projection;
}

//void Camera::Matrix(Shader &shader, const char *uniform)
//{
//    glUniformMatrix4fv(glGetUniformLocation(shader.GetProgram(), uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
//}