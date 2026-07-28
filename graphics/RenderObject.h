//
// Created by junrui on 27/7/26.
//

#ifndef PEBBLEENGINE_RENDEROBJECT_H
#define PEBBLEENGINE_RENDEROBJECT_H
#include "VertexArray.h"
#include "Buffers.h"

namespace engine
{
    class RenderObject
    {
    public:
        RenderObject();
        ~RenderObject();

    private:
        VertexArray   vao_;
        VertexBuffer  vbo_;
        ElementBuffer ebo_;
        size_t        indicies_count_;
    };
}


#endif //PEBBLEENGINE_RENDEROBJECT_H
