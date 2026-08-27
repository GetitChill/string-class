#include "/home/grant/Desktop/string/myString.hpp"
#include <catch2/catch_test_macros.hpp>


using namespace gmc_string;


//I need to find a way to automate this testing shit.

TEST_CASE( "string construction - default" ) {
	Mystring a;
	REQUIRE(a.str_array[0] == '\0');
}
TEST_CASE( "string construction - Mystring" ) {
	//Char array
	Mystring a("Hello World");
	REQUIRE(a.str_array[0] == 'H' && a.str_array[1] == 'e' &&a.str_array[2] == 'l' &&a.str_array[3] == 'l' &&a.str_array[4] == 'o' &&a.str_array[5] == ' ' && a.str_array[6] == 'W' &&a.str_array[7] == 'o' &&a.str_array[8] == 'r' &&a.str_array[9] == 'l' &&a.str_array[10] == 'd' && a.str_array[11] == '\0' );

	//Copy constructions
	Mystring b(a);
	REQUIRE(b.str_array[0] == 'H' && b.str_array[1] == 'e' &&b.str_array[2] == 'l' &&b.str_array[3] == 'l' &&b.str_array[4] == 'o' &&b.str_array[5] == ' ' && b.str_array[6] == 'W' &&b.str_array[7] == 'o' &&b.str_array[8] == 'r' &&b.str_array[9] == 'l' &&b.str_array[10] == 'd' && b.str_array[11] == '\0' );

	//Over the 100 length. This test is specifically for the c style array example. With the heap stuff we won't need to worry about this I don't think.
	Mystring long_test("Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since 1966, when designers at Letraset and James Mosley, the librarian at St Bride Printing Library in London, took a 1914 Cicero translation and scrambled it to make dummy text for Letraset's Body Type sheets. It has survived not only many decades, but also the leap into electronic typesetting, remaining essentially unchanged. It was popularised thanks to these sheets and more recently with desktop publishing software like Aldus PageMaker and Microsoft Word including versions of Lorem Ipsum. Why do we use it? It is a long established fact that a reader will be distracted by the readable content of a page when looking at its layout. The point of using Lorem Ipsum is that it has a more-or-less normal distribution of letters, as opposed to using 'Content here, content here', making it look like readable English. Many desktop publishing packages and web page editors now use Lorem Ipsum as their default model text, and a search for 'lorem ipsum' will uncover many web sites still in their infancy. Various versions have evolved over the years, sometimes by accident, sometimes on purpose injected humour and the like.")
	REQUIRE(b.str_array[100] == '\0')


	Mystring c(1234);
	REQUIRE(b.str_array[0] == '1' && b.str_array[1] == '2' &&b.str_array[2] == '3' &&b.str_array[3] == '4' &&b.str_array[4] == '\0');

	Mystring num_double(1.23456789);
	REQUIRE(b.str_array[0] == '1' && b.str_array[1] == '.' &&b.str_array[2] == '2' &&b.str_array[3] == '3' &&b.str_array[4] == '4'&&b.str_array[5] == '5' &&b.str_array[6] == '6' &&b.str_array[7] == '7'&&b.str_array[8] == '8' &&b.str_array[9] == '9');

	Mystring d("Hello ");
	Mystring e(d + "World");
	REQUIRE(e.str_array[0] == 'H' && e.str_array[1] == 'e' &&e.str_array[2] == 'l' &&e.str_array[3] == 'l' &&e.str_array[4] == 'o' &&e.str_array[5] == ' ' && e.str_array[6] == 'W' &&e.str_array[7] == 'o' &&e.str_array[8] == 'r' &&e.str_array[9] == 'l' &&e.str_array[10] == 'd' && e.str_array[11] == '\0' );


}

