#pragma once
#include <iostream>

class MyString {
private:
    char* data;
    int length;

    int getStrLen(const char* s) const;
    void copyStr(char* dest, const char* src) const;

public:
    MyString();
    MyString(const char* s);
    MyString(const MyString& other);
    ~MyString();

    MyString& operator=(const MyString& other);

    char& operator[](int index);
    const char& operator[](int index) const;

    int getLength() const;
    const char* c_str() const;
};