#pragma once

#include <vector>
#include <string>

#include "spectrum.h"

template<typename Type>
class Texture {
public:
    // https://registry.khronos.org/OpenGL-Refpages/gl4/html/glTexParameter.xhtml
    enum TextureFilter {
        NEAREST, LINEAR, CUBIC
    };
    enum TextureWrap {
        CLAMP, CLAMP_TO_BORDER,
        MIRRORED_REPEAT, REPEAT,
        MIRROR_CLAMP_TO_EDGE, CLAMP_TO_EDGE
    };
    TextureFilter textureFilter;
    TextureWrap textureWrap;

    Type defaultValue;
    int width;
    int height;
    Type *pixels;

    // set pixels to nullptr
    Texture(Type defaultValue = Type(0));

    // create pixels, initialize to zero
    Texture(int width, int height);

    // load from image
    Texture(std::string image_path);

    // clean-up
    ~Texture();

    // uv from 0 to 1, bottom left is (0,0), bottom right is (1,0)
    // returns interpolated pixel value
    // returns default if pixels is nullptr
    Type getValue(vec2 uv) const;

    // save image
    // auto determine file type from extension
    // most image formats (including HDR): https://github.com/nothings/stb/blob/master/stb_image_write.h
    Type writeImage(std::string filename) const;
};
