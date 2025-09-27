#include "engine/engine.hpp"
#include "funkin/test_scene.hpp"

int main(int argc, char *argv[]) {
    Engine engine(1280, 720, "Friday Night Funkin'");
    engine.get_game()->setScene(new TestScene());
    engine.run();
    return 0;
}
