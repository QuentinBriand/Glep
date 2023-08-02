/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PointLight
*/

#include <Graphics/PointLight.hpp>

namespace Glep
{
    PointLight::PointLight(const glm::vec3 &ambient, const glm::vec3 &diffuse, const glm::vec3 &specular)
    {
        _ambient = ambient;
        _diffuse = diffuse;
        _specular = specular;
    }

    void PointLight::setAmbientColor(const glm::vec3 &ambient)
    {
        _ambient = ambient;
    }

    void PointLight::setDiffuseColor(const glm::vec3 &diffuse)
    {
        _diffuse = diffuse;
    }

    void PointLight::setSpecularColor(const glm::vec3 &specular)
    {
        _specular = specular;
    }

    const glm::vec3 &PointLight::getAmbientColor(void) const
    {
        return _ambient;
    }

    const glm::vec3 &PointLight::getDiffuseColor(void) const
    {
        return _diffuse;
    }

    const glm::vec3 &PointLight::getSpecularColor(void) const
    {
        return _specular;
    }
} // namespace Glep
