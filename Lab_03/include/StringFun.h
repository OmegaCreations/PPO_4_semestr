#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>

// MyString class
class MyString {
private:
    char* _string;
public:
    // Constructors
    MyString(const char* string);
    ~MyString();

    // Operators
    void* operator new(size_t size);
    void operator delete(void* p);

    // return string
    const char* str() const;
};

// MyStringContainer class
class MyStringContainer {
private:
    std::vector<MyString*> _container;
    static std::vector<std::function<bool(const MyString, const MyString)>> _functors;
public:
    // Container
    MyStringContainer();
    ~MyStringContainer();

    // Other methods
    // Add MyString obj to container
    void AddMStr(MyString* myString);

    // Sort MyStrings
    std::vector<MyString> GetSorted(const std::string& sort_type) const;

    // Static SortFunc returning vector of predefined functors
    static std::vector<std::function<bool(const MyString, const MyString)>> SortFunc();

};


// Other global methods
void PrintNames(const std::vector<MyString>& names);

