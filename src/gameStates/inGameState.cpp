#include "inGameState.hpp"
#include "../core/managers/windowManager.hpp"
#include "../core/ecs/ecs.hpp"

#include "../components/transform.hpp"
#include "../components/camera.hpp"
#include "../components/renderable.hpp"

#include "../systems/renderSystem.hpp"

void InGameState::init() {
    Ecs::getInstance().init();

    Ecs::getInstance().registerComponent<Transform>();
    Ecs::getInstance().registerComponent<Camera>();
    Ecs::getInstance().registerComponent<Renderable>();

    _renderSystem = Ecs::getInstance().addSystem<RenderSystem>(); {
        Signature signature;
        signature.set(Ecs::getInstance().getComponentType<Transform>());
        signature.set(Ecs::getInstance().getComponentType<Renderable>());
        Ecs::getInstance().setSystemSignature<RenderSystem>(signature);
    }
    _renderSystem->init();

    Entity entity = Ecs::getInstance().addEntity(); {
        Ecs::getInstance().addComponent(entity, Renderable{});
        Ecs::getInstance().addComponent(entity, 
            Transform{
                .position = Vec2f(0.0f, 0.0f),
                .rotation = 0.0f,
                .scale = 1.0f
            });
    }
}

bool InGameState::update(float deltaTime) {

    _renderSystem->update(deltaTime);

    return true;
}
