#include "assetsManager.hpp"

bool AssetsManager::init() {
    if (!_mainFont.loadFromFile("./assets/fonts/FreeMono.otf")) {
        return false;
    }
    if (!_titleTexture.loadFromFile("./assets/images/title_screen.png")) {
        return false;
    }
    return true;
}

sf::Font& AssetsManager::mainFont() {
    return _mainFont;
}

sf::Texture& AssetsManager::titleTexture() {
    return _titleTexture;
}