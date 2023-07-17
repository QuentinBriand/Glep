/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** main
*/

#include "Window/Window.hpp"
#include "GraphicsPipeline/GraphicsPipeline.hpp"
#include "Mesh/Mesh.hpp"

#include <chrono>
#include <thread>

Glep::GraphicsPipeline test(void) {
    auto vertexShader = Glep::Shader::loadFromFile("examples/shaders/default.vert", Glep::VERTEX_SHADER);
    vertexShader.compile();
    auto fragmentShader = Glep::Shader::loadFromFile("examples/shaders/default.frag", Glep::FRAGMENT_SHADER);
    fragmentShader.compile();
    return Glep::GraphicsPipeline (vertexShader, fragmentShader);
}

Glep::Mesh cubeMeshGen()
{
    auto cubeMesh = Glep::Mesh();
    cubeMesh.setVertices({
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec2(1.0f, 1.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec2(1.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec2(0.0f, 0.0f)),
        Glep::Vertex(glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec2(0.0f, 1.0f))
    });
    cubeMesh.setIndices({
        0, 1, 2,
        3, 4, 5,
        6, 7, 8,
        9, 10, 11,
        12, 13, 14,
        15, 16, 17,
        18, 19, 20,
        21, 22, 23,
        24, 25, 26,
        27, 28, 29,
        30, 31, 32,
        33, 34, 35
    });
    return cubeMesh;
}

void setCallbacks(Glep::Window& window, Glep::Camera& camera) {
    window.getKeyboardHandler().setKeyPressedCallback(GLFW_KEY_ESCAPE, [&window]() {
        window.close();
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_W, [&camera]() {
        camera.localTranslate(glm::vec3(0.0f, 0.0f, 0.1f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_S, [&camera]() {
        camera.localTranslate(glm::vec3(0.0f, 0.0f, -0.1f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_D, [&camera]() {
        camera.localTranslate(glm::vec3(-0.1f, 0.0f, 0.0f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_A, [&camera]() {
        camera.localTranslate(glm::vec3(0.1f, 0.0f, 0.0f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_SPACE, [&camera]() {
        camera.localTranslate(glm::vec3(0.0f, -0.1f, 0.0f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_LEFT_SHIFT, [&camera]() {
        camera.localTranslate(glm::vec3(0.0f, 0.1f, 0.0f));
    });

    window.getMouseHandler().setMouseMovedCallback([&camera, &window](const glm::vec2 &pos) {
        static float mouseX = 0.0f;
        static float mouseY = 0.0f;
        float sensitivity = 5.0f;
        mouseX = pos.x * sensitivity * (float)window.getDeltaTime();
        mouseY = pos.y * sensitivity * (float)window.getDeltaTime();
        mouseY = glm::clamp(mouseY, -89.0f, 89.0f);
        camera.rotate(glm::vec3(mouseY, mouseX, 0.0f));
    });
}


int main(void)
{
    Glep::Window::initOpenGL();

    Glep::Window window = Glep::Window(800, 600, "Glep");
    window.setFPSLimit(160);
    window.getMouseHandler().setRawMotionUse(true);
    window.getMouseHandler().setCursorMode(Glep::CursorMode::DISABLED);

    auto camera = window.createCamera(45.0f);
    window.setActiveCamera(camera);
    setCallbacks(window, camera);

    auto texture = Glep::Texture::loadFromFile("assets/rickroll.jpg", Glep::TextureRepetition::REPEAT);

    auto graphicsPipeline = test();
    auto cubeMesh = cubeMeshGen();
    cubeMesh.setTexture(texture);
    cubeMesh.setLocalPosition(glm::vec3(0.0f, 0.0f, -3.0f));


    while(!window.shouldClose())
    {
        window.pollEvents();
        window.pollKeyboardEvents();
        window.clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        window.draw(cubeMesh, graphicsPipeline);

        window.display();
    }
    return 0;
}
