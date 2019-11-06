/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Engine
*/


#include <iostream>
#include "Instance.hpp"
#include "Exception.hpp"

Engine::Entity &Engine::Instance::newEntity()
{
    Entity ent(_id, this);
    _entityList.push_back(ent);
    std::cout << "[Engine] : New entity | id: " << _id << std::endl;
    ++_id;
    return _entityList.back();
}

Engine::Entity &Engine::Instance::getEntity(ID id)
{
    for (auto &ent : _entityList) {
        if (ent.getId() == id)
            return ent;
    }
    throw Engine::Exception("[ERROR|Engine] Id unfoundable");
}

bool Engine::Instance::killEntity(Engine::Entity &entity)
{
    for (auto it = _componentStorage.getComponents().begin();
    it != _componentStorage.getComponents().end(); ++it) {
        if ((*it)->getOwnerId() == entity.getId()) {
            delete *it;
            _componentStorage.getComponents().erase(it);
            it = _componentStorage.getComponents().begin();
        }
    }
    for (auto it = _entityList.begin(); it != _entityList.end(); ++it) {
        if (it->getId() == entity.getId()) {
            _entityList.erase(it);
            return true;
        }
    }
    return false;
}

void Engine::Instance::update(void)
{
    try {
        for (auto it = _systems.begin(); it != _systems.end(); ++it) {
            if (it->second == nullptr)
                continue;
            if (it->second->isActivate()) {
                it->second->refresh();
                it->second->update();
            }
        }
    } catch (const Engine::Exception &e) {
        std::cerr << e.what() << std::endl;
    }
}