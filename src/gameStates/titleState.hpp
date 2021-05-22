/**
 * @file titleState.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the game state of title screen
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TITLESTATE_HPP
#define TITLESTATE_HPP

#include "../core/managers/gameStateManager.hpp"

class TitleState : public GameState {
public:
    void init() override;
    bool update(float deltaTime) override;
};

#endif
