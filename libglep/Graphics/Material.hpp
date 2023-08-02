/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
    #define MATERIAL_HPP_

    #include <glm/glm.hpp>

namespace Glep
{
    class Material {
        public:
            Material(const glm::vec3 &ambientColor = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3 &diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f), const glm::vec3 &specularColor = glm::vec3(1.0f, 1.0f, 1.0f), const int &shininess = 32);
            ~Material() = default;

            const glm::vec3 &getAmbientColor() const;
            const glm::vec3 &getDiffuseColor() const;
            const glm::vec3 &getSpecularColor() const;
            const int &getShininess() const;
        private:
            glm::vec3 _ambientColor;
            glm::vec3 _diffuseColor;
            glm::vec3 _specularColor;
            int _shininess;
    };
} // namespace Glep

#endif /* !MATERIAL_HPP_ */
