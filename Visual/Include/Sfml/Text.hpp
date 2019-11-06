/*
** EPITECH PROJECT, 2019
** RType
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include "IText.hpp"

namespace Visual
{
    namespace SFML
    {

        class Text : public IText {
            public:
                Text(const std::string &str = "", const std::string &font = "") { setString(str); setFont(font); _visible = true; _font = ""; _textstring = str; };

                void create(const Utils::Vector2 &pos, const std::string &text, const std::string &font) final;

                void setString(const std::string str) final;
                void setSize(float size) final;
                void setPosition(const Utils::Vector2 &pos) final;
                void setVisible(bool) final;
                void setFont(const std::string &font) final;

                void move(const Utils::Vector2 &pos) final;

                std::string getString(void) final { return _textstring; }
                bool getVisible(void) final { return _visible; };
                std::string getFont(void) final { return _font; };
                Utils::Vector2 getPosition(void) final { return Utils::Vector2(_text.getPosition().x, _text.getPosition().y); };
                float getSize(void) final { return _text.getScale().x; };

                sf::Text get(void) { return _text; }

            private:
                sf::Text _text;
                bool _visible;
                std::string _textstring;
                std::string _font;
        };
    }
}

#endif /* !TEXT_HPP_ */
