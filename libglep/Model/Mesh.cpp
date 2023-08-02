/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Mesh
*/

#include <Model/Mesh.hpp>

namespace Glep
{
    Mesh::Mesh()
    {
        glGenVertexArrays(1, &_VAOId);
        glGenBuffers(1, &_VBOId);
        glGenBuffers(1, &_EBOId);
    }

    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &_VBOId);
        glDeleteBuffers(1, &_EBOId);
    }

    void Mesh::setVertices(const std::vector<Vertex> &vertices)
    {
        _vertices.clear();
        for (auto &vertex : vertices) {
            _addVertex(vertex);
        }
        _updateVBO();
    }

    void Mesh::setIndices(const std::vector<unsigned int> &indices)
    {
        _indices = indices;
        _updateEBO();
    }

    void Mesh::addIndex(const unsigned int &index)
    {
        _indices.push_back(index);
        _updateEBO();
    }

    void Mesh::addVertex(const Vertex &vertex)
    {
        _addVertex(vertex);
        _updateVBO();
    }

    void Mesh::addIndices(const std::vector<unsigned int> &indices)
    {
        _indices.insert(_indices.end(), indices.begin(), indices.end());
        _updateEBO();
    }

    void Mesh::addVertices(const std::vector<Vertex> &vertices)
    {
        for (auto &newVertex : vertices) {
            _addVertex(newVertex);
        }
        _updateVBO();
    }

    const unsigned int &Mesh::getVBOId() const
    {
        return _VBOId;
    }

    const unsigned int &Mesh::getEBOId() const
    {
        return _EBOId;
    }

    void Mesh::_updateVBO()
    {
        glBindBuffer(GL_ARRAY_BUFFER, _VBOId);
        glBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(float),
            _vertices.data(), GL_STATIC_DRAW);
    }

    void Mesh::_updateEBO()
    {
        glBindVertexArray(_VAOId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBOId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int),
            _indices.data(), GL_STATIC_DRAW);
        // Position Location 0
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *)0);
        glEnableVertexAttribArray(0);
        // UV Location 1
        glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // Normal Location 2
        glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *)(5 * sizeof(float)));
        glEnableVertexAttribArray(2);
        // Color Location 3
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void *)(8 * sizeof(float)));
        glEnableVertexAttribArray(3);
    }

    void Mesh::setDrawMode(const DrawMode &drawMode)
    {
        _drawMode = drawMode;
    }

    void Mesh::setDisplayMode(const DisplayMode &displayMode)
    {
        _displayMode = displayMode;
    }

    void Mesh::setTexture(const Texture &texture)
    {
        _texture = texture;
    }

    void Mesh::setMaterial(const Material &material)
    {
        _material = material;
    }

    void Mesh::_addVertex(const Vertex &vertex)
    {
        _vertices.push_back(vertex.position.x);
        _vertices.push_back(vertex.position.y);
        _vertices.push_back(vertex.position.z);
        _vertices.push_back(vertex.uv.x);
        _vertices.push_back(vertex.uv.y);
        _vertices.push_back(vertex.normal.x);
        _vertices.push_back(vertex.normal.y);
        _vertices.push_back(vertex.normal.z);
        _vertices.push_back(vertex.color.r);
        _vertices.push_back(vertex.color.g);
        _vertices.push_back(vertex.color.b);
    }

    void Mesh::draw(const GraphicsPipeline &pipeline) const
    {
        pipeline.setUniform("model", getTransformationMatrix());
        if (_texture.has_value()) {
            _texture.value().use();
        }
        if (_material.has_value()) {
            auto matval = _material.value();
            pipeline.setUniform("material.ambient", matval.getAmbientColor());
            pipeline.setUniform("material.diffuse", matval.getDiffuseColor());
            pipeline.setUniform("material.specular", matval.getSpecularColor());
            pipeline.setUniform("material.shininess", matval.getShininess());
        }
        glBindVertexArray(_VAOId);
        glPolygonMode(GL_FRONT_AND_BACK, _displayMode);
        glDrawElements(_drawMode, _indices.size(), GL_UNSIGNED_INT, 0);
    }
} // namespace Glep
