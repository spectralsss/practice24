#include "MyString.h"
#include <iostream>

int MyString::getStrLen(const char* s) const {
    if (s == nullptr) return 0;
    int len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}

void MyString::copyStr(char* dest, const char* src) const {
    if (dest == nullptr || src == nullptr) return;
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

MyString::MyString() {
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

MyString::MyString(const char* s) {
    if (s == nullptr) {
        length = 0;
        data = new char[1];
        data[0] = '\0';
    }
    else {
        length = getStrLen(s);
        data = new char[length + 1];
        copyStr(data, s);
    }
}

MyString::MyString(const MyString& other) {
    length = other.length;
    data = new char[length + 1];
    copyStr(data, other.data);
}

MyString::~MyString() {
    delete[] data;
}

MyString& MyString::operator=(const MyString& other) {
    if (this == &other) {
        return *this;
    }

    delete[] data;

    length = other.length;
    data = new char[length + 1];
    copyStr(data, other.data);

    return *this;
}

char& MyString::operator[](int index) {
    if (index < 0 || index >= length) {
        std::cerr << "Index out of bounds!" << std::endl;
        static char dummy = '\0';
        return dummy;
    }
    return data[index];
}

const char& MyString::operator[](int index) const {
    if (index < 0 || index >= length) {
        std::cerr << "Index out of bounds!" << std::endl;
        static char dummy = '\0';
        return dummy;
    }
    return data[index];
}

int MyString::getLength() const {
    return length;
}

const char* MyString::c_str() const {
    return data;
}