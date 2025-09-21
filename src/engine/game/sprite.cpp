#include "engine/game/sprite.hpp"

#include "engine/assets/assets.hpp"

Sprite::Sprite(double x, double y, const char* initialTexturePath) {
    position = {x, y};

    if (initialTexturePath != nullptr) {
        loadTexture(initialTexturePath);
    }

    scale.scale(6.0);
}

Sprite::~Sprite() {
    if (loadedTexture) {
        Assets::instance->dereferenceTexture((const char*)texturePath);
    }
}

void Sprite::event(ObjectEvent event) {
    Object::event(event);

    if (event.type == Update) {
        rotation += *((double*)event.data) * 90.0;
    }

    if (event.type == Draw) {
        if (!loadedTexture) {
            return;
        }

        GFX::Vector4 rgbaColor = color;
        rgbaColor.scaleToRGBA();
        DrawTexturePro(
            texture,
            {0, 0, (float)texture.width, (float)texture.height},
            {(float)position.x, (float)position.y, (float)texture.width * (float)scale.x, (float)texture.height * (float)scale.y},
            {((float)texture.width/2.0f) * (float)scale.x, ((float)texture.height/2.0f) * (float)scale.y},
            rotation,
            {(unsigned char)rgbaColor.x, (unsigned char)rgbaColor.y, (unsigned char)rgbaColor.z, (unsigned char)rgbaColor.w}
        );
    }
}

void Sprite::loadTexture(const char* path) {
    Texture2D loading = Assets::instance->getTexture(path);
    if (IsTextureValid(loading)) {
        if (loadedTexture) {
            Assets::instance->dereferenceTexture((const char*)texturePath);
        }

        texturePath = (char*)path;
        texture = loading;
    }

    loadedTexture = IsTextureValid(texture);
    setTextureFilter(textureFilter);
}

void Sprite::setTextureFilter(GFX::TextureFilter filter) {
    textureFilter = filter;

    if (loadedTexture) {
        SetTextureFilter(texture, textureFilter == GFX::TextureFilter::Linear ? TEXTURE_FILTER_BILINEAR : TEXTURE_FILTER_POINT);
    }
}

GFX::TextureFilter Sprite::getTextureFilter(void) {
    return textureFilter;
}