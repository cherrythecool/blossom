#ifndef BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER
#define BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER

#include "engine/game/object.hpp"

#include "raylib.h"

namespace Blossom {
    class SoundPlayer : public Object {
        private:
            Sound sound;
            Music music;
            char *audioPath = nullptr;
            bool useMusic = true;
            bool isValid = false;
            double volume = 1.0;
            double pitch = 1.0;

        public:
            SoundPlayer(const char* initialSoundPath = nullptr, bool loadStreamed = false);
            virtual ~SoundPlayer();

            virtual void event(ObjectEvent event);
            virtual void updateStream(void);
            virtual void loadSound(const char* initialSoundPath = nullptr, bool loadStreamed = false);
            virtual bool isStreamed(void);

            virtual void play(void);
            virtual void stop(void);
            virtual void pause(void);
            virtual bool isPlaying(void);

            virtual double getVolume(void);
            virtual void setVolume(double volume);

            virtual double getPitch(void);
            virtual void setPitch(double pitch);

            // WARNING: Only available on streamed audio! (raudio limitation)
            virtual double getTime(void);

            // WARNING: Only available on streamed audio! (raudio limitation)
            virtual void setTime(double time);
    };
}

#endif // !BLOSSOM_ENGINE_GAME_SOUND_PLAYER_HEADER
