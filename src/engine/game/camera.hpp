#ifndef BLOSSOM_ENGINE_GAME_CAMERA_HEADER
#define BLOSSOM_ENGINE_GAME_CAMERA_HEADER

#include "engine/game/object.hpp"
#include "engine/graphics/vectors.hpp"

#include "raylib.h"

namespace Blossom {
    class Camera : public Object {
        private:
            Camera2D internalCamera;
    
        public:
            Blossom::Vector2 position = {0.0, 0.0};
    
            Camera();
            virtual ~Camera();
    
            virtual void event(ObjectEvent event);
    
            virtual double getZoom(void);
            virtual void setZoom(double zoom);
    
            virtual double getRotation(void);
            virtual void setRotation(double rotation);
    };
}

#endif // !BLOSSOM_ENGINE_GAME_CAMERA_HEADER