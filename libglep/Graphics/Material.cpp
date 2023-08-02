/*
** EPITECH PROJECT, 2023
** Glep
** File description:
** Material
*/

#include <Graphics/Material.hpp>

namespace Glep
{
    Material::Material(
        const glm::vec3 &diffuseColor,
        const int &shininess,
        const float &emissiveStrength
    ) {
        _shininess = shininess;
        _diffuseColor = diffuseColor;
        _emissiveStrength = emissiveStrength;
    }

    Material::Material(
        Texture &diffuseTexture,
        const int &shininess,
        const float &emissiveStrength
    ) {
        _shininess = shininess;
        _diffuseTexture = diffuseTexture;
        _emissiveStrength = emissiveStrength;
        _textureFlags |= TextureFlag::DIFFUSE;
    }

    void Material::setShininess(const int &shininess)
    {
        _shininess = shininess;
    }

    void Material::setEmissiveStrength(const float &emissiveStrength)
    {
        _emissiveStrength = emissiveStrength;
    }

    void Material::setDiffuseColor(const glm::vec3 &diffuseColor)
    {
        _diffuseColor = diffuseColor;
    }

    void Material::setSpecularColor(const glm::vec3 &specularColor)
    {
        _specularColor = specularColor;
    }

    void Material::setEmissionColor(const glm::vec3 &emissionColor)
    {
        _emissionColor = emissionColor;
    }

    void Material::setDiffuseTexture(Texture &diffuseTexture)
    {
        _textureFlags |= TextureFlag::DIFFUSE;
        _diffuseTexture = diffuseTexture;
    }

    void Material::setSpecularTexture(Texture &specularTexture)
    {
        _textureFlags |= TextureFlag::SPECULAR;
        _specularTexture = specularTexture;
    }

    void Material::setEmissionTexture(Texture &emissionTexture)
    {
        _textureFlags |= TextureFlag::EMISSION;
        _emissionTexture = emissionTexture;
    }

    const glm::vec3 &Material::getDiffuseColor() const
    {
        return _diffuseColor;
    }

    const glm::vec3 &Material::getSpecularColor() const
    {
        return _specularColor;
    }

    const glm::vec3 &Material::getEmissionColor() const
    {
        return _emissionColor;
    }

    const Texture &Material::getDiffuseTexture() const
    {
        if (!_diffuseTexture.has_value())
            throw std::runtime_error("Material has no diffuse texture");
        return _diffuseTexture.value();
    }

    const Texture &Material::getSpecularTexture() const
    {
        if (!_specularTexture.has_value())
            throw std::runtime_error("Material has no specular texture");
        return _specularTexture.value();
    }

    const Texture &Material::getEmissionTexture() const
    {
        if (!_emissionTexture.has_value())
            throw std::runtime_error("Material has no emission texture");
        return _emissionTexture.value();
    }

    const int &Material::getShininess() const
    {
        return _shininess;
    }

    const unsigned char &Material::getTextureFlags() const
    {
        return _textureFlags;
    }

    const float &Material::getEmissiveStrength() const
    {
        return _emissiveStrength;
    }
} // namespace Glep
