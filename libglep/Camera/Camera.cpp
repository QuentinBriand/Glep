/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Camera
*/

#include <Camera/Camera.hpp>

namespace Glep
{
    Camera::Camera(glm::ivec4 &viewport, float fov, float near, float far) : _viewport(viewport) {
        _fov = fov;
        _near = near;
        _far = far;
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

    const glm::mat4 &Camera::getTransformationMatrix() const
    {
        _worldTransformationMatrix = glm::mat4(1.0f);
        _worldTransformationMatrix *= glm::toMat4(_modelOrientation);
        _worldTransformationMatrix = glm::translate(_worldTransformationMatrix, -_worldPosition);
        _worldTransformationMatrix = glm::scale(_worldTransformationMatrix, _worldScale);
        return _worldTransformationMatrix;
    }
} // namespace Glep
