/**
 * @file floorUpdateSystem.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines how to update floor system
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef FLOORUPDATESYSTEM_HPP
#define FLOORUPDATESYSTEM_HPP

#include "../core/ecs/entity.hpp"
#include "../core/ecs/system.hpp"

class FloorUpdateSystem : public System {
public:
    void init();
    void update(float deltaTime);
};

#endif
