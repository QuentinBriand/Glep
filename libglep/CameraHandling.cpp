/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** CameraHandling
*/

#include <Window.hpp>

namespace Glep
{
    Camera Window::createCamera(const float &fov, const float &nearPlane, const float &farPlane)
    {
        return Camera(_viewport, fov, nearPlane, farPlane);
    }

    void Window::setActiveCamera(Camera &camera)
    {
        _activeCamera = camera;
    }
} // namespace Glep
