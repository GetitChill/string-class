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
	~Mystring();
    Mystring(const Mystring& str);
    Mystring(const char a[]);

	    Mystring& operator=(const Mystring& a);

    char operator[](std::size_t i) const;

    bool operator==(const Mystring& rhs) const;
    bool operator!=(const Mystring& rhs) const;

    Mystring operator+(const Mystring& rhs) const;
    Mystring& operator+=(const Mystring& rhs);

	//print declaration 
	std::ostream& print(std::ostream& os);
    std::size_t length() const;


    static constexpr std::size_t max_length{100};
	char* str_array;



private:


};

std::ostream& operator<<(std::ostream& os, Mystring& rhs);
}

