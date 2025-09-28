#include "funkin/test_scene.hpp"
#include "raylib.h"

TestScene::TestScene() {
    dad = new Sprite(640.0, 360.0, "daddyDearest.png");
    dad->loadAnimationData("daddyDearest.xml");
    dad->addAnimation("idle", "idle", 24.0, true);
    dad->playAnimation("idle");
    append(dad);

    mainCamera = new CameraObject();
    mainCamera->position = {640.0, 360.0};
    append(mainCamera);

    hudCamera = new CameraObject();
    hudCamera->position = {640.0, 360.0};
    append(hudCamera);

    background = new Sprite(0.0, 0.0, "phillyForeground.png");
    background->origin = {0.0, 0.0};
    mainCamera->append(background);

    darnell = new Sprite(640.0, 360.0, "darnell.png");
    darnell->loadAnimationData("darnell.xml");
    darnell->addAnimation("idle", "Idle", 24.0, false);
    darnell->addAnimation("singLEFT", "Pose Left", 24.0, false, {-1.0, 0.0});
    darnell->addAnimation("singDOWN", "Pose Down", 24.0, false, {0.0, 3.0});
    darnell->addAnimation("singUP", "Pose Up", 24.0, false, {-8.0, -5.0});
    darnell->addAnimation("singRIGHT", "Pose Right", 24.0, false, {-4.0, -3.0});
    darnell->playAnimation("idle");
    hudCamera->append(darnell);
}

TestScene::~TestScene() {
    delete background;
    delete dad;
    delete darnell;
    delete mainCamera;
    delete hudCamera;
}

void TestScene::event(ObjectEvent event) {
    switch (event.type) {
        case Update: {
            double elapsed = *((double*)event.data);
            if (IsKeyDown(KEY_A)) {
                hudCamera->setZoom(hudCamera->getZoom() - (elapsed * 0.5));
            }

            if (IsKeyDown(KEY_D)) {
                hudCamera->setZoom(hudCamera->getZoom() + (elapsed * 0.5));
            }

            if (IsKeyPressed(KEY_SPACE)) {
                darnell->playAnimation("idle");
            }

            float wheel = GetMouseWheelMove();
            if (wheel != 0.0f) {
                mainCamera->setZoom((float)mainCamera->getZoom() + wheel * 0.1f);
            }

            if (IsKeyDown(KEY_I)) {
                mainCamera->position.y -= elapsed * 1000.0;
            }

            if (IsKeyDown(KEY_K)) {
                mainCamera->position.y += elapsed * 1000.0;
            }

            if (IsKeyDown(KEY_J)) {
                mainCamera->position.x -= elapsed * 1000.0;
            }

            if (IsKeyDown(KEY_L)) {
                mainCamera->position.x += elapsed * 1000.0;
            }

            if (IsKeyPressed(KEY_LEFT)) {
                darnell->playAnimation("singLEFT");
            }

            if (IsKeyPressed(KEY_DOWN)) {
                darnell->playAnimation("singDOWN");
            }

            if (IsKeyPressed(KEY_UP)) {
                darnell->playAnimation("singUP");
            }

            if (IsKeyPressed(KEY_RIGHT)) {
                darnell->playAnimation("singRIGHT");
            }

            break;
        } default:
            break;
    }

    Object::event(event);
}
