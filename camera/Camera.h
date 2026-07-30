//
// Created by junrui on 28/7/26.
//

#ifndef PEBBLEENGINE_CAMERA_H
#define PEBBLEENGINE_CAMERA_H
#include <glm/glm.hpp>

namespace engine
{
    enum class CameraType : uint8_t
    {
        PERSPECTIVE,
        ORTHOGRAPHIC, // Not implemented yet
    };

    // Not implemented yet
    enum class CameraMode : uint8_t
    {
        FREE_LOOK,
        FIRST_PERSON,
    };

    struct CameraSettings
    {
        float      field_of_view;
        float      aspect_ratio;
        float      near_plane;
        float      far_plane;

        CameraType camera_type;
        CameraMode camera_mode;
    };

    class Camera
    {
    public:
        Camera(glm::vec3 pos, glm::vec3 view_vec, glm::vec3 up_vec, glm::vec3 right_vec);
        Camera(glm::vec3 pos, glm::vec3 view_vec, CameraSettings settings);

        void Update();

        inline glm::mat4 GetViewMatrix() const { return view_matrix_; }
        inline glm::mat4 GetProjectionMatrix() const { return projection_matrix_; }
        inline glm::mat4 GetViewProjectionMatrix() const { return projection_matrix_ * view_matrix_; }

    private:
        glm::vec3 position_;
        glm::vec3 view_vec_;
        glm::vec3 up_vec_;
        glm::vec3 right_vec_;
        glm::mat4 view_matrix_;
        glm::mat4 projection_matrix_;
        CameraSettings settings_;
        bool settings_has_changed;
    };
}

#endif //PEBBLEENGINE_CAMERA_H
