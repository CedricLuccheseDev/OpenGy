/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include "Component.hpp"
#include "Instance.hpp"

using ID = unsigned long long int;

namespace Engine
{
    class Instance;

    class Entity {
        public:
            Entity(ID i, Engine::Instance *instance) : _id(i), _instance(instance), _activate(true) {};

            void kill(void);

            ID getId(void) { return _id; }
            Instance *getInstance(void) { return _instance; }

            template<typename T, typename... Args>
            T& addComponent(Args&&... args);

            template<typename T>
            T& getComponent(void);

            template<typename T>
            bool hasComponent(void);

            template<typename T>
            void removeComponent(void);

            bool hasComponent(const std::string &type)
            {
                return hasComp(type, _id);
            }

            void activate(void) { _activate = true; }
            void deactivate(void) { _activate = false; }
            bool getActivate(void) { return _activate; }

        private:
            ID _id;
            Instance *_instance;

            bool _activate;

            void addComp(Component *);
            Component &getComp(const std::string &type, ID id);
            bool hasComp(const std::string &type, ID id);
    };

    template <typename T, typename... Args>
    T& Entity::addComponent(Args&&... args)
    {
        auto *component = new T{std::forward<Args>(args)...};
        component->create(_id, typeid(*component).name());
        addComp(component);
        return *component;
    }

    template <typename T>
    T& Entity::getComponent()
    {
        std::string str(typeid(T).name());
        return static_cast<T&>(getComp(str, _id));
    }

    template <typename T>
    bool Entity::hasComponent()
    {
        std::string str(typeid(T).name());
        return hasComp(str, _id);
    }

    template <typename T>
    void Entity::removeComponent()
    {
        std::string str(typeid(T).name());
        //getInstance()->getComponentStorage
    }

}

#endif /* !ENTITY_HPP_ */
