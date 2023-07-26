/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** KeyboardHandler
*/

#ifndef KEYBOARDHANDLER_HPP_
    #define KEYBOARDHANDLER_HPP_

    #include <glad/glad.h>
    #include <GLFW/glfw3.h>

    #include <iostream>
    #include <optional>
    #include <functional>
    #include <unordered_map>

namespace Glep {
    class KeyboardHandler {
        public:
            KeyboardHandler();
            ~KeyboardHandler();

            void update();
            void setKeyPressedCallback(int key, std::function<void()> callback);
            void setKeyReleasedCallback(int key, std::function<void()> callback);
            void setKeyRepeatCallback(int key, std::function<void()> callback);

            void removeKeyPressedCallback(int key);
            void removeKeyReleasedCallback(int key);
            void removeKeyRepeatCallback(int key);

            bool isKeyPressed(int key) const;
            bool isKeyReleased(int key) const;
            bool isKeyRepeat(int key) const;
        protected:
        private:
            GLint _keys[GLFW_KEY_LAST];

            std::optional<std::function<void(void)>> _keyPressedCallbacks[GLFW_KEY_LAST];
            std::optional<std::function<void(void)>> _keyReleasedCallbacks[GLFW_KEY_LAST];
            std::optional<std::function<void(void)>> _keyRepeatCallbacks[GLFW_KEY_LAST];
    };
} // namespace Glep

#endif /* !KEYBOARDHANDLER_HPP_ */
