/*
** EPITECH PROJECT, 2019
** RType
** File description:
** IText
*/

#ifndef ITEXT_HPP_
#define ITEXT_HPP_

#include "Vector.hpp"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

namespace Visual
{

    class IText {
        public:
            virtual ~IText() = default;

            virtual void create(const Utils::Vector2 &pos, const std::string &text, const std::string &font) = 0;

            virtual void setString(const std::string str) = 0;
            virtual void setSize(float size) = 0;
            virtual void setPosition(const Utils::Vector2 &pos) = 0;
            virtual void setVisible(bool) = 0;
            virtual void setFont(const std::string &font) = 0;

            virtual void move(const Utils::Vector2 &pos) = 0;

            virtual std::string getString(void) = 0;
            virtual bool getVisible(void) = 0;
            virtual std::string getFont(void) = 0;
            virtual Utils::Vector2 getPosition(void) = 0;
            virtual float getSize(void) = 0;

    };

}

#endif /* !ITEXT_HPP_ */
