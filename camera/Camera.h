//
// Created by junrui on 28/7/26.
//

#ifndef PEBBLEENGINE_CAMERA_H
#define PEBBLEENGINE_CAMERA_H
#include <glm/glm.hpp>

namespace engine
{
    class Camera
    {
    public:
        Camera(glm::vec3 pos, glm::vec3 view_vec, glm::vec3 up_vec, glm::vec3 right_vec);
        Camera(glm::vec3 pos, glm::vec3 view_vec);

        void Update();

        inline glm::mat4 GetViewMatrix() const { return view_matrix_; }

    private:
        glm::vec3 position_;
        glm::vec3 view_vec_;
        glm::vec3 up_vec_;
        glm::vec3 right_vec_;

        glm::mat4 view_matrix_;
    };
}

#endif //PEBBLEENGINE_CAMERA_H
