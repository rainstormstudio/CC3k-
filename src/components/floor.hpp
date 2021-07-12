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
#include <iostream>

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

        {   // TODO: delete the following
            std::cout << "floor generated" << std::endl;
            int i = 0;
            std::string asciiTile = " .#-|1234++=:";
            for (auto& row : floor.data) {
                std::string line = "";
                for (auto& type : row) {
                    int index = static_cast<int>(type);
                    line += asciiTile[index];
                }
                std::cout << line << std::endl;
                i ++;
            }
        }
    }
};

#endif
