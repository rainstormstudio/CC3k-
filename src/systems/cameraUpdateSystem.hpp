/**
 * @file cameraUpdateSystem.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines how to update the camera
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef CAMERAUPDATESYSTEM_HPP
#define CAMERAUPDATESYSTEM_HPP

#include "../core/ecs/entity.hpp"
#include "../core/ecs/system.hpp"

class CameraUpdateSystem : public System {
public:
    void init();
    void update(float deltaTime);
};

#endif

