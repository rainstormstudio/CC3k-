/**
 * @file ecs.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the coordinator of the Entity Component System
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef ECS_HPP
#define ECS_HPP

#include "componentManager.hpp"
#include "entityManager.hpp"
#include "systemManager.hpp"
#include "entity.hpp"
#include "component.hpp"

#include <memory>

class Ecs {
private:
    std::unique_ptr<ComponentManager> _componentManager;
    std::unique_ptr<EntityManager> _entityManager;
    std::unique_ptr<SystemManager> _systemManager;

    Ecs() {}

public:
    Ecs(Ecs const&) = delete;
    void operator=(Ecs const&) = delete;

    static Ecs& getInstance() {
        static Ecs instance;
        return instance;
    }

    /**
     * @brief initialize the ECS
     * 
     */
    void init() {
        _componentManager = std::make_unique<ComponentManager>();
        _entityManager = std::make_unique<EntityManager>();
        _systemManager = std::make_unique<SystemManager>();
    }

    // Entity methods 

    /**
     * @brief create a new entity
     * 
     * @return Entity 
     */
    Entity addEntity() {
        return _entityManager->add();
    }

    /**
     * @brief destroy the entity
     * 
     * @param entity 
     */
    void destroyEntity(Entity entity) {
        _entityManager->destroy(entity);
        _componentManager->entityDestroyed(entity);
        _systemManager->entityDestroyed(entity);
    }

    // Component methods
    
    /**
     * @brief register the component T
     * 
     * @tparam T 
     */
    template<typename T>
    void registerComponent() {
        _componentManager->registerComponent<T>();
    }

    /**
     * @brief add component T to the entity
     * 
     * @tparam T 
     * @param entity 
     * @param component 
     */
    template<typename T>
    void addComponent(Entity entity, T component) {
        _componentManager->addComponent<T>(entity, component);
        auto signature = _entityManager->getSignature(entity);
        signature.set(_componentManager->getComponentType<T>(), true);
        _entityManager->setSignature(entity, signature);
        _systemManager->entitySignatureChanged(entity, signature);
    }

    /**
     * @brief remove component T from the entity
     * 
     * @tparam T 
     * @param entity 
     */
    template<typename T>
    void removeComponent(Entity entity) {
        _componentManager->removeComponent<T>(entity);
        auto signature = _entityManager->getSignature(entity);
        signature.set(_componentManager->getComponentType<T>(), false);
        _entityManager->setSignature(entity, signature);
        _systemManager->entitySignatureChanged(entity, signature);
    }

    /**
     * @brief Get the Component T of the entity
     * 
     * @tparam T 
     * @param entity 
     * @return T& 
     */
    template<typename T>
    T& getComponent(Entity entity) {
        return _componentManager->getComponent<T>(entity);
    }

    /**
     * @brief Get the Component Type 
     * 
     * @tparam T 
     * @return ComponentType 
     */
    template<typename T>
    ComponentType getComponentType() {
        return _componentManager->getComponentType<T>();
    }

    // System methods
    
    /**
     * @brief register the system T
     * 
     * @tparam T 
     * @return std::shared_ptr<T> 
     */
    template<typename T>
    std::shared_ptr<T> addSystem() {
        return _systemManager->add<T>();
    }

    /**
     * @brief Set the Signature of System T
     * 
     * @tparam T 
     * @param signature 
     */
    template<typename T>
    void setSystemSignature(Signature signature) {
        _systemManager->setSignature<T>(signature);
    }
};

#endif
