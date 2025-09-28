#include "engine/graphics/vectors.hpp"
#include "engine/graphics/math.hpp"

namespace Blossom {
    void Vector4::scaleToRGBA(void) {
        x = clamp(x * 255.0, 0.0, 255.0);
        y = clamp(y * 255.0, 0.0, 255.0);
        z = clamp(z * 255.0, 0.0, 255.0);
        w = clamp(w * 255.0, 0.0, 255.0);
    }
}