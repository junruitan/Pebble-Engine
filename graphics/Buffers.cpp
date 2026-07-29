//
// Created by junrui on 20/7/26.
//

#include "Buffers.h"

namespace engine
{
    VertexBuffer::VertexBuffer(std::span<const glm::vec3> vertices)
    {
        glGenBuffers(1, &handle_);

        glBindBuffer(GL_ARRAY_BUFFER, handle_);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);
    }

    VertexBuffer::VertexBuffer(std::span<const float> vertices)
    {
        glGenBuffers(1, &handle_);

        // add error handling here

        glBindBuffer(GL_ARRAY_BUFFER, handle_);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer()
    {
        if (handle_ != 0)
        {
            glDeleteBuffers(1, &handle_);
        }
    }

    VertexBuffer::VertexBuffer(VertexBuffer&& other) noexcept : handle_(other.handle_) { other.handle_ = 0; }

    VertexBuffer& VertexBuffer::operator=(VertexBuffer&& other) noexcept
    {
        // Make sure not copying to itself
        if (this != &other)
        {
            // Check if valid handle
            if (handle_ != 0)
            {
                // Delete current existing buffer
                glDeleteBuffers(1, &handle_);
            }

            // "Steal" other buffer's handle
            handle_ = other.handle_;

            // Set the other buffer's handle to 0
            other.handle_ = 0;
        }

        return *this;
    }

    ElementBuffer::ElementBuffer(std::span<const unsigned int> indices)
    {
        glGenBuffers(1, &handle_);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, handle_);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    }

    ElementBuffer::~ElementBuffer()
    {
        if (handle_ != 0)
        {
            glDeleteBuffers(1, &handle_);
        }
    }

    ElementBuffer::ElementBuffer(ElementBuffer&& other) noexcept : handle_(other.handle_) { other.handle_ = 0; }

    ElementBuffer& ElementBuffer::operator=(ElementBuffer&& other) noexcept
    {
        if (this != &other)
        {
            // Delete this current resource
            if (handle_ != 0)
            {
                glDeleteBuffers(1, &handle_);
            }

            handle_ = other.handle_;
            other.handle_ = 0;
        }

        return *this;
    }

}
