//
// Created by junrui on 9/7/26.
//

#ifndef PEBBLEENGINE_VERTEX_H
#define PEBBLEENGINE_VERTEX_H
#include <glm/glm.hpp>

struct VertexData
{
    std::vector<glm::vec3> position;
    std::vector<glm::vec3> normal;
    std::vector<glm::vec3> tangent;
    std::vector<glm::vec2> uv;
};

#endif //PEBBLEENGINE_VERTEX_H
