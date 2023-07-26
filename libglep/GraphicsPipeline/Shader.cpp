/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Shader
*/

#include <GraphicsPipeline/Shader.hpp>

namespace Glep
{
    Shader::~Shader()
    {
        if (_sourceCode)
            delete[] _sourceCode;
        if (_id)
            glDeleteShader(_id);
        std::cout << "Shader deleted" << std::endl;
    }

    Shader Shader::loadFromFile(const char *path, const ShaderType &type)
    {
        char *fileContent = NULL;
        int count = 0;
        FILE *fp = fopen(path,"rt");
        if (!fp)
            throw std::runtime_error("Failed to open shader file: " + std::string(path));
        fseek(fp, 0, SEEK_END);
        count = ftell(fp);
        rewind(fp);
        if (count > 0) {
            fileContent = (char *)malloc(sizeof(char) * (count+1));
            count = fread(fileContent,sizeof(char),count,fp);
            fileContent[count] = '\0';
        }
        fclose(fp);
        auto shader = loadFromMemory(fileContent, type);
        shader._path = path;
        return shader;
    }

    void Shader::compile(void)
    {
        glShaderSource(_id, 1, &_sourceCode, NULL);
        glCompileShader(_id);
        int success;
        glGetShaderiv(_id, GL_COMPILE_STATUS, &success);
        if (success == GL_FALSE) {
            GLint maxLength = 0;
            glGetShaderiv(_id, GL_INFO_LOG_LENGTH, &maxLength);
	        char infoLog[maxLength];
            glGetShaderInfoLog(_id, maxLength, &maxLength, &infoLog[0]);
            glDeleteShader(_id);
            std::cerr << "Shader compile error:" << infoLog;
            throw std::runtime_error("Failed to compile shader");
        } else {
            _compiled = true;
        }
    }

    Shader Shader::loadFromMemory(const char *sourceCode, const ShaderType &type)
    {
        Shader shader;
        if (sourceCode)
            delete[] shader._sourceCode;

        shader._sourceCode = new char[strlen(sourceCode) + 1];
        bzero(shader._sourceCode, strlen(sourceCode) + 1);
        strcpy(shader._sourceCode, sourceCode);
        auto glShaderType =
            type == VERTEX_SHADER ? GL_VERTEX_SHADER :
            type == FRAGMENT_SHADER ? GL_FRAGMENT_SHADER :
            GL_GEOMETRY_SHADER;
        shader._id = glCreateShader(glShaderType);
        shader._type = type;
        if (!shader._id)
            throw std::runtime_error("Failed to create shader");
        return shader;
    }
} // namespace Glep
