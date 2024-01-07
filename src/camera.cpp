#include "camera.hpp"
#include "glm/ext.hpp"
#include "game.hpp"

Camera::Camera() 
{
    //Initalize the projection matrix
    float aspectRatio = (float)(Game::window->size().x) / (float)Game::window->size().y;
    m_projection = glm::perspective(m_flFov, aspectRatio, m_flzNear, m_flzFar);
}

Camera::~Camera() {}

void Camera::Resize(float width, float height)
{
    float newAspectRatio = width / height;
    m_projection = glm::perspective(m_flFov, newAspectRatio * m_flFov, m_flzNear, m_flzFar);
}


glm::mat4 Camera::proj() {

    glm::mat4 projection = m_projection;
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