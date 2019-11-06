/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Entity
*/

#include "Entity.hpp"
#include <exception>

void Engine::Entity::kill(void)
{
    if (getInstance() == nullptr)
        return;
    getInstance()->killEntity(*this);
}

void Engine::Entity::addComp(Engine::Component *comp)
{
    if (getInstance() == nullptr)
        return;
    getInstance()->getComponentStorage().addComponent(comp);
}

Engine::Component &Engine::Entity::getComp(const std::string &type, ID id)
{
    if (getInstance() == nullptr)
        throw std::logic_error("errnull");
    return getInstance()->getComponentStorage().getComponent(type, id);
}

bool Engine::Entity::hasComp(const std::string &type, ID id)
{
    if (getInstance() == nullptr)
        throw std::logic_error("errnull");
    return getInstance()->getComponentStorage().hasComponent(type, id);
}