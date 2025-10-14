#ifndef BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER
#define BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER

#include <map>
#include <string>

#include "raylib.h"

#include "engine/game/animation/animation_data.hpp"

namespace Blossom {
    class Assets {
        private:
            std::map<std::string, Texture2D> textures;
            std::map<std::string, size_t> textureReferences;

            std::map<std::string, Sound> sounds;
            std::map<std::string, size_t> soundReferences;

            std::map<std::string, AnimationData> animations;
            std::map<std::string, size_t> animationReferences;

            std::string rootPath;

        public:
            static Assets* instance;

            Assets();
            ~Assets();

            void clean(void);
            void setRootPath(const char* path);
            std::string getFullPath(const char* path);

            Texture2D getTexture(const char* path);
            void dereferenceTexture(const char* path);
            void unloadTexture(const char* path);

            AnimationData getAnimation(const char* path);
            void dereferenceAnimation(const char* path);
            void unloadAnimation(const char* path);

            Sound getSound(const char* path);
            void dereferenceSound(const char* path);
            void unloadSound(const char* path);
    };
}

#endif // !BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER
