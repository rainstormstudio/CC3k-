#include "inGameState.hpp"
#include "../core/managers/windowManager.hpp"

void InGameState::init() {
    _world.init();
    //_world.registerSystem()
}

bool InGameState::update(float deltaTime) {
    return true;
}

bool InGameState::render(float deltaTime) {
    WindowManager::getInstance().write("FPS: " + std::to_string(1.0f / deltaTime));
    return true;
}