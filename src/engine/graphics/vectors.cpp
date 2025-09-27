#include "engine/graphics/vectors.hpp"
#include "engine/graphics/math.hpp"

namespace GFX {
    void Vector2::set(double _x, double _y) {
        x = _x;
        y = _y;
    }

    void Vector2::add(Vector2 vector) {
        x += vector.x;
        y += vector.y;
    }

    void Vector2::subtract(Vector2 vector) {
        x -= vector.x;
        y -= vector.y;
    }

    void Vector2::multiply(Vector2 vector) {
        x *= vector.x;
        y *= vector.y;
    }

    void Vector2::divide(Vector2 vector) {
        x /= vector.x;
        y /= vector.y;
    }

    void Vector2::scale(double factor) {
        x *= factor;
        y *= factor;
    }

    void Vector3::set(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }

    void Vector3::add(Vector3 vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
    }

    void Vector3::subtract(Vector3 vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
    }

    void Vector3::multiply(Vector3 vector) {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
    }

    void Vector3::divide(Vector3 vector) {
        x /= vector.x;
        y /= vector.y;
        z /= vector.z;
    }

    void Vector3::scale(double factor) {
        x *= factor;
        y *= factor;
        z *= factor;
    }

    void Vector4::set(double _x, double _y, double _z, double _w) {
        x = _x;
        y = _y;
        z = _z;
        w = _w;
    }

    void Vector4::add(Vector4 vector) {
        x += vector.x;
        y += vector.y;
        z += vector.z;
        w += vector.w;
    }

    void Vector4::subtract(Vector4 vector) {
        x -= vector.x;
        y -= vector.y;
        z -= vector.z;
        w -= vector.w;
    }

    void Vector4::multiply(Vector4 vector) {
        x *= vector.x;
        y *= vector.y;
        z *= vector.z;
        w *= vector.w;
    }

    void Vector4::divide(Vector4 vector) {
        x /= vector.x;
        y /= vector.y;
        z /= vector.z;
        w /= vector.w;
    }

    void Vector4::scale(double factor) {
        x *= factor;
        y *= factor;
        z *= factor;
        w *= factor;
    }

    void Vector4::scaleToRGBA(void) {
        x = clamp(x * 255.0, 0.0, 255.0);
        y = clamp(y * 255.0, 0.0, 255.0);
        z = clamp(z * 255.0, 0.0, 255.0);
        w = clamp(w * 255.0, 0.0, 255.0);
    }
}