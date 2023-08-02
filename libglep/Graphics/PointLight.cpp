/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PointLight
*/

#include <Graphics/PointLight.hpp>

namespace Glep
{

    PointLight::PointLight(const glm::vec3 &color, const float &intensity) : _color(color), _intensity(intensity)
    {
    }

    void PointLight::setColor(const glm::vec3 &color)
    {
        _color = color;
    }

    void PointLight::setIntensity(const float &intensity)
    {
        _intensity = intensity;
    }

    const glm::vec3 &PointLight::getColor(void) const
    {
        return _color;
    }

    const float &PointLight::getIntensity(void) const
    {
        return _intensity;
    }

} // namespace Glep
