/**
 * @file assetsManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines an assets manager
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ASSETSMANAGER_HPP
#define ASSETSMANAGER_HPP

#include <SFML/Graphics.hpp>

class AssetsManager {
private:
    sf::Font _mainFont;
    sf::Texture _titleTexture;

    AssetsManager() {}

public:
    AssetsManager(AssetsManager const&) = delete;
    void operator=(AssetsManager const&) = delete;

    static AssetsManager& getInstance() {
        static AssetsManager instance;
        return instance;
    }

    bool init();

    sf::Font& mainFont();
    sf::Texture& titleTexture();
};

#endif
