/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** SFMLWindow
*/

#ifndef SFMLWINDOW_HPP_
#define SFMLWINDOW_HPP_

#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>
#include    <SFML/Window/Keyboard.hpp>
#include    <SFML/Window/Event.hpp>

#include <memory>
#include <map>

#include "IWindow.hpp"
#include "Sfml/Sprite.hpp"

namespace Visual
{
    namespace SFML
    {

        class Window : public IWindow {
            public:
                Window();
                ~Window() { destroy(); }

                virtual void create(const std::string &WindowName, const Utils::Vector2 &WindowSize) final;
                virtual void destroy(void) final;

                virtual void update(void) final;
                virtual void display(void) final;
                virtual void clear(void) final;
                virtual void quit(void) final;

                virtual void draw(Visual::ISprite &sprite) final;
                virtual void draw(Visual::IText &text) final;

                virtual void handleEvent(void) final;

                virtual bool isRunning(void) final { return _run; };

                virtual Keys getKey(void) final { return _keyPressed; }
                virtual Keys getKeyReleased(void) final { return _keyReleased; };

                virtual Utils::Vector2 getMousePosition(void) final;
                virtual bool getMouseLeftClick(void) final;
                virtual bool getMouseRightClick(void) final;
                virtual bool getMouseLeftClickReleased(void) final;
                virtual bool getMouseRightClickReleased(void) final;

            private:
                std::map<sf::Keyboard::Key, Visual::Keys> _keys;
                std::unique_ptr<sf::RenderWindow> _window;

                bool _run;

                Visual::Keys _keyPressed;
                Visual::Keys _keyReleased;

                sf::Event _ev;
                sf::Mouse _mouse;

                bool _clickLeft;
                bool _clickRight;
        };

    }

}

#endif /* !SFMLWINDOW_HPP_ */
