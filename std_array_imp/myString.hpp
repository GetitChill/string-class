#pragma once

#include <array>
#include <cstddef>
#include <iostream>

namespace gmc_string
{
class Mystring
{
public:
    Mystring();
    Mystring(const Mystring& str);
    Mystring(const char a[]);

    Mystring& operator=(const Mystring& a);

    char operator[](std::size_t i) const;

    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;

    Mystring operator+(const Mystring& rhs) const;
    Mystring& operator+=(const Mystring& rhs);

    std::size_t length() const;

    std::ostream& print(std::ostream& os);

    //There's most definitly a way to make this private and maybe do a getter for it. I need this private :(
    static constexpr std::size_t max_length{100};
    std::array<char, max_length> str_array;
private:


};
void read(char* buf, int size);

std::ostream& operator<<(std::ostream& os, const Mystring& rh);
}



