//
// Created by junrui on 20/7/26.
//

#ifndef PEBBLEENGINE_VERTEXARRAY_H
#define PEBBLEENGINE_VERTEXARRAY_H
#include "glad/glad.h"

namespace engine
{
#if 0
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        VertexArray(VertexArray&&) noexcept;
        VertexArray& operator=(VertexArray&&) noexcept;

        inline GLuint get_handle() const { return handle_; }

        VertexArray(const VertexArray&) = delete;
        VertexArray& operator=(const VertexArray&) = delete;
    private:
        GLuint handle_ = 0;
    };
#endif

}

#endif //PEBBLEENGINE_VERTEXARRAY_H
