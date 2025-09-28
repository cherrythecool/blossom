#include "engine/game/game.hpp"

namespace Blossom {
    Game::Game() {}

    Game::~Game() {
        if (!empty()) {
            delete scene;
        }
    }

    void Game::setScene(Object* _scene) {
        scene = _scene;
    }

    Object* Game::getScene(void) {
        return scene;
    }

    bool Game::empty(void) {
        return scene == nullptr;
    }

    double Game::getLastElapsed(void) {
        return lastElapsedSeconds;
    }

    void Game::update(double elapsedSeconds) {
        lastElapsedSeconds = elapsedSeconds;

        if (empty()) {
            return;
        }

        scene->event({Update, &lastElapsedSeconds});
    }

    void Game::draw(void) {
        if (empty()) {
            return;
        }

        scene->event({Draw, nullptr});
    }
}