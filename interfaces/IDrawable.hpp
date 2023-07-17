/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** IDrawable
*/

#ifndef IDRAWABLE_HPP_
    #define IDRAWABLE_HPP_

namespace Glep
{
    class GraphicsPipeline;
    class IDrawable {
        public:
            ~IDrawable() = default;

            virtual void draw(const GraphicsPipeline &pipeline) const = 0;
        protected:
        private:
    };
} // namespace Glep

#endif /* !IDRAWABLE_HPP_ */
