#include "engine/game/animation/animation_data.hpp"

#include <cstdio>
#include <stdlib.h>
#include <string.h>

#include "engine/graphics/vectors.hpp"
#include "tinyxml2.h"

AnimationData AnimationData::loadFromSparrow(const char* path) {
    AnimationData data;

    tinyxml2::XMLDocument document;
    document.LoadFile(path);

    if (document.Error()) {
        fprintf(stderr, "Error loading animation data from sparrow file: %s\n", path);
        return data;
    }

    tinyxml2::XMLNode* rootNode = document.FirstChild();
    if (rootNode == nullptr) {
        return data;
    }

    tinyxml2::XMLDeclaration* declaration = rootNode->ToDeclaration();
    if (declaration != nullptr) {
        rootNode = rootNode->NextSibling();

        if (rootNode == nullptr) {
            fprintf(stderr, "Sparrow atlas only contains XML version declaration: %s\n", path);
            return data;
        }
    }

    tinyxml2::XMLElement* rootElement = rootNode->ToElement();
    if (rootElement == nullptr) {
        return data;
    }

    if (strcmp(rootElement->Name(), "TextureAtlas") != 0) {
        return data;
    }

    data.framesCount = rootElement->ChildElementCount();
    data.frames = new AnimationFrame[data.framesCount];

    size_t frameIndex = 0;
    tinyxml2::XMLNode* animationIterator = rootElement->FirstChild();
    while (animationIterator != nullptr) {
        tinyxml2::XMLElement* animationElement = animationIterator->ToElement();
        if (animationElement != nullptr) {
            const char* name = animationElement->Attribute("name");
            const char* xStr = animationElement->Attribute("x");
            const char* yStr = animationElement->Attribute("y");
            const char* widthStr = animationElement->Attribute("width");
            const char* heightStr = animationElement->Attribute("height");
            const char* frameXStr = animationElement->Attribute("frameX");
            const char* frameYStr = animationElement->Attribute("frameY");
            const char* frameWidthStr = animationElement->Attribute("frameWidth");
            const char* frameHeightStr = animationElement->Attribute("frameHeight");
            const char* rotatedStr = animationElement->Attribute("rotated");

            if (name != nullptr && xStr != nullptr && yStr != nullptr && widthStr != nullptr && heightStr != nullptr) {
                AnimationFrame frame;
                frame.name = std::string(name);
                frame.region = {
                    atof(xStr),
                    atof(yStr),
                    atof(widthStr),
                    atof(heightStr)
                };

                if (frameXStr != nullptr && frameYStr != nullptr) {
                    frame.offset = {
                        atof(frameXStr),
                        atof(frameYStr)
                    };
                } else {
                    frame.offset = {
                        0.0,
                        0.0
                    };
                }

                if (frameWidthStr != nullptr && frameHeightStr != nullptr) {
                    frame.boundingBox = {
                        atof(frameWidthStr),
                        atof(frameHeightStr)
                    };
                } else {
                    frame.boundingBox = {
                        frame.region.z,
                        frame.region.w
                    };
                }

                if (rotatedStr != nullptr && strcmp(rotatedStr, "true") == 0) {
                    frame.rotation = RotationNinety;
                } else {
                    frame.rotation = RotationNone;
                }

                data.frames[frameIndex] = frame;
            }
        }

        animationIterator = animationIterator->NextSibling();
        frameIndex++;
    }

    return data;
}
