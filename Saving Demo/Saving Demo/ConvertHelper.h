#pragma once

#include<string>

using namespace std;


// a method to help cast bool's to string
string btos(bool boolean)
{
	string trueString = "1", falseString = "0";
	if (boolean)
		return trueString;
	else
		return falseString;
};

// a method to help cast string's to bool
bool stob(string str)
{
	return stoi(str);
}

// a method to help cast an enumerator to string
string etos(int theTypeCastIntOfEnum)
{
	return to_string(theTypeCastIntOfEnum);
}