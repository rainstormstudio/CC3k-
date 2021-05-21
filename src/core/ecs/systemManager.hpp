/**
 * @file systemManager.hpp
 * @author Hongyu Ding (rainstormstudio@yahoo.com)
 * @brief This file defines a system manager
 * @version 0.1
 * @date 2021-05-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include "system.hpp"
#include "entity.hpp"
#include "component.hpp"

#include <memory>
#include <unordered_map>

class SystemManager {
private:
    std::unordered_map<const char*, Signature> _signatures{};
    std::unordered_map<const char*, std::shared_ptr<System>> _systems{};

public:
    /**
     * @brief register the system T
     * (need to make sure the system has not been registered yet)
     * 
     * @tparam T 
     * @return std::shared_ptr<T> 
     */
    template<typename T>
    std::shared_ptr<T> registerSystem() {
        const char* type = typeid(T).name();
        auto system = std::make_shared<T>();
        _systems.insert({type, system});
        return system;
    }

    /**
     * @brief Set the Signature of system T
     * (need to make sure the system has been registered)
     * 
     * @tparam T 
     * @param signature 
     */
    template<typename T>
    void setSignature(Signature signature) {
        const char* type = typeid(T).name();
        _signatures.insert({type, signature});
    }

    /**
     * @brief clean after entity was destroyed
     * 
     * @param entity 
     */
    void entityDestroyed(Entity entity) {
        for (auto const& pair : _systems) {
            auto const& system = pair.second;
            system->_entities.erase(entity);
        }
    }

    /**
     * @brief notify each system that an entity's signature has been changed
     * 
     * @param entity 
     * @param signature entity's signature
     */
    void entitySignatureChanged(Entity entity, Signature signature) {
        for (auto const& pair : _systems) {
            auto const& type = pair.first;
            auto const& system = pair.second;
            auto const& systemSignature = _signatures[type];
            if ((signature & systemSignature) == systemSignature) {
                system->_entities.insert(entity);
            } else {
                system->_entities.erase(entity);
            }
        }
    }
};

#endif
