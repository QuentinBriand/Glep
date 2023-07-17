/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** CameraHandling
*/

#include "Window/Window.hpp"

namespace Glep
{
    Camera Window::createCamera(float fov, float nearPlane, float farPlane)
    {
        return Camera(_viewport, fov, nearPlane, farPlane);
    }

    void Window::setActiveCamera(Camera &camera)
    {
        _activeCamera = camera;
    }
} // namespace Glep
