/**
 * @file componentManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the Component Manager
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef COMPONENTMANAGER_HPP
#define COMPONENtMANAGER_HPP

#include "entity.hpp"
#include "component.hpp"
#include "componentList.hpp"

#include <any>
#include <memory>
#include <unordered_map>

class ComponentManager {
private:
    std::unordered_map<const char*, ComponentType> _components{};
    std::unordered_map<const char*, std::shared_ptr<IComponentList>> _componentLists{};
    ComponentType _nextComponent{};

    /**
     * @brief Get the Component List 
     * (need to make sure the component has been registered already)
     * 
     * @tparam T 
     * @return std::shared_ptr<ComponentList<T>> 
     */
    template<typename T>
    std::shared_ptr<ComponentList<T>> getComponentList() {
        const char* type = typeid(T).name();
        return std::static_pointer_cast<ComponentList<T>>(_componentLists[type]);
    }

public:
    /**
     * @brief register the component
     * (need to make sure the component has not been registered yet)
     * 
     * @tparam T 
     */
    template<typename T>
    void registerComponent() {
        const char* type = typeid(T).name();
        _components.insert({type, _nextComponent});
        _componentLists.insert({type, std::make_shared<ComponentList<T>>()});
        _nextComponent ++;
    }

    /**
     * @brief Get the Component type
     * (need to make sure the component has been registered)
     * 
     * @tparam T 
     * @return Component 
     */
    template<typename T>
    ComponentType getComponentType() {
        const char* type = typeid(T).name();
        return _components[type];
    }

    /**
     * @brief add component to entity
     * 
     * @tparam T 
     * @param entity 
     * @param component 
     */
    template<typename T>
    void addComponent(Entity entity, T component) {
        getComponentList<T>()->addComponent(entity, component);
    }

    /**
     * @brief remove component from entity
     * 
     * @tparam T 
     * @param entity 
     */
    template<typename T>
    void removeComponent(Entity entity) {
        getComponentList<T>()->removeComponent(entity);
    }

    /**
     * @brief Get the Component of the entity
     * 
     * @tparam T 
     * @param entity 
     * @return T& 
     */
    template<typename T>
    T& getComponent(Entity entity) {
        return getComponentList<T>()->getComponent(entity);
    }

    void entityDestroyed(Entity entity) {
        for (auto const& pair : _componentLists) {
            auto const& component = pair.second;
            component->entityDestroyed(entity);
        }
    }
};

#endif
