/*
** EPITECH PROJECT, 2019
** rtype
** File description:
** Vector
*/

#ifndef VECTOR_HPP_
#define VECTOR_HPP_

namespace Utils
{
    /**
     * @brief Vector 2D
     *
     */
    struct Vector2 {
        Vector2(float x = 0, float y = 0) : X(x), Y(y) {}

        Vector2 &operator=(const Vector2 &vec) { X = vec.X; Y = vec.Y; return *this; }
        Vector2 &operator>>(Vector2 &vec) { vec.X = X; vec.Y = Y; return *this; }
        bool operator==(const Vector2 &vec) const { return (vec.X == X && vec.Y == Y) ? true : false; }
        bool operator!=(const Vector2 &vec) const { return (vec.X == X && vec.Y == Y) ? false : true; }

        Vector2 operator+(const Vector2 &vec) {
            Vector2 newvec(X + vec.X, Y + vec.Y);
            return newvec;
        }
        Vector2 &operator+=(const Vector2 &vec) {
            *this = *this + vec;
            return *this;
        }

        float X;
        float Y;
    };

    struct Rectangle {
        Rectangle(float x = 0, float y = 0, float width = 0, float heigth = 0) :
        X(x), Y(y), Width(width), Heigth(heigth) {};

        float X;
        float Y;
        float Width;
        float Heigth;
    };

    struct Collision {
            static bool PointPoint(float p1, float p2) { if (p1 == p2) return true; else return false; };
            static bool PointRectangle(Vector2 p, Rectangle r) {
                if (p.X >= r.X && p.X <= r.Width && p.Y >= r.Y && p.Y <= r.Heigth)
                    return true;
                return false;
            }
    };

}

#endif /* !VECTOR_HPP_ */
