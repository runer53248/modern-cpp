#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle {
public:
    using Rectangle::Rectangle;
    Square() = delete;
    explicit Square(double x);
    Square(const Square& other) = default;

    double getY() = delete;

    double getArea() const noexcept override;
    double getPerimeter() const noexcept override;
    void print() const override;
};
