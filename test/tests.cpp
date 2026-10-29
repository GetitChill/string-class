//#include "/home/grant/Desktop/string/std_array_imp/myString.hpp"

#ifdef USE_HEAP
#include "/home/grant/Desktop/string/heap_implementation/myString_h.hpp"
#else
#include "/home/grant/Desktop/string/std_array_imp/myString.hpp"
#endif

#include <catch2/catch_test_macros.hpp>
#include <cstring>

using namespace gmc_string;


TEST_CASE( "string construction - default" ) {
	Mystring a;
	REQUIRE(a.str_array[0] == '\0');
}
TEST_CASE( "string construction - Mystring" ) {
// Char array
Mystring a("Hello World");

REQUIRE(a.str_array[0] == 'H');
REQUIRE(a.str_array[1] == 'e');
REQUIRE(a.str_array[2] == 'l');
REQUIRE(a.str_array[3] == 'l');
REQUIRE(a.str_array[4] == 'o');
REQUIRE(a.str_array[5] == ' ');
REQUIRE(a.str_array[6] == 'W');
REQUIRE(a.str_array[7] == 'o');
REQUIRE(a.str_array[8] == 'r');
REQUIRE(a.str_array[9] == 'l');
REQUIRE(a.str_array[10] == 'd');
REQUIRE(a.str_array[11] == '\0');


// Copy construction
Mystring b(a);

REQUIRE(b.str_array[0] == 'H');
REQUIRE(b.str_array[1] == 'e');
REQUIRE(b.str_array[2] == 'l');
REQUIRE(b.str_array[3] == 'l');
REQUIRE(b.str_array[4] == 'o');
REQUIRE(b.str_array[5] == ' ');
REQUIRE(b.str_array[6] == 'W');
REQUIRE(b.str_array[7] == 'o');
REQUIRE(b.str_array[8] == 'r');
REQUIRE(b.str_array[9] == 'l');
REQUIRE(b.str_array[10] == 'd');
REQUIRE(b.str_array[11] == '\0');
}

TEST_CASE("Simple Creation Check")
{
	Mystring a("Sup");
	REQUIRE(a[0] == 'S');
	REQUIRE(a[1] == 'u');
	REQUIRE(a[2] == 'p');
}

TEST_CASE("empty c string construction")
{
	Mystring a("");
	REQUIRE(a.str_array[0] == '\0');
	REQUIRE(a.length() == 0);
}

TEST_CASE("one character construction")
{
	Mystring a("A");
	REQUIRE(a[0] == 'A');
	REQUIRE(a[1] == '\0');
	REQUIRE(a.length() == 1);
}
//Does it include spaces?
//
TEST_CASE("space construction")
{
	Mystring a("Hello World");
	REQUIRE(a[5] == ' ');
	REQUIRE(a.length() == 11);
}

//Copy construction additional test
TEST_CASE("copy construction")
{
	Mystring a("Hello World");
	Mystring b(a);

	REQUIRE(a == b);
	REQUIRE(a.length() == b.length());
}

//Seperate strings - like if we did copy construction can I alter one without the other?
TEST_CASE("seperate strings")
{
	Mystring a("Hello World");
	Mystring b(a);

	b.str_array[0] = 'J';

	REQUIRE(a[0] == 'H');
	REQUIRE(b[0] == 'J');
}

//Emptry CC
TEST_CASE("Empty CC")
{
	Mystring a("");
	Mystring b(a);

	REQUIRE(b.length() == 0);
	REQUIRE(b[0] == '\0');
}


TEST_CASE("simple copy string =")
{
	Mystring a("Sup");
	Mystring b;
	
	b = a;
	REQUIRE(a==b);
}
TEST_CASE("ASSIGNMENT WORKS ")
{
	Mystring a("Apple");
	Mystring b("Bad");

	b = a;

	REQUIRE(b == Mystring("Apple"));
	REQUIRE(b.length() == 5);
}
TEST_CASE("from empty string")
{
	Mystring a("Sup");
	Mystring b("");

	a = b;

	REQUIRE(a[0] == '\0');
	REQUIRE(a.length() == 0);
}
TEST_CASE("Self Assignment")
{
	Mystring a("Sup");

	a = a;

	REQUIRE (a == Mystring("Sup"));
	REQUIRE(a.length() == 3);
}
TEST_CASE("equal to nothing")
{
	Mystring a("Sup");
	Mystring b("");

	a = b;

	REQUIRE (a == Mystring(""));
	REQUIRE(a.length() == 0);
}


