/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PointLight
*/

#ifndef POINTLIGHT_HPP_
    #define POINTLIGHT_HPP_

    #include <glm/glm.hpp>

namespace Glep
{
    class PointLight {
        public:
            PointLight() = default;
            ~PointLight() = default;
            PointLight(const glm::vec3 &color, const float &intensity);

        protected:
        private:
            glm::vec3 _color = glm::vec3(1.0f, 1.0f, 1.0f);
            float _intensity = 1.0f;
    };
} // namespace Glep

#endif /* !POINTLIGHT_HPP_ */
