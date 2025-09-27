#ifndef TEST_SCENE_HEADER
#define TEST_SCENE_HEADER

#include "engine/game/object.hpp"
#include "engine/game/sprite.hpp"

class TestScene : public Object {
    private:
        Sprite* background;
        Sprite* dad;

    public:
        TestScene();
        ~TestScene();

        void event(ObjectEvent event);
};

#endif // !TEST_SCENE_HEADER
