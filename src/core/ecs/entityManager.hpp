/**
 * @file entityManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines the EntityManager class
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include <queue>
#include <array>

#include "entity.hpp"
#include "component.hpp"

class EntityManager {
private:
    std::queue<Entity> _entities{};
    std::array<Signature, MAX_ENTITIES> _signatures{};
    uint32_t _livingEntities;

public:
    EntityManager() {
        for (Entity entity = 0; entity < MAX_ENTITIES; entity ++) {
            _entities.push(entity);
        }
    }

    /**
     * @brief create an entity
     * (need to make sure it won't exceed MAX_ENTITIES)
     * 
     * @return Entity 
     */
    Entity add() {
        Entity entity = _entities.front();
        _entities.pop();
        _livingEntities ++;
        return entity;
    }

    /**
     * @brief destroy an entity
     * (need to make sure it is within the range of MAX_ENTITIES)
     * 
     * @param entity 
     */
    void destroy(Entity entity) {
        _signatures[entity].reset();
        _entities.push(entity);
        _livingEntities --;
    }

    /**
     * @brief Set the signature of the entity
     * (need to make sure entity is within the range of MAX_ENTITIES)
     * 
     * @param entity 
     * @param signature 
     */
    inline void setSignature(Entity entity, Signature signature) {
        _signatures[entity] = signature;
    }

    /**
     * @brief Get the signature of the entity
     * (need to make sure entity is within the range of MAX_ENTITIES)
     * 
     * @param entity 
     * @return Signature 
     */
    inline Signature getSignature(Entity entity) {
        return _signatures[entity];
    }
};

#endif
