#ifndef BLOSSOM_ENGINE_GAME_GAME_HEADER
#define BLOSSOM_ENGINE_GAME_GAME_HEADER

#include <vector>

#include "engine/game/object.hpp"

class Game {
    private:
        Object* scene = nullptr;
        double lastElapsedSeconds = 0.0;

    public:
        Game();
        ~Game();

        void setScene(Object* scene);
        Object* getScene(void);
        bool empty(void);
        double getLastElapsed(void);

        void update(double elapsedSeconds);
        void draw(void);
};

#endif // !BLOSSOM_ENGINE_GAME_HEADER
