#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;

// Function to get the integer value of a character (e.g., 'A' → 10)
int charToValue(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    throw invalid_argument("Invalid character for the base.");
}

// Function to get the character representation of a value (e.g., 10 → 'A')
char valueToChar(int val) {
    if (val >= 0 && val <= 9) return val + '0';
    if (val >= 10 && val <= 15) return val - 10 + 'A';
    throw invalid_argument("Invalid value for the base.");
}

// Function to convert the integer part of a number from any base to decimal
long long integerToDecimal(const string &intPart, int baseFrom) {
    long long result = 0;
    for (char c : intPart) {
        int value = charToValue(c);
        if (value >= baseFrom)
            throw invalid_argument("Invalid digit for the base.");
        result = result * baseFrom + value;
    }
    return result;
}

// Function to convert the fractional part of a number from any base to decimal
double fractionalToDecimal(const string &fracPart, int baseFrom) {
    double result = 0.0;
    double basePower = 1.0 / baseFrom;
    for (char c : fracPart) {
        int value = charToValue(c);
        if (value >= baseFrom)
            throw invalid_argument("Invalid digit for the base.");
        result += value * basePower;
        basePower /= baseFrom;
    }
    return result;
}

// Function to convert the integer part of a decimal number to any base
string decimalToInteger(long long intPart, int baseTo) {
    if (intPart == 0) return "0";
    string result = "";
    while (intPart > 0) {
        result += valueToChar(intPart % baseTo);
        intPart /= baseTo;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to convert the fractional part of a decimal number to any base
string decimalToFractional(double fracPart, int baseTo, int precision = 10) {
    string result = "";
    while (precision-- > 0 && fracPart > 0.0) {
        fracPart *= baseTo;
        int digit = static_cast<int>(fracPart);
        result += valueToChar(digit);
        fracPart -= digit;
    }
    return result;
}

// Function to split the input number into integer and fractional parts
void splitNumber(const string &num, string &intPart, string &fracPart) {
    size_t pointPos = num.find('.');
    if (pointPos == string::npos) {
        intPart = num;
        fracPart = "";
    } else {
        intPart = num.substr(0, pointPos);
        fracPart = num.substr(pointPos + 1);
    }
}

// Main function to convert a number from one base to another
string convertBase(const string &num, int baseFrom, int baseTo) {
    if (baseFrom != 2 && baseFrom != 8 && baseFrom != 16)
        throw invalid_argument("Only bases 2, 8, and 16 are supported.");
    if (baseTo != 2 && baseTo != 8 && baseTo != 16)
        throw invalid_argument("Only bases 2, 8, and 16 are supported.");

    string intPart, fracPart;
    splitNumber(num, intPart, fracPart);

    // Convert integer and fractional parts to decimal
    long long decimalInt = integerToDecimal(intPart, baseFrom);
    double decimalFrac = fractionalToDecimal(fracPart, baseFrom);

    // Convert decimal to the target base
    string resultInt = decimalToInteger(decimalInt, baseTo);
    string resultFrac = decimalToFractional(decimalFrac, baseTo);

    // Combine integer and fractional parts
    if (resultFrac.empty())
        return resultInt;
    return resultInt + "." + resultFrac;
}

// Driver code
int main() {
    string num;
    int baseFrom, baseTo;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the base of the number (2, 8, or 16): ";
    cin >> baseFrom;
    cout << "Enter the target base (2, 8, or 16): ";
    cin >> baseTo;

    try {
        string result = convertBase(num, baseFrom, baseTo);
        cout << "Converted number: " << result << endl;
    } catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
