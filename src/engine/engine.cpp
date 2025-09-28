#include "engine/engine.hpp"

#include "raylib.h"

#if _WIN32
#include "engine/windows.hpp"
#endif // _WIN32

namespace Blossom {
    Engine* Engine::instance;
    
    Engine::Engine(int gameWidth, int gameHeight, const char* windowTitle) {
        instance = this;
    
        SetConfigFlags(FLAG_WINDOW_HIGHDPI | FLAG_WINDOW_RESIZABLE);
        InitWindow(gameWidth, gameHeight, windowTitle);
        #if _WIN32
        WindowsWrappers::applyWindowDarkModeSetting(GetWindowHandle());
        #endif // _WIN32
    
        InitAudioDevice();
        SetTargetFPS(0);
    
        assets = new Assets();
        game = new Game();
    }
    
    Engine::~Engine() {
        delete game;
        delete assets;
        CloseAudioDevice();
        CloseWindow();
    
        if (instance == this) {
            instance = nullptr;
        }
    }
    
    Game* Engine::getGame(void) {
        return game;
    }
    
    void Engine::run(void) {
        while (!WindowShouldClose()) {
            game->update((double)GetFrameTime());
    
            BeginDrawing();
            ClearBackground(BLACK);
    
            game->draw();
    
            DrawFPS(8, 8);
    
            EndDrawing();
        }
    }
    
    void Engine::switchScene(Object* scene, bool destroyLast) {
        Object* lastScene = game->getScene();
        game->setScene(scene);
    
        if (destroyLast && lastScene != nullptr) {
            delete lastScene;
        }
    
        assets->clean();
    }
}