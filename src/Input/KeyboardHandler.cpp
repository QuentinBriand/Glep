/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** KeyboardHandler
*/

#include "Input/KeyboardHandler.hpp"

namespace Glep
{
    KeyboardHandler::KeyboardHandler()
    {
        for (int i = 0; i < GLFW_KEY_LAST; i++) {
            _keys[i] = false;
            _keyPressedCallbacks[i] = std::nullopt;
            _keyReleasedCallbacks[i] = std::nullopt;
            _keyRepeatCallbacks[i] = std::nullopt;
        }
    }

    KeyboardHandler::~KeyboardHandler()
    {
    }

    void KeyboardHandler::update(void)
    {
        for (int i = 0; i < GLFW_KEY_LAST; i++) {
            auto &pressCallback = _keyPressedCallbacks[i];
            auto &releaseCallback = _keyReleasedCallbacks[i];
            auto &repeatCallback = _keyRepeatCallbacks[i];
            bool hasPressCallback = pressCallback.has_value();
            bool hasReleaseCallback = releaseCallback.has_value();
            bool hasRepeatCallback = repeatCallback.has_value();

            if (!hasPressCallback && !hasReleaseCallback && !hasRepeatCallback)
                continue;
            int newKeyState = glfwGetKey(glfwGetCurrentContext(), i);
            if (newKeyState == GLFW_PRESS && _keys[i] == GLFW_REPEAT && hasRepeatCallback) {
                repeatCallback.value()();
            } else if ((hasPressCallback || hasRepeatCallback) && newKeyState == GLFW_PRESS) {
                if (_keys[i] == GLFW_RELEASE && hasPressCallback)
                    pressCallback.value()();
                if (_keys[i] == GLFW_PRESS && hasRepeatCallback) {
                    _keys[i] = GLFW_REPEAT;
                    repeatCallback.value()();
                }
            } else if (hasReleaseCallback && newKeyState == GLFW_RELEASE && _keys[i] == GLFW_PRESS) {
                releaseCallback.value()();
            }
            _keys[i] = newKeyState;
        }
    }

    void KeyboardHandler::setKeyPressedCallback(int key, std::function<void()> callback)
    {
        _keyPressedCallbacks[key] = callback;
    }

    void KeyboardHandler::setKeyReleasedCallback(int key, std::function<void()> callback)
    {
        _keyReleasedCallbacks[key] = callback;
    }

    void KeyboardHandler::setKeyRepeatCallback(int key, std::function<void()> callback)
    {
        _keyRepeatCallbacks[key] = callback;
    }

    void KeyboardHandler::removeKeyPressedCallback(int key)
    {
        _keyPressedCallbacks[key] = std::nullopt;
    }

    void KeyboardHandler::removeKeyReleasedCallback(int key)
    {
        _keyReleasedCallbacks[key] = std::nullopt;
    }

    void KeyboardHandler::removeKeyRepeatCallback(int key)
    {
        _keyRepeatCallbacks[key] = std::nullopt;
    }

    bool KeyboardHandler::isKeyPressed(int key) const
    {
        return _keys[key] == GLFW_PRESS;
    }

    bool KeyboardHandler::isKeyReleased(int key) const
    {
        return _keys[key] == GLFW_RELEASE;
    }

    bool KeyboardHandler::isKeyRepeat(int key) const
    {
        return _keys[key] == GLFW_REPEAT;
    }
} // namespace Glep
