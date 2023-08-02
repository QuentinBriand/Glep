/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** LightHandler
*/

#include <LightHandler.hpp>

namespace Glep
{
    void LightHandler::addPointLight(PointLight &light)
    {
        _pointLights.push_back(light);
    }

    void LightHandler::removePointLight(PointLight &light)
    {
        for (auto it = _pointLights.begin(); it != _pointLights.end(); it++) {
            if (std::addressof(it->get()) == std::addressof(light)) {
                _pointLights.erase(it);
                return;
            }
        }
    }

    const std::list<std::reference_wrapper<PointLight>> &LightHandler::getPointLights(void) const
    {
        return _pointLights;
    }
} // namespace Glep
