#include "gameStateManager.hpp"

void GameStateManager::addScreen(std::shared_ptr<GameState> screen) {
    _screens.push(screen);
    _screens.top()->init();
}

void GameStateManager::popScreen() {
    if (_screens.size() > 0) {
        _screens.pop();
    }
}

void GameStateManager::clearScreens() {
    while (_screens.size() > 0) {
        _screens.pop();
    }
}

bool GameStateManager::update(float deltaTime) {
    if (_screens.size() > 0) {
        return _screens.top()->update(deltaTime);
    }
    return false;
}
