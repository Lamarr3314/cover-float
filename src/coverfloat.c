#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "coverfloat.h"

void softFloat_clearFlags( uint_fast8_t clearMask) {
    softfloat_exceptionFlags &= ~clearMask;
}

uint_fast8_t softFloat_getFlags () {
    return softfloat_exceptionFlags;
}

void softFloat_setRoundingMode (uint_fast8_t rm) {
    softfloat_roundingMode = rm;
}

void softfloat_getIntermResults (intermResult_t * result) {

    result->sign     = softfloat_intermediateResult->sign;
    result->exp      = softfloat_intermediateResult->exp;
    result->sig64    = softfloat_intermediateResult->sig64;
    result->sig0     = softfloat_intermediateResult->sig0;
    result->sigExtra = softfloat_intermediateResult->sigExtra;

}

/*
AI CODE NEEDS MODIFICATION
*/

// Parse a hex string into a 128-bit integer (__uint128_t)
// __uint128_t parse_hex_128(const char *hex) {
//     __uint128_t value = 0;
//     while (*hex) {
//         char c = *hex++;
//         uint8_t digit = 0;

//         if (c >= '0' && c <= '9') digit = c - '0';
//         else if (c >= 'a' && c <= 'f') digit = 10 + (c - 'a');
//         else if (c >= 'A' && c <= 'F') digit = 10 + (c - 'A');
//         else continue; // skip non-hex chars

//         value = (value << 4) | digit;
//     }
//     return value;
// }
uint128_t parse_hex_128(const char *hex) {
    uint128_t value = {0, 0};

    while (*hex) {
        char c = *hex++;
        uint8_t digit;

        if (c >= '0' && c <= '9') digit = c - '0';
        else if (c >= 'a' && c <= 'f') digit = 10 + (c - 'a');
        else if (c >= 'A' && c <= 'F') digit = 10 + (c - 'A');
        else continue; // skip non-hex chars

        // Shift value left by 4 bits (multiply by 16)
        uint64_t new_upper = (value.upper << 4) | (value.lower >> 60);
        uint64_t new_lower = (value.lower << 4) | digit;

        value.upper = new_upper;
        value.lower = new_lower;
    }

    return value;
}





void reference_model( const uint32_t       * op,
                      const uint8_t        * rm,
                      const uint128_t      * a, 
                      const uint128_t      * b, 
                      const uint128_t      * c, 
                      const uint8_t        * operandFmt, 
                      const uint8_t        * resultFmt,

                      uint128_t            * result,
                      uint8_t              * flags ,
                      intermResult_t       * intermResult ) {
    
    
    // clear flags so we ger only triggered flags
    softFloat_clearFlags(0xFF);

    // set rounding mode
    softFloat_setRoundingMode(*rm);

    // nested switch statements to call softfloat functions

    switch (*op) {
        case OP_ADD: {
            
            switch (*operandFmt) {
                case FMT_SINGLE: {
                    float32_t af, bf, resultf;
                    UINT128_TO_FLOAT32(af, a);
                    UINT128_TO_FLOAT32(bf, b);
                    resultf = f32_add(af, bf);
                    FLOAT32_TO_UINT128(result, resultf);
                    break;
                }

                case FMT_DOUBLE: {
                    float64_t af, bf, resultf;
                    UINT128_TO_FLOAT64(af, a);
                    UINT128_TO_FLOAT64(bf, b);
                    resultf = f64_add(af, bf);
                    FLOAT64_TO_UINT128(result, resultf);
                    break;
                }

                /* ... */

            }
            break;
        }

        case OP_SUB: {
            
            switch (*operandFmt) {
                case FMT_SINGLE: {
                    float32_t af, bf, resultf;
                    UINT128_TO_FLOAT32(af, a);
                    UINT128_TO_FLOAT32(bf, b);
                    resultf = f32_sub(af, bf);
                    FLOAT32_TO_UINT128(result, resultf);
                    break;
                }

                case FMT_DOUBLE: {
                    float64_t af, bf, resultf;
                    UINT128_TO_FLOAT64(af, a);
                    UINT128_TO_FLOAT64(bf, b);
                    resultf = f64_add(af, bf);
                    FLOAT64_TO_UINT128(result, resultf);
                    break;
                }

                /* ... */

            }
            break;
        }

        /* ... */

    }

    *flags = softFloat_getFlags();
    softfloat_getIntermResults(intermResult);
}

// TODO needs complete refactor...
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *fin = fopen(argv[1], "r");
    if (!fin) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *fout = fopen(argv[2], "w");
    if (!fout) {
        perror("Error opening output file");
        fclose(fin);
        return EXIT_FAILURE;
    }

    char line[TEST_VECTOR_WIDTH_HEX_WITH_SEPARATORS + 2];
    while (fgets(line, sizeof(line), fin)) {
        // Strip newline
        line[strcspn(line, "\r\n")] = '\0';

        char     op_str[MAX_TOKEN_LEN];
        char     rm_str[MAX_TOKEN_LEN];
        char      a_str[MAX_TOKEN_LEN];
        char      b_str[MAX_TOKEN_LEN];
        char      c_str[MAX_TOKEN_LEN];
        char  opFmt_str[MAX_TOKEN_LEN];
        char    res_str[MAX_TOKEN_LEN];
        char resFmt_str[MAX_TOKEN_LEN];
        char  flags_str[MAX_TOKEN_LEN];

        if (line[0] == '/' && line[1] == '/') continue;

        if (sscanf(line, "%48[^_]_%48[^_]_%48s_%48[^_]_%48[^_]_%48s_%48[^_]_%48[^_]_%48s", 
            op_str, rm_str, a_str, b_str, c_str, opFmt_str, res_str, resFmt_str, flags_str) != 9) {
            fprintf(stderr, "Skipping malformed line: %s\n", line);
            continue;
        }


        // unpack test vector tokens into integers to pass to the reference model

        uint32_t       op        = parse_hex_128(op_str       ).lower;
        uint8_t        rm        = parse_hex_128(rm_str       ).lower;
        uint128_t      a         = parse_hex_128(a_str        )      ;
        uint128_t      b         = parse_hex_128(b_str        )      ;
        uint128_t      c         = parse_hex_128(c_str        )      ;
        uint8_t        opFmt     = parse_hex_128(opFmt_str    ).lower;
        uint8_t        resFmt    = parse_hex_128(resFmt_str   ).lower;
        uint128_t      res       = parse_hex_128(res_str      )      ;
        uint8_t        flags     = parse_hex_128(flags_str    ).lower;
        
        
        uint128_t      newRes;
        uint8_t        newFlags;
        intermResult_t intermRes;


        // Call reference model
                
        reference_model(&op,
                        &rm,
                        &a, 
                        &b, 
                        &c, 
                        &opFmt, 
                        &resFmt,

                        &newRes,
                        &newFlags,
                        &intermRes );

        // Write cover vector (append intermediate result to test vector)
        fprintf(fout, "%s_%04x_%032x_%064x%064x%064x\n", 
                line, intermRes.sign, intermRes.exp, intermRes.sig64, intermRes.sig0, intermRes.sigExtra);

        // confirm softfloat output matches testvectors
        if (res.upper   != newRes.upper   || res.lower   != newRes.lower ||     // outputs don't match
            flags != newFlags                                              ) {  // flags   don't match
            fprintf(stderr, "Error: testvector output doesn't match expected value\nTestVector output: %x\nExpected output: %x", res, newRes);
            fclose(fin);
            fclose(fout);
            return EXIT_FAILURE;
        }
    }

    fclose(fin);
    fclose(fout);

    return EXIT_SUCCESS;
}
