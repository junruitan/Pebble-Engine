//
// Created by junrui on 20/7/26.
//

#ifndef PEBBLEENGINE_VERTEXARRAY_H
#define PEBBLEENGINE_VERTEXARRAY_H
#include "glad/glad.h"

namespace engine
{

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

        inline void bind() { glBindVertexArray(handle_); }
        inline void unbind() { glBindVertexArray(0); }

    private:
        GLuint handle_ = 0;
    };


}

#endif //PEBBLEENGINE_VERTEXARRAY_H
