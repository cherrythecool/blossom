#include "engine/string.hpp"

#include <string.h>

namespace Blossom {
    namespace Strings {
        bool startsWith(const char* string, const char* prefix) {
            if (strlen(prefix) > strlen(string)) {
                return false;
            }
    
            return strncmp(string, prefix, strlen(prefix)) == 0;
        }
    
        bool startsWith(std::string string, std::string prefix) {
            return startsWith(string.c_str(), prefix.c_str());
        }
    }
}