/**
 * @file system.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the system
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include "entity.hpp"
#include "component.hpp"

#include <set>

class System {
public:
    std::set<Entity> entities;
};

#endif
