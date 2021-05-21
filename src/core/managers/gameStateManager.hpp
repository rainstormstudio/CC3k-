/**
 * @file gameStateManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the game state manager
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef GAMESTATEMANAGER_HPP
#define GAMESTATEMANAGER_HPP

#include <memory>
#include <stack>

class GameState {
public:
    virtual void init();
    virtual bool update(double deltaTime);
    virtual bool render(double deltaTime);
};

class GameStateManager {
private:
    std::stack<std::unique_ptr<GameState>> _screens;

    GameStateManager();
public:
    GameStateManager(GameStateManager const&) = delete;
    void operator=(GameStateManager const&) = delete;

    static GameStateManager& getInstance() {
        static GameStateManager instance;
        return instance;
    }

    void addScreen(std::unique_ptr<GameState> screen);
    void popScreen();
    void clearScreens();
    bool update(double deltaTime);
    bool render(double deltaTime);
};

#endif
