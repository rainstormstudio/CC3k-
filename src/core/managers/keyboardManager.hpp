/**
 * @file keyboardManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines a keyboard manager
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef KEYBOARDMANAGER_HPP
#define KEYBOARDMANAGER_HPP

#include <SFML/Window/Keyboard.hpp>

class KeyboardManager {
private:
    KeyboardManager() {}
public:
    KeyboardManager(KeyboardManager const&) = delete;
    void operator=(KeyboardManager const&) = delete;

    static KeyboardManager& getInstance() {
        static KeyboardManager instance;
        return instance;
    }

    bool init();

    bool keyPressed(sf::Keyboard::Key key);
};

#endif
