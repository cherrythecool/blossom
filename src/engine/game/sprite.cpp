#include "engine/game/sprite.hpp"

#include "engine/string.hpp"
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

    switch (event.type) {
        case Update:
            if (!animated) {
                return;
            }

            if (playing) {
                frameTimer += *((double*)event.data);
                recalculateFrame();
            }

            break;
        case Draw:
            if (!visible) {
                return;
            }

            if (!isTextureLoaded()) {
                return;
            }

            if (scale.x < 0.0) {
                scale.x = 0.0;
            }

            if (scale.y < 0.0) {
                scale.y = 0.0;
            }

            if (animated && currentAnimation.framesCount != 0) {
                drawAnimated();
            } else {
                drawNotAnimated();
            }

            break;
        default:
            break;
    }
}

void Sprite::recalculateFrame(void) {
    if (currentAnimation.frameRate <= 0.0) {
        currentFrame = 0;
        return;
    }

    currentFrame = frameTimer * currentAnimation.frameRate;
    if (currentAnimation.loop) {
        currentFrame = currentFrame % currentAnimation.framesCount;
    } else {
        currentFrame = currentFrame < currentAnimation.framesCount ? currentFrame : currentAnimation.framesCount - 1;
    }
}

void Sprite::drawNotAnimated(void) {
    GFX::Vector4 rgbaColor = color;
    rgbaColor.scaleToRGBA();
    DrawTexturePro(
        texture,
        {0, 0, (float)texture.width, (float)texture.height},
        {(float)position.x, (float)position.y, (float)texture.width * (float)scale.x, (float)texture.height * (float)scale.y},
        {(float)texture.width * (float)origin.x * (float)scale.x, (float)texture.height * (float)origin.y * (float)scale.y},
        rotation,
        {(unsigned char)rgbaColor.x, (unsigned char)rgbaColor.y, (unsigned char)rgbaColor.z, (unsigned char)rgbaColor.w}
    );
}

void Sprite::drawAnimated(void) {
    GFX::Vector4 rgbaColor = color;
    rgbaColor.scaleToRGBA();

    size_t index = currentAnimation.frames[currentFrame];
    AnimationFrame frame = animationData.frames[index];
    GFX::Vector2 drawingBox = frame.boundingBox;
    switch (frame.rotation) {
        case RotationNinety:
            drawingBox.x = frame.boundingBox.y;
            drawingBox.y = frame.boundingBox.x;
            break;
        default:
            break;
    }

    Rectangle drawDestination = {
        (float)position.x - ((float)frame.offset.x * (float)scale.x),
        (float)position.y - ((float)frame.offset.y * (float)scale.y),
        (float)frame.region.z * (float)scale.x,
        (float)frame.region.w * (float)scale.y
    };

    Vector2 drawOrigin = {
        (float)drawingBox.x * (float)origin.x * (float)scale.x,
        (float)drawingBox.y * (float)origin.y * (float)scale.y
    };
    drawDestination.x += (float)drawingBox.x * (float)scale.x * 0.5f;
    drawDestination.y += (float)drawingBox.y * (float)scale.y * 0.5f;

    drawDestination.x -= drawOrigin.x;
    drawDestination.y -= drawOrigin.y;

    double drawRotation = rotation;

    switch (frame.rotation) {
        case RotationNinety:
            drawRotation -= 90.0;
        default:
            DrawTexturePro(
                texture,
                {
                    (float)frame.region.x,
                    (float)frame.region.y,
                    (float)frame.region.z,
                    (float)frame.region.w
                },
                drawDestination,
                {(float)drawingBox.x * (float)scale.x * 0.5f, (float)drawingBox.y * (float)scale.y * 0.5f},
                drawRotation,
                {
                    (unsigned char)rgbaColor.x,
                    (unsigned char)rgbaColor.y,
                    (unsigned char)rgbaColor.z,
                    (unsigned char)rgbaColor.w
                }
            );

            break;
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

void Sprite::addAnimation(const char* id, const char* prefix, double frameRate, bool loop) {
    SpriteAnimation animation = {0};
    animation.frameRate = frameRate;
    animation.loop = loop;

    for (size_t i = 0; i < animationData.framesCount; i++) {
        AnimationFrame frame = animationData.frames[i];
        if (Strings::startsWith(frame.name.c_str(), prefix)) {
            animation.framesCount++;
        }
    }

    animation.frames = new size_t[animation.framesCount];

    size_t framesIndex = 0;
    for (size_t i = 0; i < animationData.framesCount; i++) {
        AnimationFrame frame = animationData.frames[i];
        if (Strings::startsWith(frame.name.c_str(), prefix)) {
            animation.frames[framesIndex++] = i;
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
    frameTimer = 0.0;
    playing = true;
}

void Sprite::setFrame(size_t frame) {
    frameTimer = (double)frame / currentAnimation.frameRate;
}

size_t Sprite::getFrame(void) {
    recalculateFrame();
    return currentFrame;
}
