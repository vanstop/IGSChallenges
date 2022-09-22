#include <iostream>
#include <string>
#include <map>

using namespace std;

	int ConvertRomanNumerals(string romanNumeral);

	map<string, int> referenceValues = {
        {"M", 1000}, {"CM", 900}, {"D", 500},
        {"CD", 400}, {"C",  100}, {"XC", 90},
        {"L",   50}, {"XL",  40}, {"X",  10},
        {"V",    5}, {"IX",   9}, {"IV",  4},
        {"I",    1}
    };

