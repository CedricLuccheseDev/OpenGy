/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Component
*/

#include "Component.hpp"
#include "Exception.hpp"
#include <exception>

void Engine::ComponentStorage::addComponent(Engine::Component *comp)
{
    if (comp == nullptr)
        return;
    _components.push_back(comp);
}

Engine::Component &Engine::ComponentStorage::getComponent(const std::string &type, ID id)
{
    for (auto &comp : _components) {
        if (comp->getType() == type && comp->getOwnerId() == id) {
            return *comp;
        }
    }
    throw Exception("[ERROR|Engine] Component " + type + " introuvable pour l'id : " + std::to_string(id));
}

Engine::Component &Engine::ComponentStorage::getComponent(const std::string &type)
{
    for (auto &comp : _components) {
        if (comp->getType() == type) {
            return *comp;
        }
    }
    throw Exception("[ERROR|Engine] Component " + type + " introuvable");
}

bool Engine::ComponentStorage::hasComponent(const std::string &type, ID id)
{
    for (auto &comp : _components) {
        if (comp->getType() == type && comp->getOwnerId() == id) {
            return true;
        }
    }
    return false;
}