#include "windowManager.hpp"

bool WindowManager::isWindowOpen() {
    return _window->isOpen();
}

bool WindowManager::pollEvent() {
    return _window->pollEvent(_event);
}

sf::Event& WindowManager::getEvent() {
    return _event;
}

void WindowManager::init() {
    _window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(800, 600),
        "CC3k+"
    );
}

void WindowManager::clear() {
    _window->clear();
}

void WindowManager::render() {
    _window->display();
}

void WindowManager::closeWindow() {
    _window->close();
}