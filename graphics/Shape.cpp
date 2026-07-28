//
// Created by junrui on 20/7/26.
//

#include "Shape.h"

namespace engine
{
    Triangle::Triangle(glm::vec3 p0, glm::vec3 p1, glm::vec3 p2)
    {
        vertices[0] = p0;
        vertices[1] = p1;
        vertices[2] = p2;
    }
}