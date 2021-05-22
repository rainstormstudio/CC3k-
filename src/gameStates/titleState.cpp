#include "titleState.hpp"
#include "../core/managers/windowManager.hpp"
#include "../core/managers/assetsManager.hpp"

void TitleState::init() {

}

bool TitleState::update(float deltaTime) {
    WindowManager::getInstance().clear();
    WindowManager::getInstance().draw(
        AssetsManager::getInstance().titleTexture(),
        0.0f,
        0.0f,
        2.0f
    );
    WindowManager::getInstance().render();
    return true;
}