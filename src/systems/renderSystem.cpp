#include "renderSystem.hpp"

#include <string>

#include "../core/managers/windowManager.hpp"
#include "../core/ecs/ecs.hpp"
#include "../components/transform.hpp"
#include "../components/camera.hpp"

void RenderSystem::init() {
    _cameraEntity = Ecs::getInstance().addEntity();
    Ecs::getInstance().addComponent(
        _cameraEntity,
        Transform{
            .position = Vec2f(0, 0), // TODO: change the default camera position
            .rotation = 0.0f,
            .scale = 1.0f
        }
    );
    Ecs::getInstance().addComponent(
        _cameraEntity,
        Camera{
            .view = sf::View()
        }
    );
}

void RenderSystem::update(float deltaTime) {
    WindowManager::getInstance().clear();

    auto& transform = Ecs::getInstance().getComponent<Transform>(_cameraEntity);
    auto& camera = Ecs::getInstance().getComponent<Camera>(_cameraEntity);

    camera.view.setCenter(transform.position);
    camera.view.setRotation(transform.rotation);
    camera.view.zoom(transform.scale);

    WindowManager::getInstance().setView(camera.view);

    for (auto& entity : _entities) {
        auto& transform = Ecs::getInstance().getComponent<Transform>(entity);
        WindowManager::getInstance().write("###", transform.position.x, transform.position.y);
    }

    WindowManager::getInstance().setView(
        WindowManager::getInstance().defaultView()
    );
    WindowManager::getInstance().write("FPS: " + std::to_string(1.0f / deltaTime));
    
    WindowManager::getInstance().render();
}