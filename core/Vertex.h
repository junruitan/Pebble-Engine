//
// Created by junrui on 9/7/26.
//

#ifndef PEBBLEENGINE_VERTEX_H
#define PEBBLEENGINE_VERTEX_H
#include <glm/glm.hpp>

struct Vertex
{
    glm::vec3 position;
    glm::vec3 color;
    glm::vec3 normal;
    glm::vec2 tex_coords;
};

#endif //PEBBLEENGINE_VERTEX_H
