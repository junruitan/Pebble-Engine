//
// Created by junrui on 5/7/26.
//
#ifndef PEBBLEENGINE_SHADERPROGRAM_H
#define PEBBLEENGINE_SHADERPROGRAM_H
#include "Shader.h"

namespace engine
{
    class ShaderProgram
    {
    private:
        GLuint    handle_ = 0;

    public:
        ShaderProgram(Shader&& vertex_shader, Shader&& fragment_shader);
        ~ShaderProgram();

        ShaderProgram(ShaderProgram&&) noexcept;
        ShaderProgram& operator=(ShaderProgram&&) noexcept;

        inline void Use() { glUseProgram(handle_); }
        inline GLuint GetHandle() const { return handle_; }

        // Disable copy
        ShaderProgram(const ShaderProgram&) = delete;
        ShaderProgram& operator=(const ShaderProgram&) = delete;
    };
}

#endif //PEBBLEENGINE_SHADERPROGRAM_H
