#ifndef BLOSSOM_ENGINE_GAME_OBJECT_HEADER
#define BLOSSOM_ENGINE_GAME_OBJECT_HEADER

#include <vector>

namespace Blossom {
    enum ObjectEventType {
        Ready = 0,
        Update,
        Draw,
    };

    struct ObjectEvent {
        ObjectEventType type;
        void* data;
    };

    class Object {
        public:
            std::vector<Object*> children;
    
            Object();
            virtual ~Object();
    
            virtual void append(Object* child);
            virtual void erase(Object* child);
            virtual Object* popBack(void);
    
            virtual void event(ObjectEvent event);
    };
}

#endif // !BLOSSOM_ENGINE_GAME_OBJECT_HEADER