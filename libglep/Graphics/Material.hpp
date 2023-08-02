/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** Material
*/

#ifndef MATERIAL_HPP_
    #define MATERIAL_HPP_

    #include <optional>
    #include <functional>
    #include <glm/glm.hpp>
    #include <Graphics/Texture.hpp>

namespace Glep
{

    class Material {
        public:
            enum TextureFlag {
                DIFFUSE = 1,
                SPECULAR = 2,
                EMISSION = 4
            };

            Material(
                const glm::vec3 &diffuseColor = glm::vec3(1.0f),
                const int &shininess = 32,
                const float &emissiveStrength = 1.0f
            );

            Material(
                Texture &diffuseTexture,
                const int &shininess = 32,
                const float &emissiveStrength = 1.0f
            );

            Material(const Material &other) = default;
            Material &operator=(const Material &other) = default;
            ~Material() = default;

            void setShininess(const int &shininess);
            void setEmissiveStrength(const float &emissiveStrength);

            void setDiffuseColor(const glm::vec3 &diffuseColor);
            void setSpecularColor(const glm::vec3 &specularColor);
            void setEmissionColor(const glm::vec3 &emissionColor);

            void setDiffuseTexture(Texture &diffuseTexture);
            void setSpecularTexture(Texture &specularTexture);
            void setEmissionTexture(Texture &emissionTexture);

            const glm::vec3 &getDiffuseColor() const;
            const glm::vec3 &getSpecularColor() const;
            const glm::vec3 &getEmissionColor() const;

            const Texture &getDiffuseTexture() const;
            const Texture &getSpecularTexture() const;
            const Texture &getEmissionTexture() const;

            const int &getShininess() const;
            const float &getEmissiveStrength() const;
            const unsigned char &getTextureFlags() const;
        private:
            glm::vec3 _diffuseColor = glm::vec3(1.0f, 1.0f, 1.0f);
            glm::vec3 _specularColor = glm::vec3(1.0f, 1.0f, 1.0f);
            glm::vec3 _emissionColor = glm::vec3(0.0f, 0.0f, 0.0f);

            std::optional<std::reference_wrapper<Texture>> _diffuseTexture = std::nullopt;
            std::optional<std::reference_wrapper<Texture>> _specularTexture = std::nullopt;
            std::optional<std::reference_wrapper<Texture>> _emissionTexture = std::nullopt;

            int _shininess;
            float _emissiveStrength = 0;
            unsigned char _textureFlags = 0;
    };
} // namespace Glep

#endif /* !MATERIAL_HPP_ */
