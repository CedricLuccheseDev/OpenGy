/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** IWindow
*/

#ifndef IWINDOW_HPP_
#define IWINDOW_HPP_

#include <string>
#include "Vector.hpp"
#include "ISprite.hpp"
#include "IText.hpp"

namespace Visual
{

    enum Keys : unsigned int
    {
        NONE = 0,
        ENTER,
        TAB,
        SPACE,
        RIGHT,
        LEFT,
        DOWN,
        UP,
        K_1,
        K_2,
        K_3,
        K_4,
        K_5,
        K_6,
        K_7,
        K_8,
        K_9,
        K_0,
        K_Z,
        K_Q,
        K_S,
        K_D
    };

    class IWindow {
        public:
            virtual ~IWindow() = default;

            /**
             * @brief create new window
             *
             * @param WindowName
             * @param WindowSize
             */
            virtual void create(const std::string &WindowName, const Utils::Vector2 &WindowSize) = 0;
            virtual void destroy(void) = 0;

            /**
             * @brief update window
             *
             */
            virtual void update(void) = 0;

            /**
             * @brief display window
             *
             */
            virtual void display(void) = 0;

            /**
             * @brief clear window
             *
             */
            virtual void clear(void) = 0;

            /**
             * @brief quit and close window
             *
             */
            virtual void quit(void) = 0;

            /**
             * @brief draw sprite
             *
             */
            virtual void draw(Visual::ISprite &) = 0;

            /**
             * @brief draw text
             *
             */
            virtual void draw(Visual::IText &) = 0;

            /**
             * @brief Handle event if lib have to launch a handleEvent
             *
             */
            virtual void handleEvent(void) = 0;

            virtual bool isRunning(void) = 0;

            virtual Keys getKey(void) = 0;
            virtual Keys getKeyReleased(void) = 0;

            virtual Utils::Vector2 getMousePosition(void) = 0;

            virtual bool getMouseLeftClick(void) = 0;
            virtual bool getMouseRightClick(void) = 0;
            virtual bool getMouseLeftClickReleased(void) = 0;
            virtual bool getMouseRightClickReleased(void) = 0;
    };

}

#endif /* !IWINDOW_HPP_ */
