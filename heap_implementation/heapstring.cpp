#include "myString_h.hpp"


#include <iostream>
#include <cassert>
#include <array>
#include <iostream>

//Now we have to make some tests to make sure this thing passes.


using namespace gmc_string;
void read(char* buf, int size)
{
    char* max_p = buf + size;

	for(char c = getchar(); c != '\n' && buf <= max_p - 1; c = getchar(), ++buf)
	{
		*buf = c;
	}
	*buf = 0;
}

Mystring::Mystring() //Think about implementing something about length. 
{
	//I need to delete this thing somewhere.
	str_array = new char[1];
    str_array[0] = '\0';
}


// Copy Constructor
Mystring::Mystring(const Mystring& str)
{
	str_array = new char[sizeof(str)];
	
	//This is going to cause problems maybe - we have a const pointer trying to get a mutatable one/
    const char* str_ptr = str.str_array;
    int count = 0;
    for(;*str_ptr != '\0' && count <= max_length; ++str_ptr)
    {
        str_array[count] = *str_ptr;
        ++count;
    }
    str_array[count] = '\0';
}


Mystring::Mystring(const char a[])
{
	str_array = new char[sizeof(a)];
    const char* str_ptr = a;
    int count = 0;
    for(;*str_ptr != '\0' && count <= max_length ; ++str_ptr)
    {
        str_array[count] = *str_ptr;
        ++count;
    }
    str_array[count] = '\0';
}


Mystring& Mystring::operator=(const Mystring& a) 
{
	//So we want *this to be the same size as a
	str_array = new char[sizeof(a)];

    const char* str_ptr = a.str_array;
    int count = 0;
    for(;*str_ptr != '\0' && count <= max_length; ++str_ptr)
    {
        str_array[count] = *str_ptr;
        ++count;
    }

    //The *this-> syntax shit is trippy.
    str_array[count] = '\0';
    return *this;
}


char Mystring::operator[](std::size_t i) const
{
    return str_array[i];
}


bool Mystring::operator==(const Mystring& rhs) const
{
    //We need to have two pointers to each and literally just check/loop through each
    const char* lhs_pointer = str_array;
    const char* rhs_pointer = rhs.str_array;
    if (length() == rhs.length())
    {
        for(;*lhs_pointer != '\0' || *rhs_pointer != '\0'; ++lhs_pointer, ++rhs_pointer)
        {
            if (*lhs_pointer != *rhs_pointer )
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}


bool Mystring::operator!=(const Mystring& rhs) const
{
    if (*this == rhs)
    {
        return false;
    }
    else
    {
        return true;
    }
}

Mystring Mystring::operator+(const Mystring& rhs) const
{
    Mystring final_result;
    const char* p = str_array;
    char* final_pointer = final_result.str_array;
    for(;*p != '\0'; ++p,++final_pointer)
    {
        *final_pointer = *p;
    }
    //Now we want to add the right side.
    const char* sp = rhs.str_array;
    for(;*sp != '\0'; ++sp,++final_pointer)
    {
        *final_pointer = *sp;
    }
    *(final_pointer)= '\0';
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
    const char* sp = rhs.str_array;
    //end is where we start in the lhs string
    char* end = str_array;
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
    const char* p = str_array;
    for(;*p != '\0'; p++)
    {
        ++count;
    }
    return count;
}
std::ostream& Mystring::print(std::ostream& os)
{
    char* p = str_array;
    for(;*p != '\0' ; ++p)
    {
        os << *p;
    }

    return os;
}

std::ostream& operator<<(std::ostream& os, Mystring rhs)
{
    rhs.print(os);

    return os;
}
