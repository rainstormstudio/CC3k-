/**
 * @file BSPtree.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines a BSP tree for generating dungeons
 * @version 0.1
 * @date 2021-05-23
 * 
 * @ref https://github.com/AtTheMatinee/dungeon-generation/blob/master/dungeonGenerationAlgorithms.py
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BSPTREE_HPP
#define BSPTREE_HPP

#include <vector>
#include <memory>

#include "../core/types.hpp"
#include "BSPnode.hpp"

const int MAX_NODE_SIZE = 24;
const int MIN_NODE_SIZE = 10;
const int MAX_ROOM_SIZE = 16;
const int MIN_ROOM_SIZE = 6;

class BSPTree {

private:
    Map _floor;
    std::shared_ptr<IntRect> _room;
    std::vector<std::shared_ptr<BSPNode>> _nodes;

public:
    BSPTree() {
        _room = nullptr;
    }

    void generate(Map& floor, int mapWidth, int mapHeight);
    void createRoom(std::shared_ptr<IntRect> room);
    void createHall(std::shared_ptr<IntRect> room1, std::shared_ptr<IntRect> room2);
    void createHTunnel(int x1, int x2, int y);
    void createVTunnel(int y1, int y2, int x);
};

#endif
