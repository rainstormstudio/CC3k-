#include "cameraUpdateSystem.hpp"

#include "../core/ecs/ecs.hpp"
#include "../core/managers/keyboardManager.hpp"
#include "../components/camera.hpp"
#include "../components/transform.hpp"

void CameraUpdateSystem::init() {

}

void CameraUpdateSystem::update(float deltaTime) {
    for (auto& entity : _entities) {
        auto& transform = Ecs::getInstance().getComponent<Transform>(entity);
        auto& camera = Ecs::getInstance().getComponent<Camera>(entity);
        if (KeyboardManager::getInstance().keyPressed(sf::Keyboard::Left)) {
            transform.position.x -= camera.moveSpeed * deltaTime;
        }
        if (KeyboardManager::getInstance().keyPressed(sf::Keyboard::Right)) {
            transform.position.x += camera.moveSpeed * deltaTime;
        }
        if (KeyboardManager::getInstance().keyPressed(sf::Keyboard::Up)) {
            transform.position.y -= camera.moveSpeed * deltaTime;
        }
        if (KeyboardManager::getInstance().keyPressed(sf::Keyboard::Down)) {
            transform.position.y += camera.moveSpeed * deltaTime;
        }
    }
}