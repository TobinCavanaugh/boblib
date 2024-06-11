//
// Created by tobin on 6/6/2024.
//

#include "mat.h"


i64 mat_absi(i64 x) {
    if (x < 0) { x *= -1; }
    return x;
}

/// Calculates the power of the base to the exponent
/// \param base The base value
/// \param exp The exponent
/// \return The resulting value, 0 is the error value, indicating an overflow
/// Thanks to https://stackoverflow.com/a/101613/21769995
u64 mat_powu64(u64 base, u64 exp) {
    u64 result = 1;

    //TODO Duffs device good application??
    while (true) {
        if (exp & 1) {
            u64 tmp = result * base;
            if (tmp < result) {
                return 0;
            }
            result = tmp;
        }
        exp >>= 1;
        if (!exp) {
            break;
        }

        base *= base;
    }
    return result;
}

/// Calculates the power of the base to the exponent
/// \param base The base value
/// \param exp The exponent, unsigned as to not allow making a value smaller
/// than one
/// \return The resulting value, 0 is the error value, indicating an overflow
/// Thanks to https://stackoverflow.com/a/101613/21769995
i64 mat_powi64(i64 base, u64 exp) {
    u64 res = mat_powu64(base, exp);
}