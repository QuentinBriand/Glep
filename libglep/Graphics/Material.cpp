/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** Material
*/

#include <Graphics/Material.hpp>

namespace Glep
{
    Material::Material(const glm::vec3 &ambientColor, const glm::vec3 &diffuseColor, const glm::vec3 &specularColor, const int &shininess)
    {
        _ambientColor = ambientColor;
        _diffuseColor = diffuseColor;
        _specularColor = specularColor;
        _shininess = shininess;
    }

    const glm::vec3 &Material::getAmbientColor() const
    {
        return _ambientColor;
    }

    const glm::vec3 &Material::getDiffuseColor() const
    {
        return _diffuseColor;
    }

    const glm::vec3 &Material::getSpecularColor() const
    {
        return _specularColor;
    }

    const int &Material::getShininess() const
    {
        return _shininess;
    }
} // namespace Glep
