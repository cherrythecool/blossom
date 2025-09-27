#include "engine/game/sprite.hpp"

#include "engine/assets/assets.hpp"
#include "engine/game/animation/animation_data.hpp"

Sprite::Sprite(double x, double y, const char* initialTexturePath) {
    position = {x, y};

    if (initialTexturePath != nullptr) {
        loadTexture(initialTexturePath);
    }
}

Sprite::~Sprite() {
    if (isTextureLoaded()) {
        Assets::instance->dereferenceTexture((const char*)texturePath);
    }

    for (std::pair<std::string, SpriteAnimation> pair : animations) {
        delete[] pair.second.frames;
    }
}

void Sprite::event(ObjectEvent event) {
    Object::event(event);

    if (event.type == Draw) {
        if (!visible) {
            return;
        }

        if (!isTextureLoaded()) {
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
        if (isTextureLoaded()) {
            Assets::instance->dereferenceTexture((const char*)texturePath);
        }

        texturePath = (char*)path;
        texture = loading;
    }

    setTextureFilter(textureFilter);
}

bool Sprite::isTextureLoaded(void) {
    return texturePath != nullptr;
}

void Sprite::setTextureFilter(GFX::TextureFilter filter) {
    textureFilter = filter;

    if (isTextureLoaded()) {
        SetTextureFilter(texture, textureFilter == GFX::TextureFilter::Linear ? TEXTURE_FILTER_BILINEAR : TEXTURE_FILTER_POINT);
    }
}

GFX::TextureFilter Sprite::getTextureFilter(void) {
    return textureFilter;
}

void Sprite::loadAnimationData(const char* path, bool clearAnimations) {
    if (clearAnimations) {
        animations.clear();
        animationData = {};
        animated = false;
    }

    AnimationData data = Assets::instance->getAnimation(path);
    if (data.frames == nullptr) {
        return;
    }

    animationData = data;
    animated = true;
}

// google ai overview code
#include <string.h> // Required for strncmp and strlen

// Function to check if a string starts with a given prefix
int startsWith(const char* str, const char* prefix) {
    // If the prefix is longer than the string, it cannot be a prefix
    if (strlen(prefix) > strlen(str)) {
        return 0; // False
    }
    // Compare the first 'strlen(prefix)' characters of 'str' and 'prefix'
    // If they are identical, strncmp returns 0
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

void Sprite::addAnimation(const char* id, const char* prefix, double frameRate, bool loop) {
    SpriteAnimation animation;
    animation.frameRate = frameRate;
    animation.loop = loop;

    for (size_t i = 0; i < animationData.framesCount; i++) {
        AnimationFrame frame = animationData.frames[i];
        if (startsWith(frame.name.c_str(), prefix)) {
            animation.framesCount++;
        }
    }

    animation.frames = new size_t[animation.framesCount];
    size_t index = 0;
    for (size_t i = 0; i < animationData.framesCount; i++) {
        AnimationFrame frame = animationData.frames[i];
        if (startsWith(frame.name.c_str(), prefix)) {
            animation.frames[index++] = i;
        }
    }

    animations[std::string(id)] = animation;
}

void Sprite::playAnimation(const char* id) {
    SpriteAnimation animation = animations[std::string(id)];
    if (animation.framesCount == 0) {
        return;
    }

    currentAnimation = animation;
    currentFrame = 0;
}
