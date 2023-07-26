/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** PhongMaterial
*/

#ifndef PHONGMATERIAL_HPP_
    #define PHONGMATERIAL_HPP_

namespace Glep
{
    class PhongMaterial {
        public:
            PhongMaterial() = default;
            ~PhongMaterial() = default;
        protected:
        private:
            float _ambientStrength = 0.1f;
    };
} // namespace Glep

#endif /* !PHONGMATERIAL_HPP_ */
