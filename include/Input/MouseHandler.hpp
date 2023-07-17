/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** MouseHandler
*/

#ifndef MOUSEHANDLER_HPP_
    #define MOUSEHANDLER_HPP_

    #include <vector>
    #include <iostream>
    #include <optional>
    #include <functional>
    #include <glm/glm.hpp>
    #include <GLFW/glfw3.h>

namespace Glep
{
    using MMCallbackFunction = std::function<void(const glm::vec2 &)>;
    class Window;
    enum CursorMode {
        NORMAL = GLFW_CURSOR_NORMAL,
        HIDDEN = GLFW_CURSOR_HIDDEN,
        DISABLED = GLFW_CURSOR_DISABLED
    };

    enum MouseClick {
        LEFT = GLFW_MOUSE_BUTTON_LEFT,
        RIGHT = GLFW_MOUSE_BUTTON_RIGHT,
        MIDDLE = GLFW_MOUSE_BUTTON_MIDDLE,
        BUTTON4 = GLFW_MOUSE_BUTTON_4,
        BUTTON5 = GLFW_MOUSE_BUTTON_5,
        BUTTON6 = GLFW_MOUSE_BUTTON_6,
        BUTTON7 = GLFW_MOUSE_BUTTON_7,
        BUTTON8 = GLFW_MOUSE_BUTTON_8,
        NB_BUTTONS = BUTTON8 + 1,
    };

    enum MouseClickType {
        MOUSE_PRESS = GLFW_PRESS,
        MOUSE_RELEASE = GLFW_RELEASE,
        MOUSE_REPEAT = GLFW_REPEAT,
        MOUSE_TYPE_LAST = MOUSE_REPEAT + 1
    };

    class MouseHandler {
        public:
            MouseHandler();
            ~MouseHandler() = default;

            const bool &canUseRawMotion(void) const;
            const bool &isUsingRawMotion(void) const;
            void setRawMotionUse(const bool &rawInput);

            const CursorMode &getCursorMode(void) const;
            void setCursorMode(const CursorMode &mode);

            void update(void);

            // IS NOT TO BE CALLED BY THE USER
            void updateMousePos(const double &x, const double &y);
            void updateMouseEnter(const bool &entered);
            void updateMouseClick(const int &button, const int &type, const int &mods);
            void updateMouseScroll(const double &x, const double &y);


            void setMouseScrollCallback(const std::function<void(const double&, const double&)> &callback);
            void removeMouseScrollCallback(void);

            const glm::vec2 &getLastMousePos(void) const;
            void setMouseMovedCallback(const MMCallbackFunction& callback);
            void removeMouseMovedCallback(void);

            void setMouseEnterCallback(const std::function<void()> &callback);
            void removeMouseEnterCallback(void);

            void setMouseLeaveCallback(const std::function<void()> &callback);
            void removeMouseLeaveCallback(void);

            void setMouseClickCallback(const MouseClick &button, const MouseClickType &type, const std::function<void()> &callback);
            void removeMouseClickCallback(const MouseClick &button, const MouseClickType &type);

            const bool &isMouseEntered(void) const {
                return _mouseIn;
            }

            const int &getLastMouseModifiers(void) const {
                return _lastMouseModifiers;
            }
        private:
            bool _rawInput = false;
            bool _canUseRawInput = glfwRawMouseMotionSupported();
            bool _mouseIn = true;
            int _lastMouseModifiers = 0;

            std::optional<std::function<void(const double&, const double&)>> _mouseScrollCallback = std::nullopt;
            std::optional<MMCallbackFunction> _mouseMovedCallback = std::nullopt;

            std::optional<std::function<void()>> _mouseClickEvents[MOUSE_TYPE_LAST][NB_BUTTONS];

            std::optional<std::function<void()>> _mouseEnterCallback = std::nullopt;
            std::optional<std::function<void()>> _mouseLeaveCallback = std::nullopt;


            CursorMode _cursorMode = NORMAL;
            glm::vec2 _lastMousePos;

            friend Window;
    };
} // namespace Glep

#endif /* !MOUSEHANDLER_HPP_ */
