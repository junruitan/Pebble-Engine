//
// Created by junrui on 27/7/26.
//

#ifndef PEBBLEENGINE_RENDEROBJECT_H
#define PEBBLEENGINE_RENDEROBJECT_H
#include "VertexArray.h"
#include "Vertex.h"
#include "Buffers.h"
#include <span>

namespace engine
{
    class RenderObject
    {
    public:
        RenderObject(VertexData const& vtx_data, std::span<const unsigned int> indicies);

        inline GLuint GetVaoHandle() const { return vao_.GetHandle(); }
        inline size_t GetIndiciesCount() const { return indicies_count_; }

    private:
        VertexArray   vao_;
        VertexBuffer  vbo_;
        ElementBuffer ebo_;
        size_t        indicies_count_;
    };
}

#endif //PEBBLEENGINE_RENDEROBJECT_H
