OpenGy : Game Engine ECS
===========================================

Create new world :
******************************
#include "Instance.hpp"      *
                             *
Engine::Instance instance;   *
******************************

Create new Entity :
***********************************************
#include "Entity.hpp"                         *
                                              *
Engine::Entity entity = instance.newEntity(); *
***********************************************

Create new Composant
*******************************************
#include "Component.hpp"                  *
                                          *
class Comp : public Engine::Component     *
{                                         *
//Exemple                                 *
public:                                   *
    Vector2 Position;                     *
    int life;                             *
    ....                                  *
};                                        *
*******************************************

Create new System
*********************************************************
#include "System.hpp"                                   *
#include "Exception.hpp"                                *
                                                        *
class Sys : public Engine::System                       *
{                                                       *
public:                                                 *
    Sys(Args...); //Optionnal                           *
                                                        *
    void Update() override //MANDATORY                  *
    {                                                   *
        for (auto &e : getEntities())                   *
        {                                               *
            try {                                       *
                Comp &comp = e.getComponent<Comp>();    *
                ....                                    *
            } catch (const Engine::Exception &e) {      *
                std::cerr << e.what() << std::endl;     *
            }                                           *
        }                                               *
    }                                                   *
                                                        *
private:                                                *
    ...                                                 *
};                                                      *
*********************************************************

Add Component to Entity
***************************************
#include "Entity.hpp"                 *
                                      *
entity.addComponent<Comp>(Args...);   *
***************************************

Add Component to System
******************************************************
instance.addComponentsToSystem<System, Component>(); *
******************************************************

- Don't forget to call 'instance.update()' function in GameLoop