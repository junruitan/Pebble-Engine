//
// Created by junrui on 20/7/26.
//

#include "VertexArray.h"

#include "Shape.h"
#include "Buffers.h"

namespace engine
{
    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &handle_);
    }

    VertexArray::~VertexArray()
    {
        if (handle_ != 0)
        {
            glDeleteVertexArrays(1, &handle_);
        }
    }

    VertexArray::VertexArray(VertexArray&& other) noexcept : handle_{other.handle_}
    {
        other.handle_ = 0;
    }

    VertexArray& VertexArray::operator=(VertexArray&& other) noexcept
    {
        if (this != &other)
        {
            if (handle_ != 0)
            {
                glDeleteVertexArrays(1, &handle_);
            }

            handle_ = other.handle_;
            other.handle_ = 0;

        }

        return *this;
    }

}
