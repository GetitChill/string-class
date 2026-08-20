#include "/home/grant/Desktop/string/string.hpp"
#include <catch2/catch_test_macros.hpp>


/*
unsigned int Factorial( unsigned int number ) {
    return number <= 1 ? number : Factorial(number-1)*number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( Factorial(1) == 1 );
    REQUIRE( Factorial(2) == 2 );
    REQUIRE( Factorial(3) == 6 );
    REQUIRE( Factorial(10) == 3628800 );
}

class string
{
	int test()
	{
		return 20;
	}


}


 *
 */
TEST_CASE( "string construction" ) {
	string a;
	REQUIRE( a.test() == 20 );


}
