/**
 * @file floorRenderSystem.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the rendering system of floor (map)
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef FLOORRENDERSYSTEM_HPP
#define FLOORRENDERSYSTEM_HPP

#include "../core/ecs/entity.hpp"
#include "../core/ecs/system.hpp"

class FloorRenderSystem : public System {
private:
    Entity _cameraEntity;
public:
    void init(Entity cameraEntity);
    void update(float deltaTime);
};

#endif
