/*
** EPITECH PROJECT, 2019
** CPP_rtype_2019
** File description:
** test
*/

#ifndef TEST_H_
#define TEST_H_

#include "System.hpp"
#include "Component.hpp"
#include "Vector.hpp"
#include "Sfml/Sprite.hpp"
#include "Exception.hpp"

class Position : public Engine::Component
{
public:
    Position(Utils::Vector2 p = Utils::Vector2(0, 0)) : pos(p) {};

    Utils::Vector2 pos;
};

class Velocity : public Engine::Component
{
public:
    Velocity(int l = 0) : velocity(l) {}

    int velocity;

};

class Move : public Engine::System
{
public:
    void update() override {
        for (auto &ent : getEntities()) {
            Velocity &v = ent.getComponent<Velocity>();
            Position &p = ent.getComponent<Position>();

            p.pos.X += v.velocity;

        }
    }
};

class Vitesse : public Engine::Component
{
    public:
        Vitesse(int v = 10) : vitesse(v) {}
        int vitesse;
};

class Sprite : public Engine::Component
{
public:
    Visual::SFML::Sprite sprite;
};


class Deplacement : public Engine::System
{
public:

    Deplacement(Visual::IWindow *w) : win(w) {};

    void update() override
    {
        for (auto &ent : getEntities()) {
            try {
            Sprite &p = ent.getComponent<Sprite>();
            Vitesse &v = ent.getComponent<Vitesse>();

            //std::cout << ent.getId() << std::endl;
            if (win->getKey() == Visual::Keys::SPACE)
                ent.kill();
            if (win->getKey() == Visual::Keys::K_Q)
                p.sprite.move(Utils::Vector2(-1 * v.vitesse, 0));
            if (win->getKey() == Visual::Keys::K_D)
                p.sprite.move(Utils::Vector2(1 * v.vitesse, 0));
            if (win->getKey() == Visual::Keys::K_Z)
                p.sprite.move(Utils::Vector2(0, -1 * v.vitesse));
            if (win->getKey() == Visual::Keys::K_S)
                p.sprite.move(Utils::Vector2(0, 1 * v.vitesse));
            win->draw(p.sprite);
            } catch(const Engine::Exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }

private:
    Visual::IWindow *win;
};

class InBox : public Engine::System
{
public:
    void update() override {
        for (auto &ent : getEntities()) {
            try {
            Sprite &v = ent.getComponent<Sprite>();

            if (v.sprite.getPosition().X < 0)
                v.sprite.setPosition(Utils::Vector2(0, v.sprite.getPosition().Y));

            if (v.sprite.getPosition().X > 700)
                v.sprite.setPosition(Utils::Vector2(700, v.sprite.getPosition().Y));

            if (v.sprite.getPosition().Y < 0)
                v.sprite.setPosition(Utils::Vector2(v.sprite.getPosition().X, 0));

            if (v.sprite.getPosition().Y > 300)
                v.sprite.setPosition(Utils::Vector2(v.sprite.getPosition().X, 300));

            } catch(const Engine::Exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }
    }
};


#endif /* !TEST_H_ */
