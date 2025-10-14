#include "engine/engine.hpp"
#include "funkin/test_scene.hpp"

int main(void) {
    Blossom::Engine engine(1280, 720, "Friday Night Funkin'");
    engine.getGame()->setScene(new TestScene());
    engine.run();
    return 0;
}
