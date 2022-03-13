#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;
using ShapePerimeterMap = map<shared_ptr<Shape>, double>;

auto sortByArea = [](shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr) {
        return false;
    }
    return (first->getArea() < second->getArea());
};

auto perimeterBiggerThan20 = [](shared_ptr<Shape> s) {
    if (s) {
        return (s->getPerimeter() > 20);
    }
    return false;
};

auto areaLessThanX = [x = 10](shared_ptr<Shape> s) {
    if (s) {
        return (s->getArea() < x);
    }
    return false;
};

void printCollectionElements(const Collection& collection) {
    for (const auto& element : collection) {
        if (element) {
            element->print();
        }
    }
}

void printAreas(const Collection& collection) {
    for (const auto& element : collection) {
        if (element) {
            cout << element->getArea() << endl;
        }
    }
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     function<bool(shared_ptr<Shape>)> predicate,
                                     string info) {
    auto iter = find_if(collection.begin(), collection.end(), predicate);
    if (*iter) {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
        return;
    }
    cout << "There is no shape matching predicate " << info << endl;
}

int main() {
    Collection shapes {
        make_shared<Circle>(2.0),
        make_shared<Circle>(3.0),
        nullptr,
        make_shared<Circle>(4.0),
        make_shared<Rectangle>(10.0, 5.0),
        make_shared<Square>(3.0),
        make_shared<Circle>(4.0),
        make_shared<Circle>(Color::Red),
        make_shared<Square>(Color::White),
        make_shared<Rectangle>(Color::Black),
    };
    printCollectionElements(shapes);

    cout << "Areas before sort: " << endl;
    printAreas(shapes);

    sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThanX, "area less than 10");

    cout << "alignof Circle = " << alignof(Circle) << endl;

    cout << "Pi = " << Circle::getPi() << endl;

    ShapePerimeterMap shapesPerimeter{};
    for(auto shape: shapes) {
        if(shape) {
            shapesPerimeter.emplace(shape, shape->getPerimeter());
        }
    }

    for(auto&& [shape, perimeter] : shapesPerimeter) {
        cout << "shape adress " << shape.get()  << " perimeter = " << perimeter << endl;
    }

    return 0;
}
