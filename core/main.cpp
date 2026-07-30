#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "../graphics/ShaderProgram.h"
#include "../graphics/RenderObject.h"
#include "../math/Transform.h"
#include "../camera/Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

int main()
{
    /* Initialize the library */
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Pebble Engine", nullptr, nullptr);

    /* Create a windowed mode window and its OpenGL context */
    if (!window)
    {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) // THEN load
    {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
        return -1;
    }

    engine::Shader vertex_shader(GL_VERTEX_SHADER,"../shaders/base.vert");
    engine::Shader fragment_shader(GL_FRAGMENT_SHADER,"../shaders/base.frag");
    engine::ShaderProgram shader_program(std::move(vertex_shader),std::move(fragment_shader));

    engine::VertexData data;

    data.position =
    {
        // +X face
		{+0.5f,-0.5f,-0.5f}, {+0.5f,-0.5f,+0.5f}, {+0.5f,+0.5f,+0.5f}, {+0.5f,+0.5f,-0.5f},
        // -X face
        {-0.5f,-0.5f,+0.5f}, {-0.5f,-0.5f,-0.5f}, {-0.5f,+0.5f,-0.5f}, {-0.5f,+0.5f,+0.5f},
        // +Y face
        {-0.5f,+0.5f,-0.5f}, {+0.5f,+0.5f,-0.5f}, {+0.5f,+0.5f,+0.5f}, {-0.5f,+0.5f,+0.5f},
        // -Y face
        {-0.5f,-0.5f,+0.5f}, {+0.5f,-0.5f,+0.5f}, {+0.5f,-0.5f,-0.5f}, {-0.5f,-0.5f,-0.5f},
        // +Z face
        {+0.5f,-0.5f,+0.5f}, {-0.5f,-0.5f,+0.5f}, {-0.5f,+0.5f,+0.5f}, {+0.5f,+0.5f,+0.5f},
        // -Z face
        {-0.5f,-0.5f,-0.5f}, {+0.5f,-0.5f,-0.5f}, {+0.5f,+0.5f,-0.5f}, {-0.5f,+0.5f,-0.5f}

    };

    std::vector<unsigned int> indices =
    {
        // +X face
        0, 2, 1,  0, 3, 2,
        // -X face
        4, 6, 5,  4, 7, 6,
        // +Y face
        8, 10, 9,  8, 11, 10,
        // -Y face
        12, 14, 13,  12, 15, 14,
        // +Z face
        16, 18, 17,  16, 19, 18,
        // -Z face
        20, 22, 21,  20, 23, 22,
    };

    engine::RenderObject object(data, indices);
    engine::Transform    transform;

    transform.scale = glm::vec3(1.0f, 1.0f, 1.0f);
    transform.translation = glm::vec3(0.0f, 0.0f, 0.0f);
    transform.rotation = glm::vec3(1.0f, 0.0f, 0.0f);

    glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(1.0f, 1.0f, 1.0f));
    glm::mat4 translation = glm::translate(glm::mat4(1.0f), transform.translation);
    glm::mat4 rotation = glm::rotate(glm::mat4(1.0f), 45.0f, transform.rotation);

    transform.model_to_world = translation * rotation * scale;

    glm::vec3 cam_pos = glm::vec3(2.0f, 0.0f, 15.0f);
    glm::vec3 cam_view = glm::normalize(glm::vec3(0.f, 0.0f, 0.0f) - cam_pos);

    engine::CameraSettings camera_settings =
    {
        .field_of_view = 45.0f,
        .aspect_ratio = 640.0f/480.0f,
        .near_plane = 0.1f,
        .far_plane = 1000.0f,
    };

    engine::Camera cam(cam_pos, cam_view, camera_settings);
    glm::mat4 p = glm::perspective(glm::radians(45.0f), 640.0f / 480.0f, 0.1f, 100.0f);
    glm::mat4 mvp = p * cam.GetViewMatrix() * transform.model_to_world;

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        // glViewport(0, 0, 640, 480);
        GLuint uniform_location = glGetUniformLocation(shader_program.GetHandle(), "uMVP");
        shader_program.Use();
        if (uniform_location >= 0)
        {
           glUniformMatrix4fv(uniform_location, 1, GL_FALSE, glm::value_ptr(mvp));
        }
        glBindVertexArray(object.GetVaoHandle());
        //glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawElements(GL_TRIANGLES, object.GetIndiciesCount(), GL_UNSIGNED_INT, 0);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
