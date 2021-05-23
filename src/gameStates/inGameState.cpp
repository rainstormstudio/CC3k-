#include "inGameState.hpp"
#include "../core/managers/windowManager.hpp"
#include "../core/managers/configsManager.hpp"
#include "../core/ecs/ecs.hpp"

#include "../components/transform.hpp"
#include "../components/camera.hpp"
#include "../components/floor.hpp"

void InGameState::init() {
    Ecs::getInstance().init();

    Ecs::getInstance().registerComponent<Transform>();
    Ecs::getInstance().registerComponent<Camera>();
    Ecs::getInstance().registerComponent<Floor>();

    _cameraUpdateSystem = Ecs::getInstance().addSystem<CameraUpdateSystem>(); {
        Signature signature;
        signature.set(Ecs::getInstance().getComponentType<Transform>());
        signature.set(Ecs::getInstance().getComponentType<Camera>());
        Ecs::getInstance().setSystemSignature<CameraUpdateSystem>(signature);
    }

    _floorUpdateSystem = Ecs::getInstance().addSystem<FloorUpdateSystem>(); {
        Signature signature;
        signature.set(Ecs::getInstance().getComponentType<Transform>());
        signature.set(Ecs::getInstance().getComponentType<Floor>());
        Ecs::getInstance().setSystemSignature<FloorUpdateSystem>(signature);
    }

    _floorRenderSystem = Ecs::getInstance().addSystem<FloorRenderSystem>(); {
        Signature signature;
        signature.set(Ecs::getInstance().getComponentType<Transform>());
        signature.set(Ecs::getInstance().getComponentType<Floor>());
        Ecs::getInstance().setSystemSignature<FloorRenderSystem>(signature);
    }

    Entity cameraEntity = Ecs::getInstance().addEntity(); {
        Ecs::getInstance().addComponent(
            cameraEntity,
            Transform{
                .position = Vec2f(400, 300), // TODO: change the default camera position
                .rotation = 0.0f,
                .scale = 1.0f
            }
        );
        Ecs::getInstance().addComponent(cameraEntity,Camera{.view = sf::View(), .moveSpeed = 200.0f});
    }
    Entity map = Ecs::getInstance().addEntity(); {
        Ecs::getInstance().addComponent(map, Floor{});
        Ecs::getInstance().addComponent(map, Transform{.position = Vec2f(0, 0), .rotation = 0.0f, .scale = 1.0f});
    }

    _cameraUpdateSystem->init();
    _floorUpdateSystem->init();
    _floorRenderSystem->init(cameraEntity);

}

bool InGameState::update(float deltaTime) {
    // update systems
    _cameraUpdateSystem->update(deltaTime);
    _floorUpdateSystem->update(deltaTime);

    // renderable systems
    WindowManager::getInstance().clear();

    _floorRenderSystem->update(deltaTime);

    if (ConfigsManager::getInstance().showFPS()) {
        WindowManager::getInstance().write("FPS: " + std::to_string(1.0f / deltaTime));
    }
    WindowManager::getInstance().render();

    return true;
}
