/**
 * @file graphicsManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief this file defines the graphics manager
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef WINDOWMANAGER_HPP
#define WINDOWMANAGER_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <string>

class WindowManager {
private:
    std::unique_ptr<sf::RenderWindow> _window;
    sf::Event _event;
    sf::Clock _clock;

    WindowManager() {}
public:
    WindowManager(WindowManager const&) = delete;
    void operator=(WindowManager const&) = delete;

    static WindowManager& getInstance() {
        static WindowManager instance;
        return instance;
    }

    bool isWindowOpen();

    bool pollEvent();
    sf::Event& getEvent();

    float getDeltaTime();

    void setView(sf::View view);
    sf::View defaultView() const;

    void init();
    void clear();
    void render();

    void write(std::string content, float x = 0.0f, float y = 0.0f);

    void closeWindow();
};

#endif
