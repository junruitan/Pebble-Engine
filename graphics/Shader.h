//
// Created by junrui on 5/7/26.
//
#ifndef PEBBLEENGINE_SHADER_H
#define PEBBLEENGINE_SHADER_H
#include <glad/glad.h>
#include <string>

namespace engine
{
    class Shader
    {
    private:
        GLenum type_ = 0;
        GLuint handle_   = 0;

    public:
        Shader(GLenum const type, std::string const& filepath);
        ~Shader();

        Shader(Shader&& other) noexcept;
        Shader& operator=(Shader&& other) noexcept;

        std::string GetTypeStr() const;

        inline GLenum GetType() const { return type_; };
        inline GLuint GetHandle() const { return handle_; };

        Shader(const Shader& shader) = delete;
        Shader& operator=(const Shader& shader) = delete;
    };
}

#endif //PEBBLEENGINE_SHADER_H
