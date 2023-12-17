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

glm::vec3 Camera::viewDir() {
    glm::mat4 viewMatrix = view();
    // Extract the view direction from the view matrix
    glm::vec3 viewDir = glm::mat3(glm::inverse(viewMatrix)) * glm::vec3(0.0f, 0.0f, -1.0f);
    return glm::normalize(viewDir);
}

//void Camera::Matrix(Shader &shader, const char *uniform)
//{
//    glUniformMatrix4fv(glGetUniformLocation(shader.GetProgram(), uniform), 1, GL_FALSE, glm::value_ptr(cameraMatrix));
//}