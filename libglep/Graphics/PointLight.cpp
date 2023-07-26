/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PointLight
*/

#include <Graphics/PointLight.hpp>

Glep::PointLight::PointLight(const glm::vec3 &color, const float &intensity)
{
    _color = color;
    _intensity = intensity;
}
