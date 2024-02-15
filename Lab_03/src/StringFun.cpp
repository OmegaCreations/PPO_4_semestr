#include "StringFun.h"

//MyString Methods ---------------------------------------------------------
// Constructors
MyString::MyString(const char* string) {
    _string = new char[strlen(string) + 1];
    strcpy(_string, string);
}

MyString::~MyString() {
    delete [] _string;
}

// Operators
void* MyString::operator new(size_t size) {
    std::cout << "[MyString] Overloading new operator with size: " << size << "\n";
    return ::operator new(size);
}

void MyString::operator delete(void *p) {
    std::cout << "[MyString] Overloading delete operator\n";
    free(p);
}

// Other methods
const char* MyString::str() const {
    return _string;
}

// MyStringContainer Methods -----------------------------------------------------
std::vector<std::function<bool(const MyString, const MyString)>> MyStringContainer::_functors= {
        [](const MyString& a, const MyString& b) {
            return strcmp(a.str(), b.str()) < 0;
            },
        [](const MyString& a, const MyString& b) {
            std::cout << "HIIIIIIl";
            return strcmp(a.str(), b.str()) > 0;
        }
};

// Constructors
MyStringContainer::MyStringContainer() {}

MyStringContainer::~MyStringContainer() {
    for( auto str : _container) {
        delete str;
    }
}

// Other functions
void MyStringContainer::AddMStr(MyString* myString) {
    _container.push_back(myString);
}

std::vector<std::function<bool(const MyString, const MyString)>> MyStringContainer::SortFunc() {
    return _functors;
}

std::vector<MyString> MyStringContainer::GetSorted(const std::string &sort_type) const {
    auto func = (sort_type == "ASC") ? _functors[0] : _functors[1];
    std::vector<MyString> sorted;
    std::cout << "\nWARTOSCI i ADRESY W LOOPIE:\n";
    for (const MyString* str_ptr : _container) {
        sorted.push_back(*str_ptr);
        std::cout << (*(_container[0])).str() << " " << _container[0] << "\n";
    }

    std::cout << "\nTEST WARTOSCI: " << (*(_container[0])).str() << "\n";
    PrintNames(sorted);
    std::sort(sorted.begin(), sorted.end(), func);
    return sorted;
}

// Other global methods
void PrintNames(const std::vector<MyString>& names) {
    std::cout << "PRINTED NAMES: ";
    for(const auto& name : names) {
        std::cout << name.str() << " ";
    }
    std::cout << "\n";
}