#include "engine/game/object.hpp"

#include <algorithm>

namespace Blossom {
    Object::Object() {}

    Object::~Object() {}

    void Object::append(Object* child) {
        children.push_back(child);
    }

    void Object::erase(Object* child) {
        std::vector<Object*>::iterator found = std::find(children.begin(), children.end(), child);
        if (found == children.end()) {
            return;
        }

        children.erase(found);
    }

    Object* Object::popBack(void) {
        if (children.empty()) {
            return nullptr;
        }

        Object* last = children[children.size() - 1];
        children.pop_back();
        return last;
    }

    void Object::event(ObjectEvent event) {
        for (size_t i = 0; i < children.size(); i++) {
            children[i]->event(event);
        }
    }
}