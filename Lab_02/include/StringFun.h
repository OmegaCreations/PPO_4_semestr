#include <iostream>
#include <vector>

// MyString class
class MyString {
private:
    char* _string;
public:
    // Constructors
    MyString();
    MyString(const char* str);
    MyString(const MyString& other);
    ~MyString();

    // Operators
    MyString& operator=(const MyString& other);
    bool operator<(const MyString& other) const;
    bool operator>(const MyString& other) const;
    bool operator==(const MyString& other) const;

    // Other methods
    const char* str() const;
    std::size_t length() const;
};


// Less functor
class Less {
public:
    bool operator()(const MyString& a, const MyString& b);
};

// Greater functor
class Greater {
public:
    bool operator()(const MyString& a, const MyString& b);
};

// Length functor
class Length {
public:
    bool operator()(const MyString& a, const MyString& b);
};

// Other global methods
void PrintNames(const std::vector<MyString>& names);