#include "titleState.hpp"
#include "../core/managers/windowManager.hpp"
#include "../core/managers/configsManager.hpp"
#include "../core/managers/assetsManager.hpp"
#include "../core/managers/keyboardManager.hpp"
#include "../core/types.hpp"
#include "../gameStates/inGameState.hpp"

#include <iostream>

void TitleState::init() {

}

bool TitleState::update(float deltaTime) {
    static float t = 0.0f;
    t += deltaTime;
    if (t > 2 * 3.1415926f) {
        t = 0.0f;
    }
    AssetsManager::getInstance().titleShader().setUniform("t", t);
    AssetsManager::getInstance().titleShader().setUniform("screenWidth", ConfigsManager::getInstance().screenWidth());
    AssetsManager::getInstance().titleShader().setUniform("screenHeight", ConfigsManager::getInstance().screenHeight());

    WindowManager::getInstance().clear();
    if (KeyboardManager::getInstance().keyPressed(sf::Keyboard::Return)) {
        GameStateManager::getInstance().addScreen(std::make_shared<InGameState>());
    }
    WindowManager::getInstance().sDraw(
        AssetsManager::getInstance().whiteTexture(),
        AssetsManager::getInstance().titleShader(),
        0.0f,
        0.0f,
        2.0f
    );
    WindowManager::getInstance().draw(
        AssetsManager::getInstance().titleTexture(),
        0.0f,
        0.0f,
        2.0f
    );
    Vec2f infoPos(60.0f, 440.0f);
    sf::Color infoColor(200, 150, 70);
    WindowManager::getInstance().write("VERSION " + ConfigsManager::getInstance().version(), infoPos.x, infoPos.y, infoColor);
    WindowManager::getInstance().write("by " + ConfigsManager::getInstance().author(), infoPos.x, infoPos.y + 20.0f, infoColor);
    WindowManager::getInstance().write("(" + ConfigsManager::getInstance().authorEmail() + ")", infoPos.x, infoPos.y + 40.0f, infoColor);
    WindowManager::getInstance().write(ConfigsManager::getInstance().copyRight(), infoPos.x, infoPos.y + 60.0f, infoColor);

    WindowManager::getInstance().write("PRESS ENTER", 344.0f, 340.0f, sf::Color::White, 24);

    WindowManager::getInstance().render();
    return true;
}