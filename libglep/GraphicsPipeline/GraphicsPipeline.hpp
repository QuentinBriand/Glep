/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** GraphicsPipeline
*/

#ifndef GRAPHICSPIPELINE_HPP_
    #define GRAPHICSPIPELINE_HPP_

    #include <glm/glm.hpp>
    #include <glm/gtc/type_ptr.hpp>

    #include <filesystem>

    #include <GraphicsPipeline/Shader.hpp>

namespace Glep
{
    class GraphicsPipeline {
        public:
            GraphicsPipeline(Shader &vertexShader, Shader &fragmentShader);
            GraphicsPipeline(const GraphicsPipeline &cpy) = delete;
            GraphicsPipeline &operator=(const GraphicsPipeline &src) = delete;

            ~GraphicsPipeline();

            void use(void) const;
            void unuse(void) const;

            const GLint &getId(void) const { return _id; }

            void setUniform(const std::string &name, const int &value) const;
            void setUniform(const std::string &name, const float &value) const;
            void setUniform(const std::string &name, const glm::vec2 &value) const;
            void setUniform(const std::string &name, const glm::vec3 &value) const;
            void setUniform(const std::string &name, const glm::mat4 &value) const;
        protected:
        private:
            GLint _id;

            Shader &_vertexShader;
            Shader &_fragmentShader;
    };
} // namespace Glep

#endif /* !GRAPHICSPIPELINE_HPP_ */
