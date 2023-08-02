/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Transform
*/

#include <Transform.hpp>

namespace Glep
{
    void Transform::setLocalPosition(const glm::vec3 &position)
    {
        _worldPosition = position;
    }

    void Transform::setLocalRotation(const glm::vec3 &rotation)
    {
        _localRotation = rotation;
        updateModelOrientation();
    }

    void Transform::setLocalScale(const glm::vec3 &scale)
    {
        _worldScale = scale;
    }

    void Transform::localTranslate(const glm::vec3 &translation)
    {
        _worldPosition += _right * translation.x;
        _worldPosition += _up * translation.y;
        _worldPosition += _forward * translation.z;
    }

    void Transform::globalTranslate(const glm::vec3 &translation)
    {
        _worldPosition.x += translation.x;
        _worldPosition.y += translation.y;
        _worldPosition.z += translation.z;
    }

    void Transform::rotate(const glm::vec3 &rotation)
    {
        _localRotation += rotation;
        updateModelOrientation();
    }

    void Transform::scale(const glm::vec3 &scale)
    {
        _worldScale += scale;
    }

    const glm::vec3 &Transform::getLocalPosition() const
    {
        return _worldPosition;
    }

    const glm::vec3 &Transform::getLocalScale() const
    {
        return _worldScale;
    }

    const glm::vec3 &Transform::getRight() const
    {
        return _right;
    }

    const glm::vec3 &Transform::getUp() const
    {
        return _up;
    }

    const glm::vec3 &Transform::getForward() const
    {
        return _forward;
    }

    const glm::vec3 Transform::getLocalRotation() const
    {
        return _localRotation;
    }

    void Transform::updateModelOrientation(void) const {
        _modelOrientation = glm::angleAxis(glm::radians(_localRotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
        _modelOrientation *= glm::angleAxis(glm::radians(_localRotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
        _modelOrientation *= glm::angleAxis(glm::radians(_localRotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

        _right = glm::vec3(1.0f, 0.0f, 0.0f) * _modelOrientation;
        _forward = glm::vec3(0.0f, 0.0f, 1.0f) * _modelOrientation;
        _up = glm::vec3(0.0f, 1.0f, 0.0f) * _modelOrientation;
    }

    const glm::mat4 &Transform::getTransformationMatrix() const
    {
        _worldTransformationMatrix = glm::mat4(1.0f);
        _worldTransformationMatrix = glm::translate(_worldTransformationMatrix, _worldPosition);
        _worldTransformationMatrix *= glm::toMat4(_modelOrientation);
        _worldTransformationMatrix = glm::scale(_worldTransformationMatrix, _worldScale);
        return _worldTransformationMatrix;
    }
} // namespace Glep
