/**
 * @file entity.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the Entity type
 * @version 0.1
 * @date 2021-05-21
 * @ref https://austinmorlan.com/posts/entity_component_system/
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <cstdint>

using Entity = std::uint32_t;
const Entity MAX_ENTITIES = 10000;

#endif
