/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Transform
*/

#ifndef TRANSFORM_HPP_
    #define TRANSFORM_HPP_

    #include <glm/glm.hpp>
    #include <glm/gtc/type_ptr.hpp>
    #include <glm/gtc/quaternion.hpp>
    #include <glm/gtx/quaternion.hpp>
    #include <glm/gtc/matrix_transform.hpp>

    #include <iostream>

namespace Glep
{
    class Transform {
        public:
            Transform() = default;
            ~Transform() = default;

            void setLocalPosition(const glm::vec3 &position);
            void setLocalRotation(const glm::vec3 &rotation);
            void setLocalScale(const glm::vec3 &scale);

            void localTranslate(const glm::vec3 &translation);
            void globalTranslate(const glm::vec3 &translation);
            void rotate(const glm::vec3 &rotation);
            void scale(const glm::vec3 &scale);

            const glm::vec3 &getLocalPosition() const;
            const glm::vec3 getLocalRotation() const;
            const glm::vec3 &getLocalScale() const;

            const glm::vec3 &getRight() const;
            const glm::vec3 &getUp() const;
            const glm::vec3 &getForward() const;

            const glm::mat4 &getTransformationMatrix() const;
        protected:
        private:
            friend class Camera;
            char _YModifier = 1;
            void updateModelOrientation() const;

            glm::vec3 _worldPosition = glm::vec3(0.0f);
            glm::vec3 _worldScale = glm::vec3(1.0f);

            glm::vec3 _localRotation = glm::vec3(0.0f);

            mutable glm::vec3 _right = glm::vec3(1.0f, 0.0f, 0.0f);
            mutable glm::vec3 _forward = glm::vec3(0.0f, 0.0f, 1.0f);
            mutable glm::vec3 _up = glm::vec3(0.0f, 1.0f, 0.0f);

            mutable glm::quat _modelOrientation = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);

            mutable glm::mat4 _worldTransformationMatrix = glm::mat4(1.0f);
    };
} // namespace Glep

#endif /* !TRANSFORM_HPP_ */
