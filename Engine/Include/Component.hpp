/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include <vector>
#include <iostream>
#include <map>
#include <memory>

using ID = unsigned long long int;

namespace Engine
{

    class Component
    {
    public:
        Component(ID id = -1, const std::string &type = "") : _id(id), _type(type) {}

        void create(ID id, const std::string type) { _id = id; _type = type; }

        ID getOwnerId(void) { return _id; }
        const std::string &getType(void) { return _type; }

    private:
        ID _id;
        std::string _type;
    };

    class ComponentStorage
    {
    public:
        void addComponent(Component *);

        Component &getComponent(const std::string &type);
        Component &getComponent(const std::string &type, ID id);
        bool hasComponent(const std::string &type, ID id);

        std::vector<Component *> &getComponents() { return _components; }
    private:
        std::vector<Component *> _components;
    };


}

#endif /* !COMPONENT_HPP_ */
