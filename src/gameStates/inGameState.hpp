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

#include <memory>

#include "../core/managers/gameStateManager.hpp"

#include "../systems/cameraUpdateSystem.hpp"
#include "../systems/floorUpdateSystem.hpp"
#include "../systems/floorRenderSystem.hpp"

class InGameState : public GameState {
private:
    std::shared_ptr<CameraUpdateSystem> _cameraUpdateSystem;
    std::shared_ptr<FloorUpdateSystem> _floorUpdateSystem;
    std::shared_ptr<FloorRenderSystem> _floorRenderSystem;
public:
    void init() override;
    bool update(float deltaTime) override;
};

#endif
