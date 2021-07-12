#include "game.hpp"
#include "./core/managers/configsManager.hpp"
#include "./core/managers/assetsManager.hpp"
#include "./core/managers/windowManager.hpp"
#include "./core/managers/keyboardManager.hpp"
#include "./core/managers/gameStateManager.hpp"
#include "./gameStates/titleState.hpp"
#include "./utilities/utilities.hpp"
#include <iostream>

bool Game::init() {
    if (!ConfigsManager::getInstance().init("./configs/gameSettings.cfg")) {
        return false;
    }
    if (!AssetsManager::getInstance().init()) {
        return false;
    }
    if (!WindowManager::getInstance().init()) {
        return false;
    }
    if (!KeyboardManager::getInstance().init()) {
        return false;
    }

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
