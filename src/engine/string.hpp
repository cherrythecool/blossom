#ifndef BLOSSOM_ENGINE_STRING_HEADER
#define BLOSSOM_ENGINE_STRING_HEADER

#include <string>

namespace Blossom {
    namespace Strings {
        bool startsWith(const char* string, const char* prefix);
        bool startsWith(std::string string, std::string prefix);
    }
}

#endif // !BLOSSOM_ENGINE_STRING_HEADER