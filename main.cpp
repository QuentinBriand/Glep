/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** main
*/

#include "example.hpp"

#include <chrono>
#include <thread>

Glep::GraphicsPipeline test(void) {
    auto vertexShader = Glep::Shader::loadFromFile("examples/shaders/default.vert", Glep::VERTEX_SHADER);
    vertexShader.compile();
    auto fragmentShader = Glep::Shader::loadFromFile("examples/shaders/default.frag", Glep::FRAGMENT_SHADER);
    fragmentShader.compile();
    return Glep::GraphicsPipeline (vertexShader, fragmentShader);
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

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_LEFT_SHIFT, [&camera]() {
        camera.globalTranslate(glm::vec3(0.0f, -0.1f, 0.0f));
    });

    window.getKeyboardHandler().setKeyRepeatCallback(GLFW_KEY_SPACE, [&camera]() {
        camera.globalTranslate(glm::vec3(0.0f, 0.1f, 0.0f));
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
    // camera.globalTranslate(glm::vec3(0.0f, -2.0f, -7.5f));
    setCallbacks(window, camera);

    auto texture = Glep::Texture::loadFromFile("assets/rickroll.jpg", Glep::TextureRepetition::MIRRORED_REPEAT);

    auto graphicsPipeline = test();
    auto plane = generatePlane();
    auto pyramid = generatePyramid();
    pyramid.setTexture(texture);
    plane.setTexture(texture);
    pyramid.localTranslate(glm::vec3(0.0f, 1.0001f, 0.0f));

    while(!window.shouldClose())
    {
        window.pollEvents();
        window.pollKeyboardEvents();
        window.clear(glm::vec4(0.2f, 0.3f, 0.3f, 1.0f));

        pyramid.globalTranslate(glm::vec3(0.0f, 0.001f, 0.0f));

        window.draw(plane, graphicsPipeline);
        window.draw(pyramid, graphicsPipeline);

        window.display();
    }
    return 0;
}
