/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** View
*/

#include "Parser/ParserSceneFiles.hpp"
#include "Sfml/Sprite.hpp"
#include "Sfml/View.hpp"
#include "Sfml/Window.hpp"
#include "Vector.hpp"
#include <iostream>
#include "Vector.hpp"
#include "Functions/Functions.hpp"
#include "Sfml/Ressources.hpp"

void Scene::SFML::View::set(const Scene::Info &info)
{
    if (_sprites.size() > 0)
        _sprites.clear();

    if (info.err == true)
        return;

    _path = info.path;

    for (auto comp : info.components) {
        if (comp.type == "img") {
            SetImg(comp);
        }
        if (comp.type == "text") {
            SetText(comp);
        }
    }
    //for (auto m : info.musics)
    //    SetMusic(m);
    //_currentMusic = info.musics[0].key;
}

void Scene::SFML::View::update(const Scene::Info &info, Visual::IWindow &win, bool offset)
{
    std::vector<std::string> checked;

    if (_err == true || info.name == "")
        return;

    for (auto ev : info.events) {
        PlayEvent(ev, win);
    }

    //if (_musics.size() > 0)
    //    PlayMusic(info);

    if (offset == false)
        return;

    for (auto comp : info.components) {
        if (comp.type == "img")
            checked.push_back(SetImg(comp));
        if (comp.type == "text")
            checked.push_back(SetText(comp));
    }

    if (_sprites.size() != 0) {
        auto itsprite = _sprites.begin();
        for (; itsprite != _sprites.end(); itsprite++) {
            if (std::find(checked.begin(), checked.end(), itsprite->first) == checked.end()) {
                _sprites.erase(itsprite);
                if (_sprites.size() == 0)
                    break;
                itsprite = _sprites.begin();
            }
        }
    }

    if (_texts.size() != 0) {
        auto ittext = _texts.begin();
        for (; ittext != _texts.end(); ittext++) {
            if (std::find(checked.begin(), checked.end(), ittext->first) == checked.end()) {
                _texts.erase(ittext);
                if (_texts.size() == 0)
                    break;
                ittext = _texts.begin();
            }
        }
    }
}

void Scene::SFML::View::display(Visual::IWindow &w)
{
    Visual::SFML::Window *win = dynamic_cast<Visual::SFML::Window *>(&w);

    if (win == nullptr || _err == true)
        return;

    auto it = _sprites.begin();
    for (; it != _sprites.end(); ++it) {
        if (it->second.getVisible() == true)
            win->draw(it->second);
    }
    auto ittext = _texts.begin();
    for (; ittext != _texts.end(); ++ittext) {
        if (ittext->second.getVisible() == true)
            win->draw(ittext->second);
    }
}

std::string Scene::SFML::View::SetImg(const Scene::Component &comp)
{
    auto it = _sprites.find(comp.name);
    if (it != _sprites.end()) {
        if (it->second.getTexture() != comp.texture)
            it->second.setTexture(comp.texture);
        if (it->second.getPosition() != comp.pos)
            it->second.setPosition(comp.pos);
        if (it->second.getSize() != comp.size)
            it->second.setSize(Utils::Vector2(comp.size, comp.size));
        return (comp.name);
    } else {
        if (it != _sprites.end())
            return ("");
        _sprites.insert(std::pair<std::string, Visual::SFML::Sprite>(comp.name, Visual::SFML::Sprite()));
        _sprites[comp.name].create(comp.pos, comp.texture);
        _sprites[comp.name].setSize(Utils::Vector2(comp.size, comp.size));
        return (comp.name);
    }
    return ("");
}

std::string Scene::SFML::View::SetText(const Scene::Component &comp)
{
    auto it = _texts.find(comp.name);
    if (it != _texts.end()) {
        if (it->second.getString() != comp.text)
            it->second.setString(comp.text);
        if (it->second.getFont() != comp.texture)
            it->second.setFont(comp.texture);
        if (it->second.getPosition() != comp.pos)
            it->second.setPosition(comp.pos);
        if (it->second.getSize() != comp.size)
            it->second.setSize(comp.size);
        return (comp.name);
    } else {
        if (it != _texts.end())
            return ("");
        _texts.insert(std::pair<std::string, Visual::SFML::Text>(comp.name, Visual::SFML::Text()));
        _texts[comp.name].create(comp.pos, comp.text, comp.texture);
        _texts[comp.name].setSize(comp.size);
        return (comp.name);
    }
    return ("");
}

/*
void Scene::SFML::View::SetMusic(const Scene::Music &m)
{
    auto it = _musics.find(m.type);
    if (it == _musics.end()) {
        _musics.push_back(m.type);
    }
}*/

void Scene::SFML::View::PlayEvent(const Scene::Event &ev, Visual::IWindow &win)
{
    if (_sprites.find(ev.name) == _sprites.end())
        return;
    if (ev.type == "clickLeft") {
        if (win.getMouseLeftClick() &&
            Utils::Collision::PointRectangle(
                win.getMousePosition(),
                Utils::Rectangle(   _sprites[ev.name].getPosition().X,
                                    _sprites[ev.name].getPosition().Y,
                                    _sprites[ev.name].getPosition().X + _sprites[ev.name].getTextureRect().X,
                                    _sprites[ev.name].getPosition().Y + _sprites[ev.name].getTextureRect().Y)))
        {
            PlayAction(ev, win);
        }
    }
    if (ev.type == "clickRight") {
        if (win.getMouseRightClick() &&
            Utils::Collision::PointRectangle(
                win.getMousePosition(),
                Utils::Rectangle(   _sprites[ev.name].getPosition().X,
                                    _sprites[ev.name].getPosition().Y,
                                    _sprites[ev.name].getPosition().X + _sprites[ev.name].getTextureRect().X,
                                    _sprites[ev.name].getPosition().Y + _sprites[ev.name].getTextureRect().Y)))
        {
            PlayAction(ev, win);
        }
    }
    if (ev.type == "over") {
        if (Utils::Collision::PointRectangle(
                win.getMousePosition(),
                Utils::Rectangle(   _sprites[ev.name].getPosition().X,
                                    _sprites[ev.name].getPosition().Y,
                                    _sprites[ev.name].getPosition().X + _sprites[ev.name].getTextureRect().X,
                                    _sprites[ev.name].getPosition().Y + _sprites[ev.name].getTextureRect().Y)))
        {
            PlayAction(ev, win);
        }
    }
    if (ev.type == "out") {
        if (!(
            Utils::Collision::PointRectangle(
                win.getMousePosition(),
                Utils::Rectangle(   _sprites[ev.name].getPosition().X,
                                    _sprites[ev.name].getPosition().Y,
                                    _sprites[ev.name].getPosition().X + _sprites[ev.name].getTextureRect().X,
                                    _sprites[ev.name].getPosition().Y + _sprites[ev.name].getTextureRect().Y))))
        {
            PlayAction(ev, win);
        }
    }
    if (ev.type == "run") {
        PlayAction(ev, win);
    }
}

void Scene::SFML::View::PlayAction(const Scene::Event &ev, Visual::IWindow &win)
{
    for (auto ac : ev.actions) {
        try {
        if (ac.type == "quit")
            Scene::Functions::Func["quit"](win, "");
        if (ac.type == "swap")
            Scene::Functions::Func["swap"](win, ac.key);
        if (ac.type == "func")
            Scene::Functions::Func[ac.key](win, ac.param);
        } catch (const std::bad_function_call &e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
}

/*
void Scene::SFML::View::PlayMusic(const Scene::Info &info)
{
    auto it = _musics.find(_currentMusic);

    if (_musics.size() == 0)
        return;

    if (it == _musics.end())
        it = _musics.begin();

    if (it == _musics.end())
        return;

    if (Ressources::SFML::Content::getSound(_currentMusic)->isPlaying() == false) {
        it++;
        if (it == _musics.end())
            it = _musics.begin();
        _currentMusic = it->first;
        Ressources::SFML::Content::getSound(_currentMusic)->play();
    }



}*/