#include "floorUpdateSystem.hpp"

#include "../core/ecs/ecs.hpp"
#include "../components/floor.hpp"

void FloorUpdateSystem::init() {

}

void FloorUpdateSystem::update(float deltaTime) {
    for (auto& entity : _entities) {
        auto& floor = Ecs::getInstance().getComponent<Floor>(entity);
        if (!floor.active) {
            Floor::generate(floor, 80, 60);
        }
    }
}