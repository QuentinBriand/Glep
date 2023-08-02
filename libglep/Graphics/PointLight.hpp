/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PointLight
*/

#ifndef POINTLIGHT_HPP_
    #define POINTLIGHT_HPP_

    #include <glm/glm.hpp>

    #include <Transform.hpp>

namespace Glep
{
    class PointLight : public Transform {
        public:
            ~PointLight() = default;
            PointLight(const glm::vec3 &color = glm::vec3(1.0f, 1.0f, 1.0f), const float &intensity = 1.0f);

            void setColor(const glm::vec3 &color);
            void setIntensity(const float &intensity);

            const glm::vec3 &getColor(void) const;
            const float &getIntensity(void) const;

        protected:
        private:
            glm::vec3 _color;
            float _intensity;
    };
} // namespace Glep

#endif /* !POINTLIGHT_HPP_ */
