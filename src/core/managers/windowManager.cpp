#include "windowManager.hpp"
#include "configsManager.hpp"
#include "assetsManager.hpp"
#include <iostream>

#include "../types.hpp"

bool WindowManager::isWindowOpen() {
    return _window->isOpen();
}

bool WindowManager::pollEvent() {
    return _window->pollEvent(_event);
}

sf::Event& WindowManager::getEvent() {
    return _event;
}

float WindowManager::getDeltaTime() {
    sf::Time time = _clock.getElapsedTime();
    _clock.restart();
    return time.asSeconds();
}

void WindowManager::setView(sf::View view) {
    _window->setView(view);
}

sf::View WindowManager::defaultView() const {
    return _window->getDefaultView();
}

bool WindowManager::init() {
    if (!sf::Shader::isAvailable()) {
        std::cerr << "Shaders are not available in this machine." << std::endl;
        return false;
    }
    _window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(
            ConfigsManager::getInstance().screenWidth(), 
            ConfigsManager::getInstance().screenHeight()),
        "CC3k+",
        sf::Style::Titlebar | sf::Style::Close
    );
    //_window->setFramerateLimit(60);
    _window->setVerticalSyncEnabled(ConfigsManager::getInstance().verticalSync());
    _window->setPosition(Vec2i(0.0f, 0.0f));

    return true;
}

void WindowManager::clear() {
    _window->clear();
}

void WindowManager::render() {
    _window->display();
}

void WindowManager::draw(sf::Texture texture, float x, float y, float scale) {
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(scale, scale);
    _window->draw(sprite);
}

void WindowManager::drawSprite(sf::Sprite& sprite, IntRect region, float x, float y, float scale) {
    sprite.setTextureRect(region);
    sprite.setPosition(x, y);
    sprite.setScale(scale, scale);
    _window->draw(sprite);
}

void WindowManager::sDraw(sf::Texture texture, const sf::Shader& shader, float x, float y, float scale) {
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(x, y);
    sprite.setScale(scale, scale);
    _window->draw(sprite, &shader);
}

void WindowManager::write(std::string content, float x, float y, sf::Color color, unsigned int fontSize) {
    sf::Text text;
    text.setFont(AssetsManager::getInstance().mainFont());
    text.setString(content);
    text.setCharacterSize(fontSize);
    text.setPosition(x, y);
    text.setFillColor(color);
    _window->draw(text);
}

void WindowManager::writeF(std::string content, sf::Font& font, float x, float y, sf::Color color, unsigned int fontSize) {
    sf::Text text;
    text.setFont(font);
    text.setString(content);
    text.setCharacterSize(fontSize);
    text.setPosition(x, y);
    text.setFillColor(color);
    _window->draw(text);
}

void WindowManager::closeWindow() {
    _window->close();
}