/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** System
*/

#include "System.hpp"
#include <algorithm>
#include "Exception.hpp"

void Engine::System::refresh()
{
    if (_instance == nullptr)
        return;
    std::vector<ID> checked;
    bool no = true;

    try {
    for (ID id = 0; id < _instance->getSizeEntities(); id++) {
        no = true;
        for (auto &comp : _components)  {
            if (_instance->getEntity(id).hasComponent(comp) == false) {
                no = false;
                continue;
            }
        }
        if (no == true) {
            checked.push_back(id);
            if (_entities[id] == false) {
                _entities[id] = true;
            }
        }
    }
    } catch (const Engine::Exception &e) {
    }

    for (ID id = 0; id < _entities.size(); id++) {

        if (_entities[id] == true && std::find(checked.begin(), checked.end(), id) == checked.end()) {
            _entities[id] = false;
        }
    }
}


std::vector<Engine::Entity> Engine::System::getEntities()
{
    std::vector<Engine::Entity> vec;

    for (auto it = _instance->getEntityList().begin(); it != _instance->getEntityList().end(); ++it) {
        if (_entities[it->getId()] == true && it->getActivate() == true)
            vec.push_back(*it);
    }
    return vec;
}

Engine::Entity &Engine::System::newEntity()
{
    return _instance->newEntity();
}

void Engine::System::addComponent(const std::string &comp)
{
    _components.push_back(comp);
}

void Engine::System::removeComponent(const std::string &comp)
{
    _components.erase(std::remove(_components.begin(), _components.end(), comp), _components.end());
}