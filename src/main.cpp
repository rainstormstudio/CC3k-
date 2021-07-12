#include "game.hpp"

int main() {
    Game game{};

    if (game.init()) {
        game.run();
    }

    return 0;
}
