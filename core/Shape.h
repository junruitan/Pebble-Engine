//
// Created by junrui on 17/7/26.
//

#ifndef PEBBLEENGINE_SHAPE_H
#define PEBBLEENGINE_SHAPE_H
#include <array>
#include <glm/glm.hpp>

namespace engine
{
     class Triangle
     {
     public:
          Triangle(glm::vec3 p0, glm::vec3 p1, glm::vec3 p2);
          [[nodiscard]] std::array<glm::vec3, 3> const& get_vertices() const { return vertices; }
     private:
          std::array<glm::vec3, 3> vertices{glm::vec3(0.0f), glm::vec3(0.0f), glm::vec3(0.0f)};
     };

}

#endif //PEBBLEENGINE_SHAPE_H
