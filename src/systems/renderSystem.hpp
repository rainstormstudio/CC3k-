/**
 * @file renderSystem.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the rendering system
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef RENDERSYSTEM_HPP
#define RENDERSYSTEM_HPP

#include "../core/ecs/entity.hpp"
#include "../core/ecs/system.hpp"

class RenderSystem : public System {
private:
    Entity _cameraEntity;
public:
    void init();
    void update(float deltaTime);
};

#endif
