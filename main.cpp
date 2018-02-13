
// Jacob McKenna
// Paul Huskee
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::istringstream;

int add_string(string numbers){
	
	istringstream iss; 
	iss.str(numbers);
	
	int sum = 0;
	
	iss >> sum;
	
	return sum;
}

TEST_CASE("add_string function"){

	REQUIRE( add_string("") == 0);
	REQUIRE( add_string("1") == 1);
	REQUIRE( add_string("2") == 2);
	REQUIRE( add_string("10") == 10);
	REQUIRE( add_string("1013") == 1013);
	REQUIRE( add_string("2013") == 2013);

}