#include "engine/assets/assets.hpp"

#include <iostream>

Assets* Assets::instance;

Assets::Assets() {
    instance = this;
    setRootPath("assets");
}

Assets::~Assets() {
    for (auto& texture : textures) {
        UnloadTexture(texture.second);
    }

    if (instance == this) {
        instance = nullptr;
    }
}

void Assets::clean(void) {
    std::map<std::string, Texture2D>::iterator iterator = textures.begin();
    while (iterator != textures.end()) {
        if (textureReferences[iterator->first] == 0) {
            UnloadTexture(iterator->second);
            textureReferences.erase(iterator->first);
            iterator = textures.erase(iterator);
        } else {
            ++iterator;
        }
    }
}

std::string Assets::getFullPath(const char* path) {
    return rootPath + "/" + std::string(path);
}

void Assets::setRootPath(const char* path) {
    if (path == nullptr) {
        return;
    }

    rootPath = std::string(path);
}

Texture2D Assets::getTexture(const char* path) {
    std::string fullPath = getFullPath(path);
    if (textures.find(fullPath) == textures.end()) {
        textures[fullPath] = LoadTexture(fullPath.c_str());
    }

    textureReferences[fullPath] += 1;
    return textures[fullPath];
}

void Assets::dereferenceTexture(const char* path) {
    std::string fullPath = getFullPath(path);
    if (textureReferences.find(fullPath) != textureReferences.end()) {
        if (textureReferences[fullPath] == 0) {
            std::cerr << "WARNING: Dereferencing texture that has no references left, most likely a double dereference! Path: " << fullPath << std::endl;
        }

        textureReferences[fullPath] -= 1;
    }
}

void Assets::unloadTexture(const char* path) {
    std::string fullPath = getFullPath(path);
    if (textures.find(fullPath) != textures.end()) {
        UnloadTexture(textures[fullPath]);
        textures.erase(fullPath);
        textureReferences.erase(fullPath);
    }
}