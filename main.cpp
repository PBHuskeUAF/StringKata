
// String_Kata.cpp : Defines the entry point for the console application.
//
//#include "stdafx.h"
// Paul Huskee
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <ctype.h>
using std::string;
using std::cout;
using std::endl;
using std::istringstream;
using std::getline;

int eliminate_White_Space(string & token, int start, int length)
{
	int index = start;
	while (index < length && isspace(token[index]))//get rid of leading whitespace
	{
		index++;
	}
	if (index < length)
		return index;
	else
		return length;
}

int add_string(string numbers) {

	istringstream iss(numbers);

	string token;
	int sum = 0;
	int temp;
	int token_Length = 0;
	//int index = 0;
	string temp_token;
	int start_Token = 0;
	while (std::getline(iss, token, ',')) {
		token_Length = token.size();

		if (token_Length==1)
		{
			sum += stoi(token); //add in the last number
			start_Token = 0;
		} 
		else
		{
			for (int index = start_Token; index < token_Length; index++)
			{
				start_Token = eliminate_White_Space(token, start_Token, token_Length);
				if (isspace(token[index]) && start_Token < token_Length) //capture numbers before the white space in a token
				{
					temp_token = token.substr(start_Token, index);
					sum += stoi(temp_token); //add in the last number
					start_Token += temp_token.size();
				}
				
			}
			if (start_Token < token_Length)
			{
				temp_token = token.substr(start_Token, token_Length);
				sum += stoi(temp_token); //add in the last number
				start_Token = 0;
			}
		}
	}
return sum;
}

TEST_CASE("add_string function -- single integer") {

	REQUIRE(add_string("") == 0);
	REQUIRE(add_string("1") == 1);
	REQUIRE(add_string("2") == 2);
	REQUIRE(add_string("10") == 10);
	REQUIRE(add_string("1013") == 1013);
	REQUIRE(add_string("2013") == 2013);

}

TEST_CASE("add_string function -- comma separated integers") {

	REQUIRE(add_string("1,2") == 3);
	REQUIRE(add_string("1,2,6,4,8,4,2") == 27);

}

TEST_CASE("add_string function -- comma or whitespace separated integers") {

	REQUIRE(add_string("1 2") == 3);
	REQUIRE(add_string("1,2\n6") == 9);
	REQUIRE(add_string("1,2\n6\n") == 9);
	REQUIRE(add_string("1,2\n6  ") == 9);
	REQUIRE(add_string("1,2\n6,4,8,4") == 25);
	REQUIRE(add_string("4,4\n2\n") == 10);
	REQUIRE(add_string("1,2\n6,4,4\n2\n") == 19);

}