TEST_CASE("Longer to shorter")
{
	Mystring a("Sup");
	Mystring b("a");

	b = a;

	REQUIRE (a == Mystring("Sup"));
	REQUIRE(a.length() == 3);
}

//Length shit
TEST_CASE("L of empty mystring")
{
	Mystring a("");

	REQUIRE(a.length() == 0);
}

TEST_CASE("L = 1")
{
	Mystring a("a");

	REQUIRE(a.length() == 1);
}

TEST_CASE("Hello World")
{
	Mystring a("Hello World");

	REQUIRE(a.length() == 11);
}

//Equality

TEST_CASE("Equal Strings")
{
	Mystring a("Hello");
	Mystring b("Hello");

	REQUIRE(a == b);
}

TEST_CASE("Not - Equal Strings")
{
	Mystring a("Hello");
	Mystring b("Hello!");

	REQUIRE_FALSE(a == b);
}

TEST_CASE("Equal Empty Strings")
{
	Mystring a("");
	Mystring b("");

	REQUIRE(a == b);
}

TEST_CASE("Case sensitive")
{
	Mystring a("Hello");
	Mystring b("hello");

	REQUIRE_FALSE(a == b);
}

TEST_CASE("InEqual Operator")
{
	Mystring a("Helloasodo");
	Mystring b("Hello");

	REQUIRE(a != b);
}

//Operator + testing

TEST_CASE("simple + strings")
{
	Mystring a("Hello");
	Mystring b("World");

	Mystring c = a + b;
	REQUIRE(c == Mystring("HelloWorld"));
}


TEST_CASE("simple + strings with space")
{
	Mystring a("Hello ");
	Mystring b("World");

	Mystring c = a + b;
	REQUIRE(c == Mystring("Hello World"));
}


TEST_CASE("Empty + fill string")
{
	Mystring a("");
	Mystring b("World");

	Mystring c = a + b;
	REQUIRE(c == Mystring("World"));
}


TEST_CASE("fill + empty string")
{
	Mystring a("Hello");
	Mystring b("");

	Mystring c = a + b;
	REQUIRE(c == Mystring("Hello"));
}


TEST_CASE("empty + empty")
{
	Mystring a("");
	Mystring b("");

	Mystring c = a + b;
	REQUIRE(c == Mystring(""));
}

//Does the operator change the arguments?

TEST_CASE("Change arguments?")
{
	Mystring a("Hello");
	Mystring b("World");

	Mystring c = a + b;
	REQUIRE(a == Mystring("Hello"));
	REQUIRE(b == Mystring("World"));
	REQUIRE(c == Mystring("HelloWorld"));
}


//Operator +=

TEST_CASE("+= ")
{
	Mystring a("H");
	Mystring b("W");

	a += b;
	REQUIRE(a == Mystring("HW"));
}

TEST_CASE("+= with space ")
{
	Mystring a("H ");
	Mystring b("W");

	a += b;
	REQUIRE(a == Mystring("H W"));
}

TEST_CASE("+ empty string")
{
	Mystring a("H");
	Mystring b("");

	a += b;
	REQUIRE(a == Mystring("H"));
}

TEST_CASE("empty + string")
{
	Mystring a("");
	Mystring b("W");

	a += b;
	REQUIRE(a == Mystring("W"));
}
//I don't know how to test print

TEST_CASE("Special Chars")
{
	Mystring a("!@#$%^&*");
	REQUIRE(a.length() == 8);

	REQUIRE(a[0] == '!');

	REQUIRE(a[1] == '@');

	REQUIRE(a[2] == '#');

	REQUIRE(a[3] == '$');

	REQUIRE(a[4] == '%');

	REQUIRE(a[5] == '^');

	REQUIRE(a[6] == '&');

	REQUIRE(a[7] == '*');
}


TEST_CASE("nums inside string")
{
	Mystring a("123456789");

	REQUIRE(a.length() == 9);

	REQUIRE(a == Mystring("123456789"));
}

//Long string test - whenever you get to it

TEST_CASE("strlen function test - to make sure it's doing what I think it's doing.")
{
	//This is going to add a null terminator to the end.
	const char a[] = "Hello World";
	REQUIRE(sizeof(*a) * strlen(a) == 11);


}
