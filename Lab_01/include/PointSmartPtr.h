#pragma once
#include <iostream>
#include <string>


// Named class
class Named {
    private:
    std::string _name;

    public:
    Named();
    explicit Named(std::string name);

    // returns name
    std::string Name() const;

    // input operator overload
    friend void operator>>(const std::string& name, Named& obj);
};

// Point class
class Point : public Named {
    public:
    int _x;
    int _y;

    Point();
    explicit Point(std::nullptr_t);
    Point(int x, int y);
    Point(int x, int y, std::string name);

    // output operator overload
    friend std::ostream& operator<<(std::ostream& os, const Point& point);

    // increment operator
    Point operator++(int);
};

// PointSmartPtr class
class PointSmartPtr {
    private:
    Point* _ptr;
    int* _ref_count;

    public:

    // Constructors
    explicit PointSmartPtr(Point* ptr);
    PointSmartPtr(const PointSmartPtr& other);
    ~PointSmartPtr();

    // Operators
    PointSmartPtr& operator=(const PointSmartPtr& other);
    Point& operator*() const;
    Point* operator->() const;
    
};