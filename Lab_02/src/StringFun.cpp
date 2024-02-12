#include <cstring>
#include "StringFun.h"

// MyString class methods ---------------------------------------------
// Constructors
MyString::MyString() : _string(nullptr) {}
MyString::MyString(const char* str) : _string(nullptr) {
    if(str) {
        _string = new char[std::strlen(str) + 1];
        std::strcpy(_string, str);
    }
}

MyString::MyString(const MyString& other) : _string(nullptr) {
    if(other._string) {
        _string = new char[std::strlen(other._string) + 1];
        std::strcpy(_string, other._string);
    }
}

MyString::~MyString() {
    delete [] _string;
}

// Operators
MyString& MyString::operator=(const MyString &other) {
    if(this != &other) {
        delete [] _string;
        if(other._string) {
            _string = new char[std::strlen(other._string) + 1];
            std::strcpy(_string, other._string);
        } else {
            _string = nullptr;
        }
    }
    return *this;
}

bool MyString::operator<(const MyString &other) const {
    return std::strcmp(_string, other._string) < 0;
}

bool MyString::operator>(const MyString &other) const {
    return std::strcmp(_string, other._string) > 0;
}

bool MyString::operator==(const MyString &other) const {
    return std::strcmp(_string, other._string) == 0;
}

// Other methods
const char* MyString::str() const {
    return _string;
}

std::size_t MyString::length() const {
    return _string ? std::strlen(_string) : 0;
}

// Less functor ----------------------------------------------------
bool Less::operator()(const MyString &a, const MyString &b) {
    return a < b;
}

// Greater functor ----------------------------------------------------
bool Greater::operator()(const MyString &a, const MyString &b) {
    return a > b;
}

// Length functor ----------------------------------------------------
bool Length::operator()(const MyString &a, const MyString &b) {
    return a.length() < b.length();
}

//  PrintNames method ------------------------------------------------
void PrintNames(const std::vector<MyString>& names) {
    for( const auto& name: names) {
        std::cout << name.str() << " ";
    }
    std::cout << "\n\n";
}