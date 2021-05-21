/**
 * @file inGameState.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the in-game state
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef INGAMESTATE_HPP
#define INGAMESTATE_HPP

#include "../core/managers/gameStateManager.hpp"
#include "../core/ecs/ecs.hpp"

class InGameState : public GameState {
private:
    Ecs _world;

public:
    void init() override;
    bool update(double deltaTime) override;
    bool render(double deltaTime) override;
};

#endif
