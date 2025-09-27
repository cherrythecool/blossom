#include "engine/engine.hpp"

#include "raylib.h"

#if _WIN32
#include "engine/windows.hpp"
#endif // _WIN32

Engine::Engine(int gameWidth, int gameHeight, const char* windowTitle) {
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
}

Game* Engine::get_game(void) {
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
