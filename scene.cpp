/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** main
*/

#include "example.hpp"

Glep::Mesh generatePlane() {
    Glep::Mesh mesh;

    mesh.setVertices({
        Glep::Vertex(glm::vec3(-5.0f, 0.0f, -5.0f), glm::vec2(0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-5.0f, 0.0f, 5.0f), glm::vec2(0.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(5.0f, 0.0f, 5.0f), glm::vec2(1.0f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(5.0f, 0.0f, -5.0f), glm::vec2(1.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f))
    });
    mesh.setIndices({
        0, 1, 2,
        2, 3, 0
    });
    return mesh;
}

Glep::Mesh generatePyramid() {
    Glep::Mesh mesh;

    mesh.setVertices({
        Glep::Vertex(glm::vec3(0.0f, 1.0f, 0.0f), glm::vec2(0.5f, 1.0f), glm::vec3(0.0f, 1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-1.0f, -1.0f, 1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, 1.0f)),
        Glep::Vertex(glm::vec3(1.0f, -1.0f, 1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, -1.0f, 1.0f)),
        Glep::Vertex(glm::vec3(1.0f, -1.0f, -1.0f), glm::vec2(1.0f, 0.0f), glm::vec3(1.0f, -1.0f, -1.0f)),
        Glep::Vertex(glm::vec3(-1.0f, -1.0f, -1.0f), glm::vec2(0.0f, 0.0f), glm::vec3(-1.0f, -1.0f, -1.0f))
    });

    mesh.setIndices({
        0, 1, 2,
        0, 2, 3,
        0, 3, 4,
        0, 4, 1,
        1, 4, 3,
        1, 3, 2
    });
    return mesh;
}
