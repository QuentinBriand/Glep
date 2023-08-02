/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** window
*/

#ifndef WINDOW_HPP_
    #define WINDOW_HPP_

    #include <glm/glm.hpp>
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>

    #include <list>
    #include <memory>
    #include <thread>
    #include <optional>
    #include <iostream>
    #include <stdexcept>

    #include <Camera/Camera.hpp>
    #include <IDrawable.hpp>
    #include <LightHandler.hpp>
    #include <Input/MouseHandler.hpp>
    #include <Input/KeyboardHandler.hpp>
    #include <GraphicsPipeline/GraphicsPipeline.hpp>

namespace Glep
{
    void onNativeResizeCallback(GLFWwindow *window, int width, int height);
    class Window {
        public:
            static void initOpenGL();

            Window() = delete;
            Window(const Window &cpy) = delete;
            Window &operator=(const Window &src) = delete;
            Window(int width, int height, const char *title, GLFWmonitor *monitor = NULL, GLFWwindow *share = NULL);
            GLFWwindow *getNativeWindow(void) const {
                return _window;
            }

            ~Window();

            KeyboardHandler &getKeyboardHandler(void);
            MouseHandler &getMouseHandler(void);
            LightHandler &getLightHandler(void);
            Camera &getActiveCamera(void);

            glm::ivec4 &getViewport(void);
            void setViewport(const glm::ivec4 &viewport);

            bool shouldClose(void) const;
            void close(void);

            void clear(const glm::vec4 &c = glm::vec4(0.0f, 0.0f, 0.0f, 1.0f)) const;

            void pollEvents(void) const;
            void pollKeyboardEvents(void);

            void display(void);

            const double &getDeltaTime(void) const;
            int getFPS(void) const;
            void setFPSLimit(int limit);

            Camera createCamera(const float &fov, const float &nearPlane = 0.1f, const float &farPlane = 100.0f);
            void setActiveCamera(Camera &camera);

            void draw(const IDrawable &drawable, const GraphicsPipeline &pipeline) const;
        private:
            void setCallbacks(void);

            GLFWwindow *_window = NULL;
            std::optional<std::reference_wrapper<Camera>> _activeCamera;

            static bool _isInit;
            bool _shouldClose;
            double _lastFrameTime;
            double _deltaTime = 0.0f;

            int _frameRateLimit = 60;

            glm::ivec4 _viewport;
            KeyboardHandler _keyboardHandler;
            MouseHandler _mouseHandler;
            LightHandler _lightHandler;
    };
} // namespace GLep

#endif /* !WINDOW_HPP_ */
