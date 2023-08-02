/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** LightHandler
*/

#ifndef LIGHTHANDLER_HPP_
    #define LIGHTHANDLER_HPP_

    #include <list>
    #include <functional>
    #include <Graphics/Lights/PointLight.hpp>

namespace Glep
{
    class LightHandler {
        public:
            LightHandler() = default;
            ~LightHandler() = default;

            void addPointLight(PointLight &light);
            void removePointLight(PointLight &light);

            const std::list<std::reference_wrapper<PointLight>> &getPointLights(void) const;
        private:
            std::list<std::reference_wrapper<PointLight>> _pointLights;
    };
} // namespace Glep

#endif /* !LIGHTHANDLER_HPP_ */
