#ifndef BLOSSOM_ENGINE_HEADER
#define BLOSSOM_ENGINE_HEADER

#include "engine/game/game.hpp"
#include "engine/assets/assets.hpp"

class Engine {
    private:
        Game* game;
        Assets* assets;

    public:
        static Engine* instance;

        Engine(int gameWidth, int gameHeight, const char* windowTitle);
        ~Engine();

        Game* getGame(void);
        void run(void);

        void switchScene(Object* scene, bool destroyLast = true);
};

#endif // !BLOSSOM_ENGINE_HEADER
