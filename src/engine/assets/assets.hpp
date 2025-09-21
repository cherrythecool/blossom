#ifndef BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER
#define BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER

#include <map>
#include <string>

#include "raylib.h"

class Assets {
    private:
        std::string rootPath;
        std::map<std::string, Texture2D> textures;
        std::map<std::string, size_t> textureReferences;

        std::string getFullPath(const char* path);

    public: 
        static Assets* instance;

        Assets();
        ~Assets();

        void clean(void);
        void setRootPath(const char* path);

        Texture2D getTexture(const char* path);
        void dereferenceTexture(const char* path);
        void unloadTexture(const char* path);
};

#endif // !BLOSSOM_ENGINE_ASSETS_ASSETS_HEADER