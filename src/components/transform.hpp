/**
 * @file transform.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the transform component
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include "../core/types.hpp"

struct Transform {
    Vec2f position;
    float rotation; // rotation angle in degrees
    float scale;
};

#endif
