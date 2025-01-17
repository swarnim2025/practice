#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>
using namespace std;
# define ll long long
# define ld long double
// Function to get the integer value of a character (e.g., 'A' → 10)
int char_digit(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
 
}

// Function to get the character representation of a value (e.g., 10 → 'A')
char digit_char(int val) {
    if (val >= 0 && val <= 9) return val + '0';
    if (val >= 10 && val <= 15) return val - 10 + 'A';

}
// Function to split the input number into integer and fractional parts
void sep_num(const string &num, string &int_part, string &frac_part) {
    int pos_point = num.find('.');
    if (pos_point == string::npos) {
        int_part = num;
        frac_part = "";
    } else {
        int_part = num.substr(0, pos_point);
        frac_part = num.substr(pos_point + 1);
    }
}
// Function to convert the integer part of a number from any base to decimal
ll integerToDecimal(const string &int_part, int baseFrom) {
    ll result = 0;
    for (char c : int_part) {
        int value = char_digit(c);
    
        result = result * baseFrom + value;
    }
    return result;
}

// Function to convert the fractional part of a number from any base to decimal
ld fractionalToDecimal(const string &frac_part, int baseFrom) {
    ld result = 0.0;
    ld basePower = 1.0 / baseFrom;
    for (char c : frac_part) {
        int value = char_digit(c);
   
        result += value * basePower;
        basePower /= baseFrom;
    }
    return result;
}


// # define ld long ld
ld  base_decimal(const string & num,int basefrom){

string integer_part;
string frac_part;
sep_num(num,integer_part,frac_part);
ld res=(ld)(integerToDecimal(integer_part,basefrom));
res+=fractionalToDecimal(frac_part,basefrom);

return res;
}




// Function to convert the integer part of a decimal number to any base
string decimalToInteger(ll int_part, int baseTo) {
    if (int_part == 0) return "0";
    string result = "";
    while (int_part > 0) {
        result += digit_char(int_part % baseTo);
        int_part /= baseTo;
    }
    reverse(result.begin(), result.end());
    return result;
}

// Function to convert the fractional part of a decimal number to any base
string decimalToFractional(ld frac_part, int baseTo, int precision = 10) {
    string result = "";
    while (precision-- > 0 && frac_part > 0.0) {
        frac_part *= baseTo;
        int digit = static_cast<int>(frac_part);
        result += digit_char(digit);
        frac_part -= digit;
    }
    return result;
}



// Main function to convert a number from one base to another
string convertBase(const string &num, int baseFrom, int baseTo) {
    

    string int_part, frac_part;
    sep_num(num, int_part, frac_part);

    // Convert integer and fractional parts to decimal
    ll decimalInt = integerToDecimal(int_part, baseFrom);
    ld decimalFrac = fractionalToDecimal(frac_part, baseFrom);

    // Convert decimal to the target base
    string resultInt = decimalToInteger(decimalInt, baseTo);
    string resultFrac = decimalToFractional(decimalFrac, baseTo);

    // Combine integer and fractional parts
    if (resultFrac.empty())
        return resultInt;
    return resultInt + "." + resultFrac;
}


int main() {
    string num;
    int baseFrom, baseTo;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the base of the number (2, 8, 16 or 10): ";
    cin >> baseFrom;
    cout << "Enter the target base (2, 8, 16 or 10): ";
    cin >> baseTo;
   string result = convertBase(num, baseFrom, baseTo);
        cout << "Converted number: " << result << endl;

    return 0;
}
