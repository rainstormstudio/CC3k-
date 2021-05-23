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
    camera.view.zoom(transform.scale);

    WindowManager::getInstance().setView(camera.view);

    for (auto& entity : _entities) {
        auto& transform = Ecs::getInstance().getComponent<Transform>(entity);
        auto& floor = Ecs::getInstance().getComponent<Floor>(entity);
        int i = 0;
        for (auto& row : floor.data) {
            std::string line = "";
            for (auto& type : row) {
                switch (type) {
                    case EMPTY: {
                        line += ' ';
                        break;
                    }
                    case FLOOR: {
                        line += '.';
                        break;
                    }
                    case TUNNEL: {
                        line += '#';
                        break;
                    }
                    case WALL_H: {
                        line += '-';
                        break;
                    }
                    case WALL_V: {
                        line += '|';
                        break;
                    }
                    case CLOSED_DOOR_H: {
                        line += '=';
                        break;
                    }
                    case CLOSED_DOOR_V: {
                        line += ':';
                        break;
                    }
                    case WALL_TL: {
                        line += '1';
                        break;
                    }
                    case WALL_TR: {
                        line += '2';
                        break;
                    }
                    case WALL_BL: {
                        line += '3';
                        break;
                    }
                    case WALL_BR: {
                        line += '4';
                        break;
                    }
                }
            }
            WindowManager::getInstance().writeF(line, AssetsManager::getInstance().monoFont(), transform.position.x, transform.position.y + i * 20, sf::Color::White, 14);
            i ++;
        }
    }

    WindowManager::getInstance().setView(
        WindowManager::getInstance().defaultView()
    );
}