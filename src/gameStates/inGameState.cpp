#include "inGameState.hpp"

void InGameState::init() {
    _world.init();
    //_world.registerSystem()
}

bool InGameState::update(double deltaTime) {
    return false;
}

bool InGameState::render(double deltaTime) {
    return false;
}