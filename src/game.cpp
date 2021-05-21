#include "game.hpp"
#include "./core/managers/gameStateManager.hpp"
#include "./core/managers/windowManager.hpp"
#include "./gameStates/inGameState.hpp"

bool Game::init() {
    WindowManager::getInstance().init();
    return true;
}

void Game::run() {
    GameStateManager::getInstance().addScreen(std::make_shared<InGameState>());

    _looping = true;
    while (WindowManager::getInstance().isWindowOpen() && _looping) {
        double deltaTime = 0.01f; // TODO: get delta time

        while (WindowManager::getInstance().pollEvent()) {
            if (WindowManager::getInstance().getEvent().type == sf::Event::Closed) {
                _looping = false;
                WindowManager::getInstance().closeWindow();
            }
        }

        if (!GameStateManager::getInstance().update(deltaTime)) {
            _looping = false;
        }

        WindowManager::getInstance().clear();
        if (!GameStateManager::getInstance().render(deltaTime)) {
            _looping = false;
        }
        WindowManager::getInstance().render();
    }
}