/*
** EPITECH PROJECT, 2023
** opengl
** File description:
** Texture
*/

#ifndef TEXTURE_HPP_
    #define TEXTURE_HPP_

    #ifndef STB_IMAGE_IMPLEMENTATION
        #define STB_IMAGE_IMPLEMENTATION
        #include "stb_image.h"
    #endif

    #include <stdexcept>
    #include <glad/glad.h>
    #include <GLFW/glfw3.h>

namespace Glep
{

    enum TextureRepetition {
        REPEAT          = GL_REPEAT,
        MIRRORED_REPEAT = GL_MIRRORED_REPEAT,
        DROOL_CLAMP     = GL_CLAMP_TO_EDGE,
        COLOR_CLAMP     = GL_CLAMP_TO_BORDER
    };
    enum TextureFiltering {
        NEAREST = GL_NEAREST,
        LINEAR  = GL_LINEAR
    };

    typedef TextureFiltering FilterLogic[2];

    #define DEFAULT_TEXTURE_REPETITION TextureRepetition::REPEAT
    #define DEFAULT_TEXTURE_FILTER_METHOD TextureFiltering::LINEAR
    #define DEFAULT_TEXTURE_FILTER_METHOD_MIPMAP TextureFiltering::LINEAR
    #define DEFAULT_TEXTURE_FILTER_LOGIC {DEFAULT_TEXTURE_FILTER_METHOD, DEFAULT_TEXTURE_FILTER_METHOD_MIPMAP}

    class Texture {
        public:
            Texture() = default;
            static int getMixedLogic(const FilterLogic &zoomLogic);
            static Texture loadFromFile(const std::string &path,
                const TextureRepetition &repetition = DEFAULT_TEXTURE_REPETITION,
                const FilterLogic &zoomInLogic = DEFAULT_TEXTURE_FILTER_LOGIC,
                const FilterLogic &zoomOutLogic = DEFAULT_TEXTURE_FILTER_LOGIC);
            ~Texture();

            int getWidth() const { return this->_width; }
            int getHeight() const { return this->_height; }
            int getNbChannels() const { return this->_nbChannels; }
            void use() const { glBindTexture(GL_TEXTURE_2D, this->_id); }
        private:
            unsigned int _id;
            TextureRepetition _repetition;
            FilterLogic _zoomInLogic;
            FilterLogic _zoomOutLogic;

            int _width;
            int _height;
            int _nbChannels;
    };
} // namespace Glep

#endif /* !TEXTURE_HPP_ */
