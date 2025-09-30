#ifndef BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER
#define BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER

#include "engine/game/object.hpp"

#include "raylib.h"

namespace Blossom {
    class SoundPlayer : public Object {
        private:
            Sound sound;
            Music music;

        public:
            SoundPlayer();
            virtual ~SoundPlayer();

            
    };
}

#endif // !BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER