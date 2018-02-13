
// Jacob McKenna
// Paul Huskee
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::getline;

int add_string(string numbers){
	
	istringstream iss(numbers); 

	string token;
	int sum = 0;
	int temp; 

	while(std::getline(iss, token, ',')) {
		sum += stoi(token);
	}

	return sum;
}

TEST_CASE("add_string function -- single integer"){

	REQUIRE( add_string("") == 0);
	REQUIRE( add_string("1") == 1);
	REQUIRE( add_string("2") == 2);
	REQUIRE( add_string("10") == 10);
	REQUIRE( add_string("1013") == 1013);
	REQUIRE( add_string("2013") == 2013);

}

TEST_CASE("add_string function -- N integers"){

	REQUIRE( add_string("1,2") == 3);
	REQUIRE( add_string("1,2,6,4,8,4,2") == 27);

}