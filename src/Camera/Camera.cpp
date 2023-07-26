/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Camera
*/

#include "Camera/Camera.hpp"

namespace Glep
{
    Camera::Camera(glm::ivec4 &viewport, float fov, float near, float far) : _viewport(viewport) {
        _fov = fov;
        _near = near;
        _far = far;
        _YModifier = -1;
    }

    void Camera::updateProjectionMatrix(void)
    {
        _projectionMatrix = glm::perspective(glm::radians(_fov), (float)_viewport.z / (float)_viewport.w, _near, _far);
    }

    void Camera::setFov(float fov)
    {
        _fov = fov;
    }

    void Camera::setNear(float near)
    {
        _near = near;
    }

    void Camera::setFar(float far)
    {
        _far = far;
    }

    glm::mat4 &Camera::getProjectionMatrix(void)
    {
        updateProjectionMatrix();
        return _projectionMatrix;
    }

} // namespace Glep
