#include "game.hpp"
#include "./core/managers/gameStateManager.hpp"
#include "./gameStates/inGameState.hpp"

bool Game::init() {

}

void Game::run() {
    GameStateManager::getInstance().addScreen(std::make_unique<InGameState>());

    _looping = true;
    while (_looping) {
        double deltaTime = 0.01f; // TODO: get delta time
        if (!GameStateManager::getInstance().update(deltaTime)) {
            _looping = false;
        }
        if (!GameStateManager::getInstance().render(deltaTime)) {
            _looping = false;
        }
    }
}