//
// Created by User on 7/29/2026.
//

#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>

namespace engine
{
    Camera::Camera(glm::vec3 pos, glm::vec3 view_vec, glm::vec3 up_vec, glm::vec3 right_vec)
        : position_(pos),
          view_vec_(view_vec),
          up_vec_(up_vec),
          right_vec_(right_vec) { }

    Camera::Camera(glm::vec3 pos, glm::vec3 view_vec)
        : Camera(pos,
                 view_vec,
          glm::vec3(0.0f, 1.0f, 0.0f),
        glm::vec3(1.0f, 0.0f, 0.0f)) { }

    void Camera::Update()
    {
        view_matrix_ = glm::lookAt(position_, position_ + view_vec_, up_vec_);
    }
}
