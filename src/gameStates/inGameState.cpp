#include "inGameState.hpp"

void InGameState::init() {
    _world.init();
    //_world.registerSystem()
}

bool InGameState::update(double deltaTime) {
    return true;
}

bool InGameState::render(double deltaTime) {
    return true;
}