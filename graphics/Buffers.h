//
// Created by junrui on 20/7/26.
//

#ifndef PEBBLEENGINE_BUFFERS_H
#define PEBBLEENGINE_BUFFERS_H
#include "glad/glad.h"
#include "Shape.h"
#include <span>

namespace engine
{
    class VertexBuffer
    {
    public:
        VertexBuffer(std::span<const glm::vec3> vertices);
        VertexBuffer(std::span<const float> vertices);
        ~VertexBuffer();

        VertexBuffer(VertexBuffer&&) noexcept;
        VertexBuffer& operator=(VertexBuffer&&) noexcept;

        inline GLuint handle() const { return handle_; }

        VertexBuffer(VertexBuffer const&) = delete;
        VertexBuffer& operator=(VertexBuffer const&) = delete;
    private:
        GLuint handle_ = 0;
    };

    class ElementBuffer
    {
    public:
        ElementBuffer(std::span<const unsigned int> indices);
        ~ElementBuffer();

        ElementBuffer(ElementBuffer&&) noexcept;
        ElementBuffer& operator=(ElementBuffer&&) noexcept;

        ElementBuffer(ElementBuffer const&) = delete;
        ElementBuffer& operator=(ElementBuffer const&) = delete;

        inline GLuint handle() const { return handle_; }

    private:
        GLuint handle_     = 0;
    };
}

#endif //PEBBLEENGINE_BUFFERS_H
