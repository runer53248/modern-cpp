#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Circle.hpp"
#include "Rectangle.hpp"
#include "Shape.hpp"
#include "Square.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

bool sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second) {
    if (first == nullptr || second == nullptr) {
        return false;
    }
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s) {
    if (s) {
        return (s->getPerimeter() > 20);
    }
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s) {
    if (s) {
        return (s->getArea() < 10);
    }
    return false;
}

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
                                     bool (*predicate)(shared_ptr<Shape> s),
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
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    return 0;
}
