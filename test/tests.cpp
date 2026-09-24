#include "/home/grant/Desktop/string/std_array_imp/myString.hpp"
#include <catch2/catch_test_macros.hpp>


using namespace gmc_string;


TEST_CASE( "string construction - default" ) {
	Mystring a;
	REQUIRE(a.str_array[0] == '\0');
	REQUIRE(a.length() == 0);
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
	REQUIRE(a[5] == ',');
	REQUIRE(a[6] == ' ');
	REQUIRE(a.length() == 13);
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
	Mystring b("Bad);

	b = a;

	REQUIRE(b == Mystring("Apple");
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
