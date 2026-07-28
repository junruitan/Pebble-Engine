//
// Created by User on 7/29/2026.
//

#ifndef PEBBLEENGINE_TRANSFORM_H
#define PEBBLEENGINE_TRANSFORM_H

namespace engine
{
    struct Transform
    {
        glm::vec3  scale;
        glm::vec3  rotation;
        glm::vec3  translation;

        glm::mat4  model_to_world;
    };
}

#endif //PEBBLEENGINE_TRANSFORM_H
