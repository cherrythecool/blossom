#ifndef BLOSSOM_ENGINE_HEADER
#define BLOSSOM_ENGINE_HEADER

#include "engine/game/game.hpp"

class Engine {
    private:
        Game* game;

    public:
        Engine(int gameWidth, int gameHeight, const char* windowTitle);
        ~Engine();

        void run(void);
};

#endif // !BLOSSOM_ENGINE_HEADER
