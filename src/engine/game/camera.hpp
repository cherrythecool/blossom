#ifndef BLOSSOM_ENGINE_GAME_CAMERA_HEADER
#define BLOSSOM_ENGINE_GAME_CAMERA_HEADER

#include "engine/game/object.hpp"
#include "engine/graphics/vectors.hpp"

#include "raylib.h"

class CameraObject : public Object {
    private:
        Camera2D internalCamera;

    public:
        GFX::Vector2 position = {0.0, 0.0};

        CameraObject();
        virtual ~CameraObject();

        virtual void event(ObjectEvent event);

        virtual double getZoom(void);
        virtual void setZoom(double zoom);

        virtual double getRotation(void);
        virtual void setRotation(double rotation);
};

#endif // !BLOSSOM_ENGINE_GAME_CAMERA_HEADER