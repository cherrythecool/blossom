#ifndef BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER
#define BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER

namespace GFX {
    struct Vector2 {
        double x, y;

        void set(double x, double y);
        void add(Vector2 vector);
        void subtract(Vector2 vector);
        void multiply(Vector2 vector);
        void divide(Vector2 vector);
        void scale(double factor);
    };

    struct Vector3 {
        double x, y, z;

        void set(double x, double y, double z);
        void add(Vector3 vector);
        void subtract(Vector3 vector);
        void multiply(Vector3 vector);
        void divide(Vector3 vector);
        void scale(double factor);
    };

    struct Vector4 {
        double x, y, z, w;

        void set(double x, double y, double z, double w);
        void add(Vector4 vector);
        void subtract(Vector4 vector);
        void multiply(Vector4 vector);
        void divide(Vector4 vector);
        void scale(double factor);
        void scaleToRGBA(void);
    };
}

#endif // !BLOSSOM_ENGINE_GRAPHICS_VECTORS_HEADER