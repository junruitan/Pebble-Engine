//
// Created by junrui on 5/7/26.
//

#include "ShaderProgram.h"

constexpr unsigned int buffer_size = 512;

namespace engine
{
    ShaderProgram::ShaderProgram(Shader&& vertex_shader, Shader&& fragment_shader)
    {
        handle_ = glCreateProgram();

        if (handle_ == 0)
        {
            throw std::runtime_error("Unable to create a new shader program");
        }

        glAttachShader(handle_, vertex_shader.get_handle());
        glAttachShader(handle_, fragment_shader.get_handle());
        glLinkProgram(handle_);

        GLint link_status = 0;
        GLchar info_log[buffer_size];

        glGetProgramiv(handle_, GL_LINK_STATUS, &link_status);
        if (!link_status)
        {
            glGetProgramInfoLog(handle_, buffer_size, nullptr, info_log);
            glDeleteProgram(handle_);
            throw std::runtime_error(static_cast<char*>(info_log));
        }
    }

    ShaderProgram::~ShaderProgram()
    {
        if (handle_ != 0)
        {
            glDeleteProgram(handle_);
        }
    }

    ShaderProgram::ShaderProgram(ShaderProgram&& other) noexcept : handle_{other.handle_} { other.handle_ = 0; }

    ShaderProgram& ShaderProgram::operator=(ShaderProgram&& other) noexcept
    {
        if (this != &other)
        {
            if (handle_ != 0)
            {
                glDeleteProgram(handle_);
            }

            handle_ = other.handle_;
            other.handle_ = 0;
        }

        return *this;
    }
}

