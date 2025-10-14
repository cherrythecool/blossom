#include "engine/game/sound_player.hpp"
#include "engine/assets/assets.hpp"
#include "engine/game/object.hpp"
#include "raylib.h"

namespace Blossom {
    SoundPlayer::SoundPlayer(const char *initialSoundPath, bool loadStreamed) {
        loadSound(initialSoundPath, loadStreamed);
    }

    SoundPlayer::~SoundPlayer() {
        if (!isValid) {
            return;
        }

        if (isStreamed()) {
            UnloadMusicStream(music);
        } else {
            stop();
            Assets::instance->dereferenceSound(audioPath);
        }
    }

    void SoundPlayer::event(ObjectEvent event) {
        if (event.type == Update) {
            updateStream();
        }
    }

    void SoundPlayer::updateStream(void) {
        if ((!isValid) || (!isStreamed())) {
            return;
        }

        UpdateMusicStream(music);
    }

    void SoundPlayer::loadSound(const char *initialSoundPath, bool loadStreamed) {
        if (initialSoundPath == nullptr) {
            return;
        }

        if (isValid) {
            if (useMusic) {
                UnloadMusicStream(music);
            } else {
                Assets::instance->dereferenceSound(audioPath);
            }

            stop();
        }

        audioPath = (char*)initialSoundPath;
        useMusic = loadStreamed;
        if (loadStreamed) {
            std::string path = Assets::instance->getFullPath(initialSoundPath);
            music = LoadMusicStream(path.c_str());
            isValid = IsMusicValid(music);

            if (isValid) {
                SetMusicVolume(music, (float)volume);
                SetMusicPitch(music, (float)pitch);
            }
        } else {
            sound = Assets::instance->getSound(initialSoundPath);
            isValid = IsSoundValid(sound);

            if (isValid) {
                sound = LoadSoundAlias(sound);
                SetSoundVolume(sound, (float)volume);
                SetSoundPitch(sound, (float)pitch);
            }
        }
    }

    bool SoundPlayer::isStreamed(void) {
        return useMusic;
    }

    void SoundPlayer::play(void) {
        if (!isValid) {
            return;
        }

        if (isStreamed()) {
            PlayMusicStream(music);
        } else {
            PlaySound(sound);
        }
    }

    void SoundPlayer::stop(void) {
        if (!isValid) {
            return;
        }

        if (isStreamed()) {
            StopMusicStream(music);
        } else {
            StopSound(sound);
        }
    }

    void SoundPlayer::pause(void) {
        if (!isValid) {
            return;
        }

        if (isStreamed()) {
            PauseMusicStream(music);
        } else {
            PauseSound(sound);
        }
    }

    bool SoundPlayer::isPlaying(void) {
        if (!isValid) {
            return false;
        }

        if (isStreamed()) {
            return IsMusicStreamPlaying(music);
        }

        return IsSoundPlaying(sound);
    }

    double SoundPlayer::getVolume(void) {
        return volume;
    }

    void SoundPlayer::setVolume(double _volume) {
        volume = _volume;
    }

    double SoundPlayer::getPitch(void) {
        return pitch;
    }

    void SoundPlayer::setPitch(double _pitch) {
        pitch = _pitch;
    }

    double SoundPlayer::getTime(void) {
        if (isValid && isStreamed()) {
            return GetMusicTimePlayed(music);
        }

        return 0.0;
    }

    void SoundPlayer::setTime(double time) {
        if (isValid && isStreamed()) {
            SeekMusicStream(music, (float)time);
        }
    }
} // namespace Blossom
