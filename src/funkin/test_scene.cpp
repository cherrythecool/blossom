#include "funkin/test_scene.hpp"
#include "raylib.h"

TestScene::TestScene() {
    background = new Sprite(0.0, 0.0, "phillyForeground.png");
    append(background);

    dad = new Sprite(640.0, 360.0, "daddyDearest.png");
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
        case Update: {
            double elapsed = *((double*)event.data);
            if (IsKeyDown(KEY_A)) {
                dad->scale = {dad->scale.x - (elapsed * 0.5), dad->scale.y - (elapsed * 0.5)};
            }

            if (IsKeyDown(KEY_D)) {
                dad->scale = {dad->scale.x + (elapsed * 0.5), dad->scale.y + (elapsed * 0.5)};
            }

            if (IsKeyPressed(KEY_SPACE)) {
                dad->playing = !dad->playing;
            }

            break;
        } default:
            break;
    }

    Object::event(event);
}
