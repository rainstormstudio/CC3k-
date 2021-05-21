/**
 * @file componentList.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines a ComponentList
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef COMPONENTLIST_HPP
#define COMPONENTLIST_HPP

#include <array>
#include <unordered_map>

#include "entity.hpp"
#include "component.hpp"

class IComponentList {
public:
    virtual void entityDestroyed(Entity entity) = 0;
    virtual ~IComponentList() = default;
};

template<typename T>
class ComponentList : public IComponentList {
private:
    std::array<T, MAX_ENTITIES> _componentList{};
    std::unordered_map<Entity, size_t> _entityToIndex{};
    std::unordered_map<size_t, Entity> _indexToEntity{};
    size_t _size{};

public:
    /**
     * @brief add component to entity
     * (need to make sure component is not yet added to entity)
     * 
     * @param entity 
     * @param component 
     */
    void addComponent(Entity entity, T component) {
        size_t index = _size;
        _entityToIndex[entity] = index;
        _indexToEntity[index] = entity;
        _componentList[index] = component;
        _size ++;
    }

    /**
     * @brief remove the entity from the component list
     * (need to make sure the component was added to the entity)
     * 
     * @param entity 
     */
    void removeComponent(Entity entity) {
        size_t removingIndex = _entityToIndex[entity];
        size_t lastIndex = _size - 1;
        _componentList[removingIndex] = _componentList[lastIndex];

        Entity lastEntity = _indexToEntity[lastIndex];
        _entityToIndex[lastEntity] = removingIndex;
        _indexToEntity[removingIndex] = lastEntity;

        _entityToIndex.erase(entity);
        _indexToEntity.erase(lastIndex);

        _size --;
    }

    /**
     * @brief Get the component of the entity
     * (need to make sure the component was added to the entity)
     * 
     * @param entity 
     * @return T& 
     */
    inline T& getComponent(Entity entity) {
        return _componentList[_entityToIndex[entity]];
    }

    /**
     * @brief clean after destroying the entity
     * 
     * @param entity 
     */
    void entityDestroyed(Entity entity) override {
        if (_entityToIndex.find(entity) != _entityToIndex.end()) {
            removeComponent(entity);
        }
    }
};

#endif
