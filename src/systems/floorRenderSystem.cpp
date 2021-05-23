#include "floorRenderSystem.hpp"

#include <string>
#include <iostream>

#include "../core/managers/windowManager.hpp"
#include "../core/managers/assetsManager.hpp"
#include "../core/managers/configsManager.hpp"
#include "../core/ecs/ecs.hpp"
#include "../components/transform.hpp"
#include "../components/camera.hpp"
#include "../components/floor.hpp"

void FloorRenderSystem::init(Entity cameraEntity) {
    _cameraEntity = cameraEntity;
}

void FloorRenderSystem::update(float deltaTime) {
    auto& transform = Ecs::getInstance().getComponent<Transform>(_cameraEntity);
    auto& camera = Ecs::getInstance().getComponent<Camera>(_cameraEntity);

    camera.view.setCenter(transform.position);
    camera.view.setRotation(transform.rotation);

    WindowManager::getInstance().setView(camera.view);

    for (auto& entity : _entities) {
        auto& transform = Ecs::getInstance().getComponent<Transform>(entity);
        auto& floor = Ecs::getInstance().getComponent<Floor>(entity);
        for (int i = 0; i < floor.data.size(); i ++) {
            for (int j = 0; j < floor.data[i].size(); j ++) {
                int index = static_cast<int>(floor.data[i][j]);
                WindowManager::getInstance().drawSprite(
                    AssetsManager::getInstance().floorTiles(),
                    IntRect((index % 16) * 32, (index / 16) * 32, 32, 32),
                    transform.position.x + j * 32,
                    transform.position.y + i * 32
                );
            }
        }
    }

    WindowManager::getInstance().setView(
        WindowManager::getInstance().defaultView()
    );
}