/**
 * @file types.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines some types
 * @version 0.1
 * @date 2021-05-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef TYPES_HPP
#define TYPES_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Vector3.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>

#define IntRect sf::IntRect

#define Vec3 sf::Vector3
#define Vec3f sf::Vector3f
#define Vec3i sf::Vector3i

#define Vec2 sf::Vector2
#define Vec2f sf::Vector2f
#define Vec2i sf::Vector2i
#define Vec2u sf::Vector2u


enum FloorType {
    EMPTY,
    FLOOR,
    TUNNEL,
    WALL_H,
    WALL_V,
    WALL_TL,    // top left corner
    WALL_TR,    // top right corner
    WALL_BL,    // bottom left corner
    WALL_BR,    // bottom right corner
    OPEN_DOOR_H,
    OPEN_DOOR_V,
    CLOSED_DOOR_H,
    CLOSED_DOOR_V,
    SIZE
};

#define Map std::vector<std::vector<FloorType>>

#endif
