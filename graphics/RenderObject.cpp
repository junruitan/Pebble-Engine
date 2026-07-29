//
// Created by User on 7/29/2026.
//

#include "RenderObject.h"

namespace engine
{
    RenderObject::RenderObject(VertexData const& vtx_data, std::span<const unsigned int> indicies)
        : vbo_(vtx_data.position),
          ebo_(indicies),
          indicies_count_(indicies.size())
    {
        vao_.BindHandle();

    }
}