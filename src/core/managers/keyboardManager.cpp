#include "keyboardManager.hpp"

bool KeyboardManager::init() {
    return true;
}

bool KeyboardManager::keyPressed(sf::Keyboard::Key key) {
    return sf::Keyboard::isKeyPressed(key);
}