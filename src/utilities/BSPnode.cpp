#include "BSPnode.hpp"
#include "BSPtree.hpp"

#include "utilities.hpp"
#include <iostream>

bool BSPNode::splitNode() {
    if (_child1 != nullptr || _child2 != nullptr) {
        return false;
    }

    bool splitHorizontally = Utilities::randInt(0, 1);
    if (_width / _height >= 1.25) {
        splitHorizontally = false;
    } else if (_height / _width >= 1.25) {
        splitHorizontally = true;
    }

    int max;
    if (splitHorizontally) {
        max = _height - MIN_NODE_SIZE;
    } else {
        max = _width - MIN_NODE_SIZE;
    }

    if (max <= MIN_NODE_SIZE) {
        return false;
    }

    int split = Utilities::randInt(MIN_NODE_SIZE, max);

    if (splitHorizontally) {
        _child1 = std::make_shared<BSPNode>(_x, _y, _width, split);
        _child2 = std::make_shared<BSPNode>(_x, _y + split, _width, _height - split);
    } else {
        _child1 = std::make_shared<BSPNode>(_x, _y, split, _height);
        _child2 = std::make_shared<BSPNode>(_x + split, _y, _width - split, _height);
    }
    return true;
}

void BSPNode::createRooms(BSPTree& tree) {
    if (_child1 || _child2) {
        if (_child1) {
            _child1->createRooms(tree);
        }
        if (_child2) {
            _child2->createRooms(tree);
        }
        if (_child1 && _child2) {
            tree.createHall(_child1->getRoom(), _child2->getRoom());
        }
    } else {
        int w = Utilities::randInt(MIN_ROOM_SIZE, std::min(MAX_ROOM_SIZE, _width - 1));
        int h = Utilities::randInt(MIN_ROOM_SIZE, std::min(MAX_ROOM_SIZE, _height - 1));
        int x = Utilities::randInt(_x, _x + (_width - 1) - w);
        int y = Utilities::randInt(_y, _y + (_height - 1) - h);
        _room = std::make_shared<IntRect>(x, y, w, h);
        tree.createRoom(_room);
    }
}

std::shared_ptr<IntRect> BSPNode::getRoom() {
    if (_room) {
        return _room;
    } else {
        std::shared_ptr<IntRect> room1, room2;
        room1 = nullptr;
        room2 = nullptr;
        if (_child1) {
            room1 = _child1->getRoom();
        }
        if (_child2) {
            room2 = _child2->getRoom();
        }
        if (!_child1 && !_child2) {
            return nullptr;
        } else if (!room2) {
            return room1;
        } else if (!room1) {
            return room2;
        } else if (Utilities::randInt(0, 1)) {
            return room1;
        } else {
            return room2;
        }
    }
}