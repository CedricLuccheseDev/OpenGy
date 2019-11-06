/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** System
*/

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "Instance.hpp"
#include "Entity.hpp"

namespace Engine
{
    class Instance;
    class Entity;

    class System
    {
    public:
        System() = default;

        void create(Instance *instance, const std::string &type) { _instance = instance; _type = type; _activate = true; }

        void addComponent(const std::string &comp);
        void removeComponent(const std::string &comp);

        void refresh(void);

        virtual void update(void) {};

        void setActivate(bool ac) { _activate = ac; }
        bool isActivate(void) { return _activate; }

        const std::string &getType(void) { return _type; }

        std::vector<Engine::Entity> getEntities();

        Entity &newEntity(void);

    private:
        std::string _type;
        bool _activate;

        Instance *_instance;

        std::map<ID, bool> _entities;
        std::vector<std::string> _components;
    };

}

#endif