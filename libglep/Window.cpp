/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** window
*/

#include "Window.hpp"

namespace Glep
{
    bool Window::_isInit = false;
    void Window::initOpenGL()
    {
        if (_isInit)
            return;
        if (!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(
            GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE
        );
        _isInit = true;
    }

    Window::Window(int width, int height, const char *title, GLFWmonitor *monitor, GLFWwindow *share) : _shouldClose(false)
    {
        if (!_isInit)
            throw std::runtime_error("Glep::Window::initGlfw() must be called before creating a window");
        _window = glfwCreateWindow(width, height, title, monitor, share);
        if (!_window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }
        glfwMakeContextCurrent(_window);

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            throw std::runtime_error("Failed to initialize GLAD");
        }
        _viewport = glm::ivec4(0, 0, width, height);
        glfwSetErrorCallback([](int error, const char *description) {
            std::cerr << "Internal GLFW Error " << error << ": " << description << std::endl;
        });
        glViewport(_viewport.x, _viewport.y, _viewport.z, _viewport.w);
        glfwSetWindowUserPointer(_window, this);
        setCallbacks();
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);
        glfwSetInputMode(glfwGetCurrentContext(), GLFW_STICKY_KEYS, 1);
        glfwSwapInterval(0);
        glEnable(GL_DEPTH_TEST);
    }

    Window::~Window() {
        glfwDestroyWindow(_window);
    }

    void Window::setCallbacks(void) {
        glfwSetFramebufferSizeCallback(_window, [](GLFWwindow *window, int width, int height) {
            Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
            w->setViewport(glm::ivec4(0, 0, width, height));
        });
        glfwSetCursorPosCallback(_window, [](GLFWwindow *window, double xpos, double ypos) {
            Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
            w->getMouseHandler().updateMousePos(xpos, ypos);
        });
        glfwSetCursorEnterCallback(_window, [](GLFWwindow *window, int entered) {
            Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
            w->getMouseHandler().updateMouseEnter(entered);
        });
        glfwSetMouseButtonCallback(_window, [](GLFWwindow *window, int button, int action, int mods) {
            Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
            w->getMouseHandler().updateMouseClick(button, action, mods);
        });
        glfwSetScrollCallback(_window, [](GLFWwindow *window, double xoffset, double yoffset) {
            Window *w = static_cast<Window *>(glfwGetWindowUserPointer(window));
            w->getMouseHandler().updateMouseScroll(xoffset, yoffset);
        });
    }

    void Window::setViewport(const glm::ivec4 &viewport)
    {
        _viewport = viewport;
        glViewport(_viewport.x, _viewport.y, _viewport.z, _viewport.w);
    }

    glm::ivec4 &Window::getViewport(void) {
        return _viewport;
    }

    bool Window::shouldClose(void) const
    {
        return glfwWindowShouldClose(_window) || _shouldClose;
    }

    void Window::pollEvents(void) const
    {
        glfwPollEvents();
    }

    void Window::pollKeyboardEvents(void)
    {
        _keyboardHandler.update();
    }

    KeyboardHandler &Window::getKeyboardHandler(void)
    {
        return _keyboardHandler;
    }

    MouseHandler &Window::getMouseHandler(void)
    {
        return _mouseHandler;
    }

    Camera &Window::getActiveCamera(void)
    {
        if (!_activeCamera.has_value())
            throw std::runtime_error("No active camera");
        return _activeCamera.value();
    }

    void Window::close(void)
    {
        _shouldClose = true;
    }

    void Window::display(void)
    {
        static auto lastTime = std::chrono::high_resolution_clock::now();
        glfwSwapBuffers(_window);
        auto currentTime = std::chrono::high_resolution_clock::now();
        auto usSpent = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - lastTime);
        if (_frameRateLimit > 0) {
            auto usPerFrame = std::chrono::microseconds(1000000 / _frameRateLimit);
            if (usSpent < usPerFrame) {
                std::this_thread::sleep_for(usPerFrame - usSpent);
                currentTime = std::chrono::high_resolution_clock::now();
            }
        }
        _deltaTime = std::chrono::duration_cast<std::chrono::duration<double>>(currentTime - lastTime).count();
        lastTime = currentTime;
    }

    void Window::clear(const glm::vec4 &c) const
    {
        glClearColor(c.r, c.g, c.b, c.a);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    int Window::getFPS(void) const
    {
        return 1 / _deltaTime;
    }

    void Window::draw(const IDrawable &drawable, const GraphicsPipeline &pipeline) const
    {
        GLint currentProgram;
        glGetIntegerv(GL_CURRENT_PROGRAM, &currentProgram);
        if (currentProgram != pipeline.getId())
            pipeline.use();
        auto &cam = _activeCamera.value().get();
        pipeline.setUniform("view", cam.getTransformationMatrix());
        pipeline.setUniform("projection", cam.getProjectionMatrix());
        drawable.draw(pipeline);
    }

    const double &Window::getDeltaTime(void) const
    {
        return _deltaTime;
    }

    void Window::setFPSLimit(int limit)
    {
        _frameRateLimit = limit;
    }
} // namespace Glep
