#ifndef BLOSSOM_ENGINE_GAME_SPRITE_HEADER
#define BLOSSOM_ENGINE_GAME_SPRITE_HEADER

#include "engine/game/object.hpp"
#include "engine/graphics/vectors.hpp"
#include "engine/graphics/texture.hpp"

#include "raylib.h"

class Sprite : public Object {
    private:
        Texture2D texture;
        GFX::TextureFilter textureFilter = GFX::TextureFilter::Linear;
        char *texturePath = nullptr;

    public:
        GFX::Vector2 position = {0.0, 0.0};
        GFX::Vector2 scale = {1.0, 1.0};
        double rotation = 0.0;
        GFX::Vector4 color = {1.0, 1.0, 1.0, 1.0};
        bool visible = true;

        Sprite(double x, double y, const char* initialTexturePath = nullptr);
        virtual ~Sprite();

        virtual void event(ObjectEvent event);
        virtual void loadTexture(const char* path);
        virtual bool isTextureLoaded(void);
        virtual void setTextureFilter(GFX::TextureFilter filter);
        virtual GFX::TextureFilter getTextureFilter(void);
};

#endif // !BLOSSOM_ENGINE_GAME_OBJECT_HEADER