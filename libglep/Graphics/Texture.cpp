/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Texture
*/

#include <Graphics/Texture.hpp>

namespace Glep
{
    int Texture::getMixedLogic(const FilterLogic &zoomLogic)
    {
        return zoomLogic[0] == LINEAR ?
                zoomLogic[1] == LINEAR ?
                    GL_LINEAR_MIPMAP_LINEAR : GL_LINEAR_MIPMAP_NEAREST :
                zoomLogic[1] == LINEAR ?
                    GL_NEAREST_MIPMAP_LINEAR : GL_NEAREST_MIPMAP_NEAREST;
    }

    Texture Texture::loadFromFile(const std::string &path,
        const TextureRepetition &repetition,
        const FilterLogic &zoomInLogic,
        const FilterLogic &zoomOutLogic)
    {
        Texture texture;
        stbi_set_flip_vertically_on_load(true);
        auto *img_data = stbi_load(path.c_str(),
            &texture._width, &texture._height, &texture._nbChannels, 0);
        if (!img_data)
            throw std::runtime_error("Failed to load texture");

        glGenTextures(1, &texture._id);
        glBindTexture(GL_TEXTURE_2D, texture._id);

        texture._repetition = repetition;
        texture._zoomInLogic[0] = zoomInLogic[0]; texture._zoomInLogic[1] = zoomInLogic[1];
        texture._zoomOutLogic[0] = zoomOutLogic[0]; texture._zoomOutLogic[1] = zoomOutLogic[1];

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, repetition);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, repetition);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, getMixedLogic(zoomInLogic));
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, getMixedLogic(zoomOutLogic));

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture._width, texture._height, 0, GL_RGB, GL_UNSIGNED_BYTE, img_data);
        glGenerateMipmap(GL_TEXTURE_2D);
        stbi_image_free(img_data);
        glBindTexture(GL_TEXTURE_2D, 0);
        return texture;
    }

    Texture::~Texture()
    {
        glDeleteTextures(1, &this->_id);
    }
} // namespace Glep
