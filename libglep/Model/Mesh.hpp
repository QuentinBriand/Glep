/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Mesh
*/

#ifndef MESH_HPP_
    #define MESH_HPP_

    #include <glad/glad.h>
    #include <GLFW/glfw3.h>

    #include <vector>
    #include <optional>

    #include <Model/Vertex.hpp>
    #include <Transform.hpp>
    #include <IDrawable.hpp>
    #include <Graphics/Texture.hpp>
    #include <GraphicsPipeline/GraphicsPipeline.hpp>

namespace Glep
{
    enum DrawMode {
        TRIANGLES = GL_TRIANGLES,
        TRIANGLE_STRIP = GL_TRIANGLE_STRIP,
        TRIANGLE_FAN = GL_TRIANGLE_FAN,
        LINES = GL_LINES,
        LINE_STRIP = GL_LINE_STRIP,
        LINE_LOOP = GL_LINE_LOOP,
        POINTS = GL_POINTS
    };

    enum DisplayMode {
        FILL = GL_FILL,
        WIREFRAME = GL_LINE,
        VERTEX_ONLY = GL_POINT
    };

    class Mesh : public Transform, public IDrawable {
        public:
            Mesh();
            ~Mesh();

            void setVertices(const std::vector<Vertex> &vertices);
            void setIndices(const std::vector<unsigned int> &indices);

            void addVertices(const std::vector<Vertex> &vertices);
            void addIndices(const std::vector<unsigned int> &indices);

            void addVertex(const Vertex &vertex);
            void addIndex(const unsigned int &index);

            const std::vector<Vertex> &getVertices() const;
            const std::vector<unsigned int> &getIndices() const;

            const unsigned int &getVBOId() const;
            const unsigned int &getEBOId() const;

            void setTexture(const Texture &texture);
            void setDrawMode(const DrawMode &drawMode);
            void setDisplayMode(const DisplayMode &displayMode);

            virtual void draw(const GraphicsPipeline &pipeline) const final;
        protected:
        private:
            std::vector<float> _vertices;
            std::vector<unsigned int> _indices;

            std::optional<Texture> _texture = std::nullopt;

            unsigned int _VAOId;
            unsigned int _VBOId;
            unsigned int _EBOId;

            void _updateVBO();
            void _updateEBO();
            void _addVertex(const Vertex &vertex);
            DrawMode _drawMode = TRIANGLES;
            DisplayMode _displayMode = FILL;
    };
} // namespace Glep
#endif /* !MESH_HPP_ */
