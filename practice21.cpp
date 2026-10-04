#include <iostream>
#include "MyString.h"

int main() {
    MyString s1;
    std::cout << "s1 (default): " << (s1.c_str() ? s1.c_str() : "nullptr")
        << ", len: " << s1.getLength() << "\n";

    MyString s2("Hello World");
    std::cout << "s2: " << s2.c_str() << ", len: " << s2.getLength() << "\n";

    MyString s3(s2);
    std::cout << "s3 (copy of s2): " << s3.c_str() << ", len: " << s3.getLength() << "\n";

    MyString s4;
    s4 = s2;
    std::cout << "s4 (assigned from s2): " << s4.c_str() << ", len: " << s4.getLength() << "\n";

    s2[0] = 'h';
    s2[6] = 'w';
    std::cout << "s2 modified via []: " << s2.c_str() << "\n";

    const MyString s5("Constant");
    std::cout << "s5[0] (const []): " << s5[0] << "\n";

    std::cout << "Testing out of bounds index: ";
    std::cout << s2[100] << "\n";
}