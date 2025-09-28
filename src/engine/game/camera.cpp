#include "engine/game/camera.hpp"

CameraObject::CameraObject() {
    internalCamera.zoom = 1.0f;
    internalCamera.rotation = 0.0f;
}

CameraObject::~CameraObject() {

}

void CameraObject::event(ObjectEvent event) {
    if (event.type == Update) {
        internalCamera.target = {
            ((float)GetScreenWidth() / -2.0f) + (float)position.x,
            ((float)GetScreenHeight() / -2.0f) + (float)position.y
        };

        internalCamera.offset = {
            ((float)GetScreenWidth() / 2.0f) * (1.0f - internalCamera.zoom),
            ((float)GetScreenHeight() / 2.0f) * (1.0f - internalCamera.zoom)
        };
    }

    if (event.type == Draw) {
        BeginMode2D(internalCamera);
    }

    Object::event(event);

    if (event.type == Draw) {
        EndMode2D();
    }
}

double CameraObject::getZoom(void) {
    return (double)internalCamera.zoom;
}

void CameraObject::setZoom(double zoom) {
    internalCamera.zoom = (float)zoom;
}

double CameraObject::getRotation(void) {
    return (double)internalCamera.rotation;
}

void CameraObject::setRotation(double rotation) {
    internalCamera.rotation = (float)rotation;
}