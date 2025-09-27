#include "funkin/test_scene.hpp"
#include "raylib.h"

TestScene::TestScene() {
    background = new Sprite(0.0, 0.0, "phillyForeground.png");
    append(background);

    dad = new Sprite(0.0, 0.0, "daddyDearest.png");
    dad->loadAnimationData("daddyDearest.xml");
    dad->addAnimation("idle", "idle", 24.0, true);
    dad->playAnimation("idle");
    append(dad);
}

TestScene::~TestScene() {
    delete background;
    delete dad;
}

void TestScene::event(ObjectEvent event) {
    switch (event.type) {
        case Update:
            if (IsKeyPressed(KEY_SPACE)) {

            }

            break;
        default:
            break;
    }

    Object::event(event);
}
