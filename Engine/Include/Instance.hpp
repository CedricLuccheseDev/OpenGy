/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Engine
*/

#ifndef ENGINE_HPP_
#define ENGINE_HPP_

#include <memory>
#include <map>
#include <vector>

#include "System.hpp"
#include "Entity.hpp"
#include "Component.hpp"

using ID = unsigned long long int;

namespace Engine
{
    class Entity;
    class System;

    class Instance {
        public:
            Instance() : _id(0) {};

            Entity &newEntity(void);
            bool killEntity(Entity &);
            Entity &getEntity(ID id);
            ID getSizeEntities(void) { return _entityList.size(); }
            std::vector<Entity> &getEntityList(void) { return _entityList; }

            template <typename T, typename... Args>
            void newSystem(Args&& ...args);
            void newSystem(System &);
            template <typename T>
            void removeSystem();

            ComponentStorage &getComponentStorage(void) { return _componentStorage; }
            template <typename Sys, typename C>
            void addComponentsToSystem();
            template <typename Sys, typename C>
            void removeComponentsToSystem();

            void update(void);

        private:
            ID _id;

            std::vector<Entity> _entityList;
            std::map<std::string, System *> _systems;

            ComponentStorage _componentStorage;

    };

    template <typename T, typename... Args>
    void Instance::newSystem(Args&&... args)
    {
        auto str = typeid(T).name();
        auto *sys = new T{std::forward<Args>(args)...};
        sys->create(this, typeid(T).name());
        _systems[str] = sys;
        std::cout << "[Engine] : new system | " << str << std::endl;
    }

        template <typename T>
    void Instance::removeSystem(void)
    {
        std::string comp = typeid(T).name();

        if (_systems[comp] != nullptr) {
            delete _systems[comp];
            _systems.erase(comp);
        }
    }

    template <typename Sys, typename C>
    void Instance::addComponentsToSystem()
    {
        std::string sys = typeid(Sys).name();
        std::string comp = typeid(C).name();

        std::cout << "[Engine] : " << comp << " added in system " << sys << std::endl;
        _systems[sys]->addComponent(comp);
    }

    template <typename Sys, typename C>
    void Instance::removeComponentsToSystem()
    {
        std::string sys = typeid(Sys).name();
        std::string comp = typeid(C).name();

        std::cout << "[Engine] : " << comp << " removed in system " << sys << std::endl;
        _systems[sys]->removeComponent(comp);
    }

}

#endif /* !ENGINE_HPP_ */
