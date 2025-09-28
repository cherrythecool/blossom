#ifndef BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER
#define BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER

namespace Blossom {
    struct Vector2 {
        double x, y;
    };

    struct Vector3 {
        double x, y, z;
    };

    struct Vector4 {
        double x, y, z, w;
        void scaleToRGBA(void);
    };
}

#endif // !BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER