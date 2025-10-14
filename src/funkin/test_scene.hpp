#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include "engine/game/object.hpp"
#include "engine/game/sprite.hpp"
#include "engine/game/camera.hpp"
#include "engine/game/sound_player.hpp"

using namespace Blossom;

class TestScene : public Object {
    private:
        Sprite* background;
        Sprite* dad;
        Sprite* darnell;
        Blossom::Camera* mainCamera;
        Blossom::Camera* hudCamera;
        SoundPlayer* inst;
        SoundPlayer* voicesDarnell;
        SoundPlayer* voicesPico;

    public:
        TestScene();
        ~TestScene();

        void event(ObjectEvent event);
};

#endif // !TEST_SCENE_HEADER
