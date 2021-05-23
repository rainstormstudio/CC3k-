#include "assetsManager.hpp"
#include "configsManager.hpp"

#include <iostream>

bool AssetsManager::init() {
    if (!_mainFont.loadFromFile(ConfigsManager::getInstance().mainFontPath())) {
        std::cerr << "Failed to load main font at " 
            << ConfigsManager::getInstance().mainFontPath() << std::endl;
        return false;
    }
    if (!_monoFont.loadFromFile(ConfigsManager::getInstance().monoFontPath())) {
        std::cerr << "Failed to load mono font at "
            << ConfigsManager::getInstance().monoFontPath() << std::endl;
        return false;
    }
    if (!_whiteTexture.loadFromFile(ConfigsManager::getInstance().whiteTexturePath())) {
        std::cerr << "Failed to load white texture at "
            << ConfigsManager::getInstance().whiteTexturePath() << std::endl;
        return false;
    }
    if (!_titleTexture.loadFromFile(ConfigsManager::getInstance().titleImagePath())) {
        std::cerr << "Failed to load title image at " 
            << ConfigsManager::getInstance().mainFontPath() << std::endl;
        return false;
    }
    if (!_titleShader.loadFromFile(ConfigsManager::getInstance().titleVShaderPath(), sf::Shader::Vertex)) {
        std::cerr << "Failed to load title vertex shader at "
            << ConfigsManager::getInstance().titleVShaderPath() << std::endl;
        return false;
    }
    if (!_titleShader.loadFromFile(ConfigsManager::getInstance().titleFShaderPath(), sf::Shader::Fragment)) {
        std::cerr << "Failed to load title fragment shader at"
            << ConfigsManager::getInstance().titleFShaderPath() << std::endl;
        return false;
    }
    return true;
}

sf::Font& AssetsManager::mainFont() {
    return _mainFont;
}

sf::Font& AssetsManager::monoFont() {
    return _monoFont;
}

sf::Texture& AssetsManager::whiteTexture() {
    return _whiteTexture;
}

sf::Texture& AssetsManager::titleTexture() {
    return _titleTexture;
}

sf::Shader& AssetsManager::titleShader() {
    return _titleShader;
}