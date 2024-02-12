#include "PointSmartPtr.h"

#include <utility>

// Named class methods
Named::Named() : _name("None"){}
Named::Named(std::string name) : _name(name){}
std::string Named::Name() const {
    return _name;
}

// operators
void operator>>(const std::string& name, Named& obj) {
    obj._name = name;
}

// Point class
// Constructors
Point::Point() : Named("None"), _x(0), _y(0) {}
Point::Point(std::nullptr_t): Named("None"), _x(0), _y(0) {}
Point::Point(int x, int y) : Named("None"), _x(x), _y(y){}
Point::Point(int x, int y, std::string  name) : Named(std::move(name)), _x(x), _y(y)  {}

// operators
Point Point::operator++(int) {
    Point temp = *this;
    temp._x++;
    temp._y++;
    return temp;
}

std::ostream& operator<<(std::ostream& os, const Point& point) {
    os << point.Name() << " [" << point._x<< "," << point._y << "]";
    return os;
}

// PointSmartPtr class
// Constructors
PointSmartPtr::PointSmartPtr(Point* ptr) : _ptr(ptr), _ref_count(new int(1)){}
PointSmartPtr::PointSmartPtr(const PointSmartPtr& other) : _ptr(other._ptr), _ref_count(other._ref_count) {
    (*_ref_count)++;
}

PointSmartPtr::~PointSmartPtr() {
    if((*_ref_count)-- == 0) {
        delete _ptr;
        delete _ref_count;
    }
}

// operators
PointSmartPtr& PointSmartPtr::operator=(const PointSmartPtr& other) {
    if(this != &other){
        if((*_ref_count)-- == 0){
            delete _ptr;
            delete _ref_count;
        }

        _ptr = other._ptr;
        _ref_count = other._ref_count;
        (*_ref_count)++;
    }

    return *this;
}

Point& PointSmartPtr::operator*() const {
    return *_ptr;
}

Point* PointSmartPtr::operator->() const {
    return _ptr;
}
