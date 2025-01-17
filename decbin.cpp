
struct DecimalToBinary {
    vector<ll> st; // Stack to store binary digits of the integral part

    // Convert integral part of decimal to binary (as `ld`)
    ld dec_bin(ll m) {
        ld ans = 0;
        ld factor = 1; // Multiplier for constructing the binary number
        while (m > 0) {
            if (m & 1) {
                ans += factor; // Add the current binary digit
            }
            factor *= 10; // Shift left in base-10 representation
            m >>= 1; // Right shift to process the next bit
        }
        return ans;
    }

    // Convert fractional part of decimal to binary (as `ld`)
    ld decf_bin(ld f, int precision = 10) {
        ld ans = 0;
        ld factor = 1 / pow(10,1 ); // Initial scaling for fractional binary
        // debug(factor);
        for (int i = 0; i < precision; i++) {
            // debug(ans);
            f *= 2;
            if (f >= 1) {
                ans += factor; // Add the binary digit to the result
                f -= 1;        // Subtract the integer part
            }
            factor /= 10; // Scale down for the next binary digit
        }
        return ans;
    }

    // Convert decimal to binary (integral + fractional parts)
    ld convert(ld n, int precision = 10) {
        ll integral_part = (ll)n;       // Extract the integral part
        ld fractional_part = n - integral_part; // Extract the fractional part
        ld binary_integral = dec_bin(integral_part);
        ld binary_fractional = decf_bin(fractional_part, precision);
        return binary_integral + binary_fractional;
    }
};

// Convert binary (in `ld` form) to decimal
ld bin_to_dec(ld num, int precision = 10) {
    ll integral_part = (ll)num; // Extract integral part from binary input
    ld fractional_part = num - integral_part; // Extract fractional part from binary input

    // Convert integral part from binary to decimal
    ll decimal_integral = 0;
    ll multiplier = 1;
    while (integral_part > 0) {
        if (integral_part % 10) {
            decimal_integral += multiplier; // Add the decimal value of the binary digit
        }
        integral_part /= 10;
        multiplier *= 2; // Increase the place value
    }

    // Convert fractional part from binary to decimal
    ld decimal_fractional = 0;
    ld place_value = 0.5; // Initial place value for binary fractions
    for (int i = 0; i < precision && fractional_part > 0; i++) {
        fractional_part *= 10;
        if ((ll)fractional_part) {
            decimal_fractional += place_value; // Add the contribution of the binary digit
        }
        place_value /= 2; // Halve the place value for the next binary digit
        fractional_part -= (ll)fractional_part; // Remove the processed digit
    }

    return decimal_integral + decimal_fractional;
}
