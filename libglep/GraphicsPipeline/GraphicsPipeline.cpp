/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** GraphicsPipeline
*/

#include <GraphicsPipeline/GraphicsPipeline.hpp>

namespace Glep
{
    GraphicsPipeline::GraphicsPipeline(Shader &vertexShader, Shader &fragmentShader)
        : _vertexShader(vertexShader), _fragmentShader(fragmentShader)
    {
        if (vertexShader.getType() != VERTEX_SHADER)
            throw std::runtime_error("Vertex shader is not a vertex shader");
        if (fragmentShader.getType() != FRAGMENT_SHADER)
            throw std::runtime_error("Fragment shader is not a fragment shader");
        const bool &vertexShaderCompiled = vertexShader.isCompiled();
        if (!vertexShaderCompiled || !fragmentShader.isCompiled()) {
            std::cerr << "WARNING: " << (vertexShaderCompiled ? "Fragment" : "Vertex") << " shader not compiled" << std::endl;
        }
        _id = glCreateProgram();
        if (!_id)
            throw std::runtime_error("Failed to create the graphics pipeline program");
        glAttachShader(_id, vertexShader.getId());
        glAttachShader(_id, fragmentShader.getId());
        glLinkProgram(_id);

        GLint isLinked = 0;
        glGetProgramiv(_id, GL_LINK_STATUS, (int *)&isLinked);
        if (isLinked == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(_id, GL_INFO_LOG_LENGTH, &maxLength);
            char infoLog[maxLength];
            glGetProgramInfoLog(_id, maxLength, &maxLength, &infoLog[0]);
            glDeleteProgram(_id);
            glDeleteShader(vertexShader.getId());
            glDeleteShader(fragmentShader.getId());
            throw std::runtime_error("Failed to link the graphics pipeline program: " + std::string(infoLog));
        }
        glDetachShader(_id, vertexShader.getId());
        glDetachShader(_id, fragmentShader.getId());
    }

    GraphicsPipeline::~GraphicsPipeline()
    {
        glDeleteProgram(_id);
        std::cout << "Graphics pipeline deleted" << std::endl;
    }

    void GraphicsPipeline::use(void) const
    {
        if (!_id)
            throw std::runtime_error("Graphics pipeline not initialized");
        glUseProgram(_id);
    }

    void GraphicsPipeline::unuse(void) const
    {
        glUseProgram(0);
    }

    void GraphicsPipeline::setUniform(const std::string &name, const int &value) const
    {
        GLint location = glGetUniformLocation(_id, name.c_str());
        if (location == -1)
            throw std::runtime_error("Uniform " + name + " not found");
        glUseProgram(_id);
        glUniform1i(location, value);
    }

    void GraphicsPipeline::setUniform(const std::string &name, const float &value) const
    {
        GLint location = glGetUniformLocation(_id, name.c_str());
        if (location == -1)
            throw std::runtime_error("Uniform " + name + " not found");
        glUseProgram(_id);
        glUniform1f(location, value);
    }

    void GraphicsPipeline::setUniform(const std::string &name, const glm::vec2 &value) const
    {
        GLint location = glGetUniformLocation(_id, name.c_str());
        if (location == -1)
            throw std::runtime_error("Uniform " + name + " not found");
        glUseProgram(_id);
        glUniform2f(location, value.x, value.y);
    }

    void GraphicsPipeline::setUniform(const std::string &name, const glm::vec3 &value) const
    {
        GLint location = glGetUniformLocation(_id, name.c_str());
        if (location == -1)
            throw std::runtime_error("Uniform " + name + " not found");
        glUseProgram(_id);
        glUniform3f(location, value.x, value.y, value.z);
    }

    void GraphicsPipeline::setUniform(const std::string &name, const glm::mat4 &value) const
    {
        GLint location = glGetUniformLocation(_id, name.c_str());
        if (location == -1)
            throw std::runtime_error("Uniform " + name + " not found");
        glUseProgram(_id);
        glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
    }

} // namespace Glep
