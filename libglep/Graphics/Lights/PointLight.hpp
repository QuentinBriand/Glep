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
            PointLight(const glm::vec3 &ambient = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3 &diffuse = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3 &specular = glm::vec3(1.0f, 1.0f, 1.0f));

            void setAmbientColor(const glm::vec3 &ambient);
            void setDiffuseColor(const glm::vec3 &diffuse);
            void setSpecularColor(const glm::vec3 &specular);

            const glm::vec3 &getAmbientColor(void) const;
            const glm::vec3 &getDiffuseColor(void) const;
            const glm::vec3 &getSpecularColor(void) const;

        protected:
        private:
            glm::vec3 _ambient;
            glm::vec3 _diffuse;
            glm::vec3 _specular;
    };
} // namespace Glep

#endif /* !POINTLIGHT_HPP_ */
