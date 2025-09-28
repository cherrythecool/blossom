#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include "engine/game/object.hpp"
#include "engine/game/sprite.hpp"
#include "engine/game/camera.hpp"

class TestScene : public Object {
    private:
        Sprite* background;
        Sprite* dad;
        Sprite* darnell;
        CameraObject* mainCamera;
        CameraObject* hudCamera;

    public:
        TestScene();
        ~TestScene();

        void event(ObjectEvent event);
};

#endif // !TEST_SCENE_HEADER
