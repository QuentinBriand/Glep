/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Vertex
*/

#include <Model/Vertex.hpp>

namespace Glep
{
    Vertex::Vertex(const glm::vec3 &_position, const glm::vec2 &_uv, const glm::vec3 &_normal, const glm::vec3 &_color)
    {
        position = _position;
        uv = _uv;
        normal = _normal;
        color = _color;
    }
} // namespace Glep
