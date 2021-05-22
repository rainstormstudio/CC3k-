#include "assetsManager.hpp"
#include "configsManager.hpp"

bool AssetsManager::init() {
    if (!_mainFont.loadFromFile(ConfigsManager::getInstance().mainFontPath())) {
        return false;
    }
    if (!_titleTexture.loadFromFile(ConfigsManager::getInstance().titleImagePath())) {
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