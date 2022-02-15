#pragma once
#include <limits>

enum Color : unsigned char {
    Black,
    Red,
    White = std::numeric_limits<unsigned char>::max()
};

class Shape {
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

private:
    Color color_ = Color::White;
};
