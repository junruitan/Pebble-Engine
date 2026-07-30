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


    Camera::Camera(glm::vec3 pos, glm::vec3 view_vec, CameraSettings settings)
        : position_(pos),
          view_vec_(glm::normalize(view_vec)),
          up_vec_(glm::normalize(glm::vec3(0.0f, 1.0f, 0.0f))),
          right_vec_(glm::normalize(glm::cross(up_vec_, view_vec_))),
          view_matrix_(glm::lookAt(position_, position_ + view_vec_, up_vec_)),
          projection_matrix_(glm::mat4(1.0f)),
          settings_(settings),
          settings_has_changed(true)
    {
        if (settings_.camera_type == CameraType::PERSPECTIVE)
        {
            projection_matrix_ = glm::perspective(settings_.field_of_view,
                                                        settings_.aspect_ratio,
                                                        settings_.near_plane,
                                                        settings_.far_plane);
        }
    }

    void Camera::Update()
    {
        // Does nothing for now
    }
}
