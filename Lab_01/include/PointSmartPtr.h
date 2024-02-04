#pragma once
#include <iostream>
#include <string>


// Named class
class Named {
    private:
    std::string _name;

    public:
    Named();
    std::string Name() const;

    // input operator overload
    friend void operator>>(const std::string& name, Named& obj);
};

// Point class
class Point : public Named {
    private:
    int _x;
    int _y;

    public:
    Point();
    Point(int x, int y);
    Point(int x, int y, std::string name);

    std::string getData();

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
    PointSmartPtr(Point* ptr);
    PointSmartPtr(const PointSmartPtr& other);
    ~PointSmartPtr();

    // Operators
    PointSmartPtr& operator=(const PointSmartPtr& other);
    Point& operator*() const;
    Point* operator->() const;
    
};