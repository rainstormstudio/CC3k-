/**
 * @file floor.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the floor component
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef FLOOR_HPP
#define FLOOR_HPP

#include <vector>

#include "../core/types.hpp"
#include "../utilities/BSPtree.hpp"

struct Floor {
    Map data;
    bool active = false;

    static void generate(Floor& floor, int mapWidth, int mapHeight) {
        BSPTree bsp{};
        floor.data = Map(mapHeight);
        for (int i = 0; i < mapHeight; i ++) {
            floor.data[i] = std::vector<FloorType>(mapWidth);
            for (int j = 0; j < mapWidth; j ++) {
                floor.data[i][j] = EMPTY;
            }
        }
        bsp.generate(floor.data, mapWidth, mapHeight);
        floor.active = true;
    }
};

#endif
