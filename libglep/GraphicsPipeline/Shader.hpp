/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Shader
*/

#ifndef SHADER_HPP_
    #define SHADER_HPP_

    #include <glad/glad.h>

    #include <vector>
    #include <fstream>
    #include <cstring>
    #include <iostream>

namespace Glep
{
    enum ShaderType {
        VERTEX_SHADER,
        FRAGMENT_SHADER,
        GEOMETRY_SHADER
    };

    class Shader {
        public:
            ~Shader();

            static Shader loadFromFile(const char *path, const ShaderType &type);
            static Shader loadFromMemory(const char *sourceCode, const ShaderType &type);
            void compile(void);

            const ShaderType &getType(void) const { return _type; }
            const unsigned int &getId(void) const { return _id; }
            const bool &isCompiled(void) const { return _compiled; }
            const std::string &getPath(void) const { return _path; }
        protected:
            Shader() = default;
        private:
            std::string &getSourceCode();
            std::string _path = "";

            unsigned int _id;
            bool _compiled = false;
            ShaderType _type;
            char *_sourceCode = nullptr;
    };
} // namespace Glep

#endif /* !SHADER_HPP_ */
