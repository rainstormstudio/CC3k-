/**
 * @file component.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the Component type
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdint>
#include <bitset>

using ComponentType = std::uint8_t;
const ComponentType MAX_COMPONENTS = 64;

// component signatures of systems
using Signature = std::bitset<MAX_COMPONENTS>;

#endif
