//
// Created by junrui on 5/7/26.
//

#include "Shader.h"
#include <fstream>
#include <string>
#include <stdexcept>

constexpr unsigned int buffer_size = 512;

namespace engine
{
    Shader::Shader(GLenum const type, std::string const& filepath) : type_(type)
    {
        // Create shader handle
        handle_ = glCreateShader(type);
        if (handle_ == 0)
        {
            throw std::runtime_error("Unable to create shader " + filepath);
        }

        // Read shader content
        std::ifstream ifs(filepath);

        if (!ifs.is_open())
        {
            glDeleteShader(handle_);
            throw std::runtime_error("Unable to open file " + filepath);
        }

        std::string shader_content, buffer;
        while (std::getline(ifs, buffer))
        {
            shader_content += buffer + '\n';
        }

        ifs.close();

        const char* shader_content_cstr = shader_content.c_str(); // Apparently c_str() returns an rvalue

        glShaderSource(handle_, 1, &shader_content_cstr, nullptr);
        glCompileShader(handle_);

        GLint compile_status = 0;
        GLchar info_log[buffer_size];

        // Check shader compilation status
        glGetShaderiv(handle_, GL_COMPILE_STATUS, &compile_status);

        if (!compile_status) {
            glGetShaderInfoLog(handle_, buffer_size, nullptr, info_log);
            glDeleteShader(handle_);
            throw std::runtime_error(static_cast<char*>(info_log));
        }
    }

    Shader::~Shader()
    {
        if (handle_ != 0)
        {
            glDeleteShader(handle_);
        }
    }

    Shader::Shader(Shader&& other) noexcept : type_(other.type_), handle_(other.handle_)
    {
        other.type_ = 0;
        other.handle_ = 0;
    }

    Shader& Shader::operator=(Shader&& other) noexcept
    {
        if (this != &other)
        {
            if (handle_ != 0)
            {
                glDeleteShader(handle_);
            }

            type_ = other.type_;
            handle_ = other.handle_;

            other.handle_ = 0;
            other.type_ = 0;
        }

        return *this;
    }

    std::string Shader::get_type_str() const
    {
        if (type_ == GL_VERTEX_SHADER)
        {
            return "Vertex Shader";
        }
        else if (type_ == GL_FRAGMENT_SHADER)
        {
            return "Fragment Shader";
        }

        return "";
    }
}

