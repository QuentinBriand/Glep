/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Vertex
*/

#ifndef VERTEX_HPP_
    #define VERTEX_HPP_

    #include <glm/glm.hpp>

namespace Glep {
    class Vertex {
        public:
            Vertex(const glm::vec3 &position, const glm::vec3 &normal = glm::vec3(0.0f, 1.0f, 0.0f), const glm::vec2 &uv = glm::vec2(0.0f, 0.0f), const glm::vec3 &color = glm::vec3(1.0f, 1.0f, 1.0f));
            Vertex(const Vertex &cpy) = default;
            Vertex &operator=(const Vertex &src) = default;
            ~Vertex() = default;

            glm::vec3 position;
            glm::vec2 uv;
            glm::vec3 normal;
            glm::vec3 color;
    };
} // namespace Glep

#endif /* !VERTEX_HPP_ */
