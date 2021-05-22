#include "game.hpp"
#include "./core/managers/gameStateManager.hpp"
#include "./core/managers/assetsManager.hpp"
#include "./core/managers/windowManager.hpp"
#include "./gameStates/titleState.hpp"

bool Game::init() {
    if (!AssetsManager::getInstance().init()) {
        return false;
    }
    WindowManager::getInstance().init();
    return true;
}

void Game::run() {
    GameStateManager::getInstance().addScreen(std::make_shared<TitleState>());

    _looping = true;
    while (WindowManager::getInstance().isWindowOpen() && _looping) {
        float deltaTime = WindowManager::getInstance().getDeltaTime();

        while (WindowManager::getInstance().pollEvent()) {
            if (WindowManager::getInstance().getEvent().type == sf::Event::Closed) {
                _looping = false;
                WindowManager::getInstance().closeWindow();
            }
        }

        if (!GameStateManager::getInstance().update(deltaTime)) {
            _looping = false;
        }
    }
}