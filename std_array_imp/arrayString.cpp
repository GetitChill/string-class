#include "myString.hpp"


#include <iostream>
#include <cassert>
#include <array>
#include <iostream>

//Now we have to make some tests to make sure this thing passes.


using namespace gmc_string;

Mystring::Mystring()
{
    str_array[0] = '\0';
}


// Copy Constructor
Mystring::Mystring(const Mystring& str)
{
    const char* str_ptr = str.str_array.data();
	std::strcpy(str_array.data(), str_ptr);
}


Mystring::Mystring(const char a[])
{
    const char* str_ptr = a;
    int count = 0;
    
	if(strlen(str_array.data())>strlen(a))
	{
		std::strcpy(str_array.data(),a);
	}
}


Mystring& Mystring::operator=(const Mystring& a) //we're altering the lhs and not the rhs
{
	//so we're just putting the chars from a into object
    const char* str_ptr = a.str_array.data();
	std::strcpy(str_array.data(), str_ptr);
    return *this;
}


char Mystring::operator[](std::size_t i) const
{
    return str_array[i];
}


bool Mystring::operator==(const Mystring& rhs) const
{
    //We need to have two pointers to each and literally just check/loop through each
    const char* lhs_pointer = str_array.data();
    const char* rhs_pointer = rhs.str_array.data();
	//strcmp returns 0 for true
	return !(std::strcmp(lhs_pointer, rhs_pointer));
}


bool Mystring::operator!=(const Mystring& rhs) const
{
	return (*this == rhs);
}

Mystring Mystring::operator+(const Mystring& rhs) const
{
    Mystring final_result;
    const char* p = str_array.data();
    char* final_pointer = final_result.str_array.data();
	std::strcat(final_pointer, p);

	//Now we want to add the right side.
    const char* sp = rhs.str_array.data();
	std::strcat(final_pointer,sp);

	return Mystring(final_result);
}

Mystring& Mystring::operator+=(const Mystring& rhs)
{
        //Now we want to add to the current *this string
    //We need to find the end of the string
    int lhs_length = length();
    //char* p = str_array.data();
    //I literally just need to add to the end of the array. FFS!!!
        //rhs
    const char* sp = rhs.str_array.data();
    //end is where we start in the lhs string
    char* end = str_array.data();
    for( end += lhs_length; *sp != '\0'; ++end,++sp )
    {
        *end = *sp;
    }
    *end = '\0';
    return *this;

}

size_t Mystring::length() const
{
    size_t count = 0;
    const char* p = str_array.data();
    for(;*p != '\0'; p++)
    {
        ++count;
    }
    return count;
}

std::ostream& Mystring::print(std::ostream& os) const 
{
    const char* p = str_array.data();
    for(;*p != '\0' ; ++p)
    {
        os << *p;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os,Mystring rhs)
{
    rhs.print(os);

    return os;
}
