//
// Created by Christoffer Lehre on 03/04/2022.
//

#ifndef CPP_EKSAMEN2_VECTOR2D_H
#define CPP_EKSAMEN2_VECTOR2D_H


class Vector2D {
public:
    Vector2D(int x, int y) : m_x(x), m_y(y) {};

    [[nodiscard]] int getX() const { return m_x; }

    [[nodiscard]] int getY() const { return m_y; }

    void setX(int x) { m_x = x; }

    void setY(int y) { m_y = y; }

    [[nodiscard]] int length() const {
        return m_x * m_x + m_y * m_y;
    }

    //overloading operators for easier addition etc of positions.

    Vector2D operator+(const Vector2D &vector2) const {
        return {m_x + vector2.getX(), m_y + vector2.getY()};
    }

    Vector2D operator*(int scalar) const {
        return {m_x * scalar, m_y * scalar};
    }

    Vector2D &operator*=(int scalar) {
        m_x *= scalar;
        m_y *= scalar;
        return *this;
    }

    Vector2D operator-(const Vector2D &vector2) const {
        return {m_x - vector2.m_x, m_y - vector2.m_y};
    }

    friend Vector2D &operator-=(Vector2D &vector1, const Vector2D &vector2) {
        vector1.m_x -= vector2.m_x;
        vector1.m_y -= vector2.m_y;
        return vector1;
    }

    Vector2D operator/(int scalar) const {
        return {m_x / scalar, m_y / scalar};
    }

    Vector2D &operator/=(int scalar) {
        m_x /= scalar;
        m_y /= scalar;
        return *this;
    }

    //normalization -> important for gamelogic etc

    void normalize() {
        int tmp  = length();
        if (tmp > 0) {
            (*this) *= tmp / 1;
        }
    }

private:
    int m_x;
    int m_y;
};


#endif //CPP_EKSAMEN2_VECTOR2D_H
