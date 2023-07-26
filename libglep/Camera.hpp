/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
    #define CAMERA_HPP_

    #include <Transform.hpp>

namespace Glep
{
    class Camera : public Transform {
        public:
            friend class Window;
            Camera() = delete;
            Camera(const Camera &copy) = delete;
            Camera &operator=(const Camera &copy) = delete;

            ~Camera() = default;

            void setFov(float fov);
            void setNear(float near);
            void setFar(float far);

            glm::mat4 &getProjectionMatrix(void);
        protected:
        private:
            Camera(glm::ivec4 &viewport, float fov, float near, float far);
            void updateProjectionMatrix(void);

            glm::ivec4 &_viewport;
            float _fov;
            float _near;
            float _far;

            glm::mat4 _projectionMatrix;

    };
} // namespace Glep

#endif /* !CAMERA_HPP_ */
