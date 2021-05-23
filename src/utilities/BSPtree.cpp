#include "BSPtree.hpp"
#include "utilities.hpp"

#include <iostream>

void BSPTree::generate(Map& floor, int mapWidth, int mapHeight) {
    _floor = Map(mapHeight);
    for (int i = 0; i < mapHeight; i ++) {
        _floor[i] = std::vector<FloorType>(mapWidth);
        for (int j = 0; j < mapWidth; j ++) {
            _floor[i][j] = EMPTY;
        }
    }
    _nodes = std::vector<std::shared_ptr<BSPNode>>();

    std::shared_ptr<BSPNode> root = std::make_shared<BSPNode>(0, 0, mapWidth, mapHeight);
    _nodes.push_back(root);

    bool splitSuccessfully = true;
    while (splitSuccessfully) {
        splitSuccessfully = false;
        for (auto& node : _nodes) {
            if (node == nullptr) continue;
            if (node->child1() == nullptr && node->child2() == nullptr) {
                if (node->width() > MAX_NODE_SIZE || node->height() > MAX_NODE_SIZE || Utilities::randf() > 0.8) {
                    if (node->splitNode()) {
                        std::shared_ptr<BSPNode> child1, child2;
                        child1 = node->child1();
                        child2 = node->child2();
                        if (child1)
                            _nodes.push_back(child1);
                        if (child2)
                            _nodes.push_back(child2);
                        splitSuccessfully = true;
                    }
                }
            }
        }
    }
    root->createRooms(*this);

    for (int i = 0; i < mapHeight; i ++) {
        for (int j = 0; j < mapWidth; j ++) {
            floor[i][j] = _floor[i][j];
        }
    }
}

void BSPTree::createRoom(std::shared_ptr<IntRect> room) {
    for (int y = room->top + 1; y < room->top + room->height; y ++) {
        for (int x = room->left + 1; x < room->left + room->width; x ++) {
            if (y == room->top + 1 && x == room->left + 1) {
                _floor[y][x] = WALL_TL;
            } else if (y == room->top + room->height - 1 && x == room->left + 1) {
                _floor[y][x] = WALL_BL;
            } else if (y == room->top + 1 && x == room->left + room->width - 1) {
                _floor[y][x] = WALL_TR;
            } else if (y == room->top + room->height - 1 && x == room->left + room->width - 1) {
                _floor[y][x] = WALL_BR;
            } else if (y == room->top + 1 || y == room->top + room->height - 1) {
                _floor[y][x] = WALL_H;
            } else if (x == room->left + 1 || x == room->left + room->width - 1) {
                _floor[y][x] = WALL_V;
            } else {
                _floor[y][x] = FLOOR;
            }
        }
    }
}

void BSPTree::createHall(std::shared_ptr<IntRect> room1, std::shared_ptr<IntRect> room2) {
    int x1 = room1->left + room1->width / 2;
    int y1 = room1->top + room1->height / 2;
    int x2 = room2->left + room2->width / 2;
    int y2 = room2->top + room2->height / 2;
    if (Utilities::randInt(0, 1)) {
        createHTunnel(x1, x2, y1);
        createVTunnel(y1, y2, x2);
    } else {
        createVTunnel(y1, y2, x1);
        createHTunnel(x1, x2, y2);
    }
}

void BSPTree::createHTunnel(int x1, int x2, int y) {
    for (int x = std::min(x1, x2); x < std::max(x1, x2) + 1; x ++) {
        if (_floor[y][x] == EMPTY) {
            _floor[y][x] = TUNNEL;
        } else if (_floor[y][x] == WALL_V) {
            _floor[y][x] = CLOSED_DOOR_V;
        }
    }
}

void BSPTree::createVTunnel(int y1, int y2, int x) {
    for (int y = std::min(y1, y2); y < std::max(y1, y2) + 1; y ++) {
        if (_floor[y][x] == EMPTY) {
            _floor[y][x] = TUNNEL;
        } else if (_floor[y][x] == WALL_H) {
            _floor[y][x] = CLOSED_DOOR_H;
        }
    }
}