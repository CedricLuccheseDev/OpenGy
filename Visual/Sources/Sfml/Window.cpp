/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Window
*/

#include <iostream>
#include <memory>
#include "Sfml/Window.hpp"
#include "Sfml/Sprite.hpp"
#include "Sfml/Text.hpp"


#include	<SFML/Window.hpp>
#include	<SFML/Graphics.hpp>

Visual::SFML::Window::Window() :
_keys({ {sf::Keyboard::Unknown,	Visual::Keys::NONE},
        {sf::Keyboard::Return,  Visual::Keys::ENTER},
        {sf::Keyboard::Tab,     Visual::Keys::TAB},
        {sf::Keyboard::Space,	Visual::Keys::SPACE},
        {sf::Keyboard::Right,	Visual::Keys::RIGHT},
        {sf::Keyboard::Left,	Visual::Keys::LEFT},
        {sf::Keyboard::Up,		Visual::Keys::UP},
        {sf::Keyboard::Down,	Visual::Keys::DOWN},
        {sf::Keyboard::Num0,	Visual::Keys::K_0},
        {sf::Keyboard::Num1,	Visual::Keys::K_1},
        {sf::Keyboard::Num2,	Visual::Keys::K_2},
        {sf::Keyboard::Num3,	Visual::Keys::K_3},
        {sf::Keyboard::Num4,	Visual::Keys::K_4},
        {sf::Keyboard::Num5,	Visual::Keys::K_5},
        {sf::Keyboard::Num6,	Visual::Keys::K_6},
        {sf::Keyboard::Num7,	Visual::Keys::K_7},
        {sf::Keyboard::Num8,	Visual::Keys::K_8},
        {sf::Keyboard::Num9,	Visual::Keys::K_9},
        {sf::Keyboard::Z,       Visual::Keys::K_Z},
        {sf::Keyboard::Q,       Visual::Keys::K_Q},
        {sf::Keyboard::S,       Visual::Keys::K_S},
        {sf::Keyboard::D,       Visual::Keys::K_D}}), _run(false), _keyPressed(NONE), _keyReleased(NONE), _clickLeft(false), _clickRight(false)
{}

void Visual::SFML::Window::create(
const std::string &WindowName,
const Utils::Vector2 &WindowSize)
{
    _window = std::make_unique<sf::RenderWindow>(
        sf::VideoMode(WindowSize.X, WindowSize.Y),
        WindowName
    );
    _run = true;
}

void Visual::SFML::Window::destroy(void)
{
    if (_window)
        _window.release();
}


void Visual::SFML::Window::update(void)
{

}

void Visual::SFML::Window::display(void)
{
    _window->display();
}

void Visual::SFML::Window::clear(void)
{
    _window->clear(sf::Color::Black);
}

void Visual::SFML::Window::quit(void)
{
    _run = false;
    _window->close();
}

void Visual::SFML::Window::draw(Visual::ISprite &sprite)
{
    Visual::SFML::Sprite *sp = dynamic_cast<Visual::SFML::Sprite *>(&sprite);

    if (sp == nullptr)
        return;
    _window->draw(sp->get());
}

void Visual::SFML::Window::draw(Visual::IText &text)
{
    Visual::SFML::Text *txt = dynamic_cast<Visual::SFML::Text *>(&text);

    if (txt == nullptr)
        return;
    _window->draw(txt->get());
}

void Visual::SFML::Window::handleEvent(void)
{
    _keyReleased = Keys::NONE;
    while (_window->pollEvent(_ev)) {
        switch (_ev.type) {
        case sf::Event::Closed:
            quit();
            break;
        case sf::Event::KeyPressed:
            _keyPressed = _keys[_ev.key.code];
            break;
        case sf::Event::KeyReleased:
	        switch (_ev.key.code)
	        {
	        default:
	            _keyPressed = Keys::NONE;
                _keyReleased = _keys[_ev.key.code];
	            break;
	        }
	        break;
        default:
            break;
        }
    }
}

Utils::Vector2 Visual::SFML::Window::getMousePosition(void)
{
    return Utils::Vector2(_mouse.getPosition(*_window).x, _mouse.getPosition(*_window).y);
}

bool Visual::SFML::Window::getMouseLeftClick(void)
{
    if (_mouse.isButtonPressed(sf::Mouse::Button::Left)) {
        _clickLeft = true;
        return true;
    } else
        _clickLeft = false;
    return false;
}

bool Visual::SFML::Window::getMouseRightClick(void)
{
    if (_mouse.isButtonPressed(sf::Mouse::Button::Right)) {
        _clickRight = true;
        return true;
    } else
        _clickRight = false;
    return false;
}

bool Visual::SFML::Window::getMouseLeftClickReleased(void)
{
    if (!_mouse.isButtonPressed(sf::Mouse::Button::Left) &&
        _clickLeft == true) {
        return true;
    }
    return false;
}

bool Visual::SFML::Window::getMouseRightClickReleased(void)
{
    if (!_mouse.isButtonPressed(sf::Mouse::Button::Right) &&
        _clickRight == true) {
        return true;
    }
    return false;
}