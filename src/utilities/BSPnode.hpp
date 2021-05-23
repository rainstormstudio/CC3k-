/**
 * @file BSPnode.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the node of a BSP tree
 * @version 0.1
 * @date 2021-05-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef BSPNODE_HPP
#define BSPNODE_HPP

#include <memory>

#include "../core/types.hpp"

class BSPTree;

class BSPNode {
private:
    int _x;
    int _y;
    int _width;
    int _height;
    std::shared_ptr<BSPNode> _child1;
    std::shared_ptr<BSPNode> _child2;
    std::shared_ptr<IntRect> _room;

public:
    BSPNode(int x, int y, int width, int height)
        : _x{x}, _y{y}, _width{width}, _height{height},
        _child1{nullptr}, _child2{nullptr}, _room{nullptr} {}

    int width() const {
        return _width;
    }

    int height() const {
        return _height;
    }

    std::shared_ptr<BSPNode> child1() {
        return _child1;
    }

    std::shared_ptr<BSPNode> child2() {
        return _child2;
    }

    bool splitNode();
    void createRooms(BSPTree& tree);
    std::shared_ptr<IntRect> getRoom();
};

#endif
