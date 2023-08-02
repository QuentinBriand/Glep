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

    void Mesh::setMaterial(Material &material)
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
        pipeline.use();
        pipeline.setUniform("model", getTransformationMatrix());
        if (_material.has_value()) {
            auto &matval = _material.value().get();
            auto &textureFlags = matval.getTextureFlags();
            if (textureFlags & Material::TextureFlag::DIFFUSE) {
                auto &diffuse = matval.getDiffuseTexture();
                glActiveTexture(GL_TEXTURE0);
                glBindTexture(GL_TEXTURE_2D, diffuse.getId());
                pipeline.setUniform("material.diffuseMap", 0);
            }
            if (textureFlags & Material::TextureFlag::SPECULAR) {
                auto &specular = matval.getSpecularTexture();
                glActiveTexture(GL_TEXTURE1);
                glBindTexture(GL_TEXTURE_2D, specular.getId());
                pipeline.setUniform("material.specularMap", 1);
            }
            if (textureFlags & Material::TextureFlag::EMISSION) {
                auto &emission = matval.getEmissionTexture();
                glActiveTexture(GL_TEXTURE2);
                glBindTexture(GL_TEXTURE_2D, emission.getId());
                pipeline.setUniform("material.emissiveMap", 2);
            }
            pipeline.setUniform("material.emissiveStrength", matval.getEmissiveStrength());
            pipeline.setUniform("material.emissive", matval.getEmissionColor());
            pipeline.setUniform("material.diffuse", matval.getDiffuseColor());
            pipeline.setUniform("material.specular", matval.getSpecularColor());
            pipeline.setUniform("material.shininess", matval.getShininess());
            pipeline.setUniform("material.textureFlag", (int)textureFlags);
        }
        glBindVertexArray(_VAOId);
        glPolygonMode(GL_FRONT, _displayMode);
        glDrawElements(_drawMode, _indices.size(), GL_UNSIGNED_INT, 0);
    }
} // namespace Glep
