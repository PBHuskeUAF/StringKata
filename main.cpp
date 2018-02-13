
// Jacob McKenna
// Paul Huskee
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>

using std::string;

int add_string(string numbers){

	return 0;
}

TEST_CASE("add_string function"){
	REQUIRE( add_string("") == 0);
	REQUIRE( add_string("1") == 1);


}