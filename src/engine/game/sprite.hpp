#ifndef BLOSSOM_ENGINE_GAME_SPRITE_HEADER
#define BLOSSOM_ENGINE_GAME_SPRITE_HEADER

#include "engine/game/object.hpp"
#include "engine/graphics/vectors.hpp"
#include "engine/graphics/texture.hpp"
#include "engine/game/animation/animation_data.hpp"

#include "raylib.h"
#include <map>
#include <string>

struct SpriteAnimation {
    double frameRate;
    bool loop;
    size_t* frames;
    size_t framesCount;
};

class Sprite : public Object {
    private:
        Texture2D texture;
        GFX::TextureFilter textureFilter = GFX::TextureFilter::Linear;
        char *texturePath = nullptr;

        AnimationData animationData;
        std::map<std::string, SpriteAnimation> animations;
        SpriteAnimation currentAnimation;

    public:
        GFX::Vector2 position = {0.0, 0.0};
        GFX::Vector2 scale = {1.0, 1.0};
        double rotation = 0.0;
        GFX::Vector4 color = {1.0, 1.0, 1.0, 1.0};
        bool visible = true;
        bool animated = false;
        size_t currentFrame = 0;

        Sprite(double x, double y, const char* initialTexturePath = nullptr);
        virtual ~Sprite();

        virtual void event(ObjectEvent event);
        virtual void loadTexture(const char* path);
        virtual bool isTextureLoaded(void);
        virtual void setTextureFilter(GFX::TextureFilter filter);
        virtual GFX::TextureFilter getTextureFilter(void);

        virtual void loadAnimationData(const char* path, bool clearAnimations = true);
        virtual void addAnimation(const char* id, const char* prefix, double frameRate, bool loop);
        virtual void playAnimation(const char* id);
};

#endif // !BLOSSOM_ENGINE_GAME_OBJECT_HEADER
