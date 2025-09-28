#ifndef BLOSSOM_ENGINE_GAME_SPRITE_HEADER
#define BLOSSOM_ENGINE_GAME_SPRITE_HEADER

#include "engine/game/object.hpp"
#include "engine/graphics/vectors.hpp"
#include "engine/graphics/texture.hpp"
#include "engine/game/animation/animation_data.hpp"

#include "raylib.h"
#include <map>
#include <string>

namespace Blossom {
    struct SpriteAnimation {
        double frameRate;
        bool loop;
        size_t* frames;
        size_t framesCount;
        Blossom::Vector2 offset;
    };

    class Sprite : public Object {
        private:
            Texture2D texture;
            Blossom::TextureFilter textureFilter = Blossom::TextureFilter::Linear;
            char *texturePath = nullptr;

            AnimationData animationData;
            std::map<std::string, SpriteAnimation> animations;
            SpriteAnimation currentAnimation;
            size_t currentFrame = 0;
            double frameTimer = 0.0;

            void recalculateFrame(void);
            void drawNotAnimated(void);
            void drawAnimated(void);

        public:
            Blossom::Vector2 position = {0.0, 0.0};
            Blossom::Vector2 scale = {1.0, 1.0};
            Blossom::Vector2 origin = {0.5, 0.5};
            double rotation = 0.0;
            Blossom::Vector4 color = {1.0, 1.0, 1.0, 1.0};
            bool visible = true;
            bool animated = false;
            bool playing = true;

            Sprite(double x, double y, const char* initialTexturePath = nullptr);
            virtual ~Sprite();

            virtual void event(ObjectEvent event);
            virtual void loadTexture(const char* path);
            virtual bool isTextureLoaded(void);
            virtual void setTextureFilter(Blossom::TextureFilter filter);
            virtual Blossom::TextureFilter getTextureFilter(void);

            virtual void loadAnimationData(const char* path, bool clearAnimations = true);
            virtual void addAnimation(const char* id, const char* prefix, double frameRate = 24.0, bool loop = false, Blossom::Vector2 offset = {0.0, 0.0});
            virtual void playAnimation(const char* id);

            virtual void setAnimationFrame(size_t frame);
            virtual size_t getAnimationFrame(void);
    };
}

#endif // !BLOSSOM_ENGINE_GAME_OBJECT_HEADER
