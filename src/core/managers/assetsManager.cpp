#include "assetsManager.hpp"

bool AssetsManager::init() {
    if (!_mainFont.loadFromFile("./assets/fonts/FreeMono.otf")) {
        return false;
    }
    return true;
}

sf::Font& AssetsManager::mainFont() {
    return _mainFont;
}