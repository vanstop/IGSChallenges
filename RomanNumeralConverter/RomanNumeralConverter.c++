#include "RomanNumeralConverter.h"

int main() {

    string romanNumerals;
    int convertedValue = 0;

    while (romanNumerals != "Exit")
    {
        cout << "Please enter a roman numeral or [Exit] to leave the converter: " << endl;
        cin >> romanNumerals;

        convertedValue = ConvertRomanNumerals(romanNumerals);

        cout << "The roman numeral " << romanNumerals << " converted to a decimal number is equal: " << convertedValue << endl;

        cout << endl;
    }

    return 0;
}

int ConvertRomanNumerals(string romanNumeral) {

    int value = 0;

    for (size_t i = 0; i < romanNumeral.size(); i)
    {
        string currentRomanNumeral = (referenceValues.find(romanNumeral.substr(i, 2)) != referenceValues.end()) ? romanNumeral.substr(i, 2) : romanNumeral.substr(i, 1);

        value += referenceValues[currentRomanNumeral];

        i += currentRomanNumeral.length();
    }

    return value;
}