#ifndef BLOSSOM_ENGINE_GAME_ANIMATION_ANIMATION_DATA_HEADER
#define BLOSSOM_ENGINE_GAME_ANIMATION_ANIMATION_DATA_HEADER

#include "engine/graphics/vectors.hpp"
#include <stddef.h>
#include <string>

enum FrameRotation {
    RotationNone = 0,
    RotationNinety
};

struct AnimationFrame {
    GFX::Vector4 region;
    GFX::Vector2 offset;
    GFX::Vector2 boundingBox;
    std::string name;
    FrameRotation rotation;
};

struct AnimationData {
    AnimationFrame* frames;
    size_t framesCount;
    size_t references;

    static AnimationData loadFromSparrow(const char* path);
};

#endif // !BLOSSOM_ENGINE_GAME_ANIMATION_ANIMATION_DATA_HEADER
