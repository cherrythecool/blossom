#ifndef BLOSSOM_ENGINE_HEADER
#define BLOSSOM_ENGINE_HEADER

#include "engine/game/game.hpp"
#include "engine/assets/assets.hpp"

class Engine {
    private:
        Game* game;
        Assets* assets;

    public:
        Engine(int gameWidth, int gameHeight, const char* windowTitle);
        ~Engine();

        void run(void);
};

#endif // !BLOSSOM_ENGINE_HEADER
