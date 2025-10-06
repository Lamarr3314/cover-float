#ifndef COVERFLOAT_H_INCLUDED
#define COVERFLOAT_H_INCLUDED

#include <stdint.h>
#include "../../riscv-isa-sim/softfloat/softfloat.h" // TODO: yuck fix paths

#ifdef __cplusplus
extern "C" {
#endif

/*
typedef enum {
    OP_ADD   = 1,
    OP_SUB   = 2,
    OP_MUL   = 3,
    OP_DIV   = 4,
    OP_FMA   = 5,
    OP_SQRT  = 6,
    OP_REM   = 7,
    OP_CFI   = 8,
    OP_CIF   = 9,
    OP_QC    = 10,
    OP_SC    = 11,
    OP_EQ    = 12,
    OP_CLASS = 13
} op_t;

typedef struct packed {
    bool     sign;
    uint16_t exp;
    uint16_t sig;
} intermFloat16_t;

typedef struct packed {
    bool     sign;
    uint16_t exp;
    uint32_t sig;
} intermFloat32_t;

typedef struct packed {
    bool     sign;
    uint16_t exp;
    uint64_t sig;
} intermFloat64_t;

typedef struct packed {
    bool     sign;
    uint32_t exp;
    uint64_t sig64;
    uint64_t sig0;
    uint64_t sigExtra;
} intermFloat128_t;

typedef struct packed {
    // reported by DUT
    uint32_t         op, rm;
    uint32_t         enablebools, exceptionbools;
    float128_t       a, b, c, result;
    // reported by reference
    float128_t       expectedResult;
    intermFloat128_t intermResult;
} coverfloat128_t;

typedef struct packed {
    // reported by DUT
    uint32_t        op, rm;
    uint32_t        enablebools, exceptionbools;
    float16_t       a, b, c, result;
    // reported by reference
    float16_t       expectedResult;
    intermFloat16_t intermResult;
} coverfloat16_t;

typedef struct packed {
    // reported by DUT
    uint32_t        op, rm;
    uint32_t        enablebools, exceptionbools;
    float32_t       a, b, c, result;
    // reported by reference
    float32_t       expectedResult;
    intermFloat32_t intermResult;
} coverfloat32_t;

typedef struct packed {
    // reported by DUT
    uint32_t        op, rm;
    uint32_t        enablebools, exceptionbools;
    float64_t       a, b, c, result;
    // reported by reference
    float64_t       expectedResult;
    intermFloat64_t intermResult;
} coverfloat64_t;

coverfloat16_t  coverfloat16Ref  (uint32_t op, float16_t  a, float16_t  b, float16_t  c, uint32_t rm, uint32_t enablebools); 
coverfloat32_t  coverfloat32Ref  (uint32_t op, float32_t  a, float32_t  b, float32_t  c, uint32_t rm, uint32_t enablebools);
coverfloat64_t  coverfloat64Ref  (uint32_t op, float64_t  a, float64_t  b, float64_t  c, uint32_t rm, uint32_t enablebools);
coverfloat128_t coverfloat128Ref (uint32_t op, float128_t a, float128_t b, float128_t c, uint32_t rm, uint32_t enablebools);

*/

void softFloat_clearFlags( uint_fast8_t );

uint_fast8_t softFloat_getFlags ();

void softFloat_setRoundingMode ( uint_fast8_t );

void softfloat_getIntermResults ( intermResult_t * );

/*********************************************************************************************
SOFT FLOAT FUNCTIONS WRAPPED WITH VOID RETURNING FUNCTIONS THAT PASS OUTPUTS BY REFERENCE
SINCE DPI-C CANNOT RETURN STRUCTS
**********************************************************************************************/

/*----------------------------------------------------------------------------
| Integer-to-floating-point conversion routines.
*----------------------------------------------------------------------------*/
void coverFloat_ui32_to_bf16( uint32_t, bfloat16_t * );
void coverFloat_ui32_to_f16( uint32_t, float16_t * );
void coverFloat_ui32_to_f32( uint32_t, float32_t * );
void coverFloat_ui32_to_f64( uint32_t, float64_t * );
#ifdef SOFTFLOAT_FAST_INT64
    extFloat80_t coverFloat_ui32_to_extF80( uint32_t, extFloat80_t * );
    float128_t coverFloat_ui32_to_f128( uint32_t, float128_t * );
#endif
void coverFloat_ui32_to_extF80M( uint32_t, extFloat80_t * );
void coverFloat_ui32_to_f128M( uint32_t, float128_t * );
void coverFloat_ui64_to_f16( uint64_t, float16_t * );
void coverFloat_ui64_to_f32( uint64_t, float32_t * );
void coverFloat_ui64_to_f64( uint64_t, float64_t * );
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_ui64_to_extF80( uint64_t, extFloat80_t * );
    void coverFloat_ui64_to_f128( uint64_t, float_128_t * );
#endif
void coverFloat_ui64_to_extF80M( uint64_t, extFloat80_t * );
void coverFloat_ui64_to_f128M( uint64_t, float128_t * );
void coverFloat_i32_to_bf16( int32_t, bfloat16_t * );
void coverFloat_i32_to_f16( int32_t, float16_t * );
void coverFloat_i32_to_f32( int32_t, float32_t * );
void coverFloat_i32_to_f64( int32_t, float64_t * );
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_i32_to_extF80( int32_t, extFloat80_t * );
    void coverFloat_i32_to_f128( int32_t, float128_t * );
#endif
void coverFloat_i32_to_extF80M( int32_t, extFloat80_t * );
void coverFloat_i32_to_f128M( int32_t, float128_t * );
void coverFloat_i64_to_f16( int64_t, float16_t *);
void coverFloat_i64_to_f32( int64_t, float32_t *);
void coverFloat_i64_to_f64( int64_t, float64_t *);
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_i64_to_extF80( int64_t, extFloat80_t * );
    void coverFloat_i64_to_f128( int64_t, float128_t * );
#endif
void coverFloat_i64_to_extF80M( int64_t, extFloat80_t * );
void coverFloat_i64_to_f128M( int64_t, float128_t * );

/*----------------------------------------------------------------------------
| 16-bit (half-precision) floating-point operations.
*----------------------------------------------------------------------------*/
uint_fast8_t coverFloat_f16_to_ui8( float16_t, uint_fast8_t, bool );
uint_fast16_t coverFloat_f16_to_ui16( float16_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_f16_to_ui32( float16_t, uint_fast8_t, bool );
uint_fast64_t coverFloat_f16_to_ui64( float16_t, uint_fast8_t, bool );
int_fast8_t coverFloat_f16_to_i8( float16_t, uint_fast8_t, bool );
int_fast16_t coverFloat_f16_to_i16( float16_t, uint_fast8_t, bool );
int_fast32_t coverFloat_f16_to_i32( float16_t, uint_fast8_t, bool );
int_fast64_t coverFloat_f16_to_i64( float16_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_f16_to_ui32_r_minMag( float16_t, bool );
uint_fast64_t coverFloat_f16_to_ui64_r_minMag( float16_t, bool );
int_fast32_t coverFloat_f16_to_i32_r_minMag( float16_t, bool );
int_fast64_t coverFloat_f16_to_i64_r_minMag( float16_t, bool );
void coverFloat_f16_to_f32( float16_t, float32_t * );
void coverFloat_f16_to_f64( float16_t, float64_t * );
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_f16_to_extF80( float16_t, extFloat80_t * );
    void coverFloat_f16_to_f128( float16_t, float128_t * );
#endif
void coverFloat_f16_to_extF80M( float16_t, extFloat80_t * );
void coverFloat_f16_to_f128M( float16_t, float128_t * );
void coverFloat_f16_roundToInt( float16_t, uint_fast8_t, bool, float16_t * );
void coverFloat_f16_add( float16_t, float16_t, float16_t * );
void coverFloat_f16_sub( float16_t, float16_t, float16_t * );
void coverFloat_f16_max( float16_t, float16_t, float16_t * );
void coverFloat_f16_min( float16_t, float16_t, float16_t * );
void coverFloat_f16_mul( float16_t, float16_t, float16_t * );
void coverFloat_f16_mulAdd( float16_t, float16_t, float16_t, float16_t * );
void coverFloat_f16_div( float16_t, float16_t, float16_t * );
void coverFloat_f16_rem( float16_t, float16_t, float16_t * );
void coverFloat_f16_sqrt( float16_t, float16_t * );
bool coverFloat_f16_eq( float16_t, float16_t );
bool coverFloat_f16_le( float16_t, float16_t );
bool coverFloat_f16_lt( float16_t, float16_t );
bool coverFloat_f16_eq_signaling( float16_t, float16_t );
bool coverFloat_f16_le_quiet( float16_t, float16_t );
bool coverFloat_f16_lt_quiet( float16_t, float16_t );
bool coverFloat_f16_isSignalingNaN( float16_t );
bool coverFloat_f16_sign( float16_t );
uint_fast16_t coverFloat_f16_classify( float16_t );
void coverFloat_f16_rsqrte7( float16_t, float16_t * );
void coverFloat_f16_recip7( float16_t, float16_t * );

/*----------------------------------------------------------------------------
| BFloat16 operations.
*----------------------------------------------------------------------------*/
uint_fast8_t coverFloat_bf16_to_ui8( bfloat16_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_bf16_to_ui32( bfloat16_t, uint_fast8_t, bool );
int_fast8_t coverFloat_bf16_to_i8( bfloat16_t, uint_fast8_t, bool );
int_fast32_t coverFloat_bf16_to_i32( bfloat16_t, uint_fast8_t, bool );
void coverFloat_bf16_to_f32( bfloat16_t, float32_t * );
void coverFloat_bf16_to_f64( bfloat16_t, float64_t * );
void coverFloat_bf16_add( bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_sub( bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_mul( bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_mulAdd( bfloat16_t, bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_div( bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_sqrt( bfloat16_t, bfloat16_t * );
void coverFloat_bf16_max( bfloat16_t, bfloat16_t, bfloat16_t * );
void coverFloat_bf16_min( bfloat16_t, bfloat16_t, bfloat16_t * );
bool coverFloat_bf16_eq( bfloat16_t, bfloat16_t );
bool coverFloat_bf16_le( bfloat16_t, bfloat16_t );
bool coverFloat_bf16_lt( bfloat16_t, bfloat16_t );
bool coverFloat_bf16_sign( bfloat16_t );
uint_fast16_t coverFloat_bf16_classify( bfloat16_t );
void coverFloat_bf16_rsqrte7( bfloat16_t, bfloat16_t * );
void coverFloat_bf16_recip7( bfloat16_t, bfloat16_t * );

/*----------------------------------------------------------------------------
| 32-bit (single-precision) floating-point operations.
*----------------------------------------------------------------------------*/
uint_fast16_t coverFloat_f32_to_ui16( float32_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_f32_to_ui32( float32_t, uint_fast8_t, bool );
uint_fast64_t coverFloat_f32_to_ui64( float32_t, uint_fast8_t, bool );
int_fast16_t coverFloat_f32_to_i16( float32_t, uint_fast8_t, bool );
int_fast32_t coverFloat_f32_to_i32( float32_t, uint_fast8_t, bool );
int_fast64_t coverFloat_f32_to_i64( float32_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_f32_to_ui32_r_minMag( float32_t, bool );
uint_fast64_t coverFloat_f32_to_ui64_r_minMag( float32_t, bool );
int_fast32_t coverFloat_f32_to_i32_r_minMag( float32_t, bool );
int_fast64_t coverFloat_f32_to_i64_r_minMag( float32_t, bool );
void coverFloat_f32_to_bf16( float32_t, bfloat16_t * );
void coverFloat_f32_to_f16( float32_t, float16_t * );
void coverFloat_f32_to_f64( float32_t, float64_t * );
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_f32_to_extF80( float32_t, extFloat80_t * );
    void coverFloat_f32_to_f128( float32_t, float128_t * );
#endif
void coverFloat_f32_to_extF80M( float32_t, extFloat80_t * );
void coverFloat_f32_to_f128M( float32_t, float128_t * );
void coverFloat_f32_roundToInt( float32_t, uint_fast8_t, bool, float32_t * );
void coverFloat_f32_add( float32_t, float32_t, float32_t * );
void coverFloat_f32_sub( float32_t, float32_t, float32_t * );
void coverFloat_f32_max( float32_t, float32_t, float32_t * );
void coverFloat_f32_min( float32_t, float32_t, float32_t * );
void coverFloat_f32_mul( float32_t, float32_t, float32_t * );
void coverFloat_f32_mulAdd( float32_t, float32_t, float32_t, float32_t * );
void coverFloat_f32_div( float32_t, float32_t, float32_t * );
void coverFloat_f32_rem( float32_t, float32_t, float32_t * );
void coverFloat_f32_sqrt( float32_t, float32_t * );
bool coverFloat_f32_eq( float32_t, float32_t );
bool coverFloat_f32_le( float32_t, float32_t );
bool coverFloat_f32_lt( float32_t, float32_t );
bool coverFloat_f32_eq_signaling( float32_t, float32_t );
bool coverFloat_f32_le_quiet( float32_t, float32_t );
bool coverFloat_f32_lt_quiet( float32_t, float32_t );
bool coverFloat_f32_isSignalingNaN( float32_t );
bool coverFloat_f32_sign( float32_t );
uint_fast16_t coverFloat_f32_classify( float32_t );
void coverFloat_f32_rsqrte7( float32_t, float32_t * );
void coverFloat_f32_recip7( float32_t, float32_t * );

/*----------------------------------------------------------------------------
| 64-bit (double-precision) floating-point operations.
*----------------------------------------------------------------------------*/
uint_fast32_t coverFloat_f64_to_ui32( float64_t, uint_fast8_t, bool );
uint_fast64_t coverFloat_f64_to_ui64( float64_t, uint_fast8_t, bool );
int_fast32_t coverFloat_f64_to_i32( float64_t, uint_fast8_t, bool );
int_fast64_t coverFloat_f64_to_i64( float64_t, uint_fast8_t, bool );
uint_fast32_t coverFloat_f64_to_ui32_r_minMag( float64_t, bool );
uint_fast64_t coverFloat_f64_to_ui64_r_minMag( float64_t, bool );
int_fast32_t coverFloat_f64_to_i32_r_minMag( float64_t, bool );
int_fast64_t coverFloat_f64_to_i64_r_minMag( float64_t, bool );
void coverFloat_f64_to_bf16( float64_t, bfloat16_t * );
void coverFloat_f64_to_f16( float64_t, float16_t * );
void coverFloat_f64_to_f32( float64_t, float32_t * );
#ifdef SOFTFLOAT_FAST_INT64
    void coverFloat_f64_to_extF80( float64_t, extFloat80_t * );
    void coverFloat_f64_to_f128( float64_t, float128_t * );
#endif
void coverFloat_f64_to_extF80M( float64_t, extFloat80_t * );
void coverFloat_f64_to_f128M( float64_t, float128_t * );
void coverFloat_f64_roundToInt( float64_t, uint_fast8_t, bool, float64_t * );
void coverFloat_f64_add( float64_t, float64_t, float64_t * );
void coverFloat_f64_sub( float64_t, float64_t, float64_t * );
void coverFloat_f64_max( float64_t, float64_t, float64_t * );
void coverFloat_f64_min( float64_t, float64_t, float64_t * );
void coverFloat_f64_mul( float64_t, float64_t, float64_t * );
void coverFloat_f64_mulAdd( float64_t, float64_t, float64_t, float64_t * );
void coverFloat_f64_div( float64_t, float64_t, float64_t * );
void coverFloat_f64_rem( float64_t, float64_t, float64_t * );
void coverFloat_f64_sqrt( float64_t, float64_t * );
bool coverFloat_f64_eq( float64_t, float64_t );
bool coverFloat_f64_le( float64_t, float64_t );
bool coverFloat_f64_lt( float64_t, float64_t );
bool coverFloat_f64_eq_signaling( float64_t, float64_t );
bool coverFloat_f64_le_quiet( float64_t, float64_t );
bool coverFloat_f64_lt_quiet( float64_t, float64_t );
bool coverFloat_f64_isSignalingNaN( float64_t );
bool coverFloat_f64_sign( float64_t );
uint_fast16_t coverFloat_f64_classify( float64_t );
void coverFloat_f64_rsqrte7( float64_t, float64_t * );
void coverFloat_f64_recip7( float64_t, float64_t * );


/*----------------------------------------------------------------------------
| 80-bit extended double-precision floating-point operations.
*----------------------------------------------------------------------------*/
#ifdef SOFTFLOAT_FAST_INT64
    uint_fast32_t coverFloat_extF80_to_ui32( extFloat80_t, uint_fast8_t, bool );
    uint_fast64_t coverFloat_extF80_to_ui64( extFloat80_t, uint_fast8_t, bool );
    int_fast32_t coverFloat_extF80_to_i32( extFloat80_t, uint_fast8_t, bool );
    int_fast64_t coverFloat_extF80_to_i64( extFloat80_t, uint_fast8_t, bool );
    uint_fast32_t coverFloat_extF80_to_ui32_r_minMag( extFloat80_t, bool );
    uint_fast64_t coverFloat_extF80_to_ui64_r_minMag( extFloat80_t, bool );
    int_fast32_t coverFloat_extF80_to_i32_r_minMag( extFloat80_t, bool );
    int_fast64_t coverFloat_extF80_to_i64_r_minMag( extFloat80_t, bool );
    void coverFloat_extF80_to_f16( extFloat80_t, float16_t * );
    void coverFloat_extF80_to_f32( extFloat80_t, float32_t * );
    void coverFloat_extF80_to_f64( extFloat80_t, float64_t * );
    void coverFloat_extF80_to_f128( extFloat80_t, float128_t * );
    void coverFloat_extF80_roundToInt( extFloat80_t, uint_fast8_t, bool, extFloat80_t * );
    void coverFloat_extF80_add( extFloat80_t, extFloat80_t, extFloat80_t * );
    void coverFloat_extF80_sub( extFloat80_t, extFloat80_t, extFloat80_t * );
    void coverFloat_extF80_mul( extFloat80_t, extFloat80_t, extFloat80_t * );
    void coverFloat_extF80_div( extFloat80_t, extFloat80_t, extFloat80_t * );
    void coverFloat_extF80_rem( extFloat80_t, extFloat80_t, extFloat80_t * );
    void coverFloat_extF80_sqrt( extFloat80_t, extFloat80_t * );
    bool coverFloat_extF80_eq( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_le( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_lt( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_eq_signaling( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_le_quiet( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_lt_quiet( extFloat80_t, extFloat80_t );
    bool coverFloat_extF80_isSignalingNaN( extFloat80_t );
#endif
uint_fast32_t coverFloat_extF80M_to_ui32( const extFloat80_t *, uint_fast8_t, bool );
uint_fast64_t coverFloat_extF80M_to_ui64( const extFloat80_t *, uint_fast8_t, bool );
int_fast32_t coverFloat_extF80M_to_i32( const extFloat80_t *, uint_fast8_t, bool );
int_fast64_t coverFloat_extF80M_to_i64( const extFloat80_t *, uint_fast8_t, bool );
uint_fast32_t coverFloat_extF80M_to_ui32_r_minMag( const extFloat80_t *, bool );
uint_fast64_t coverFloat_extF80M_to_ui64_r_minMag( const extFloat80_t *, bool );
int_fast32_t coverFloat_extF80M_to_i32_r_minMag( const extFloat80_t *, bool );
int_fast64_t coverFloat_extF80M_to_i64_r_minMag( const extFloat80_t *, bool );
void coverFloat_extF80M_to_f16( const extFloat80_t *, float16_t * );
void coverFloat_extF80M_to_f32( const extFloat80_t *, float32_t * );
void coverFloat_extF80M_to_f64( const extFloat80_t *, float64_t * );
void coverFloat_extF80M_to_f128M( const extFloat80_t *, float128_t * );
void
 coverFloat_extF80M_roundToInt(
     const extFloat80_t *, uint_fast8_t, bool, extFloat80_t * );
void coverFloat_extF80M_add( const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void coverFloat_extF80M_sub( const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void coverFloat_extF80M_mul( const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void coverFloat_extF80M_div( const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void coverFloat_extF80M_rem( const extFloat80_t *, const extFloat80_t *, extFloat80_t * );
void coverFloat_extF80M_sqrt( const extFloat80_t *, extFloat80_t * );
bool coverFloat_extF80M_eq( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_le( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_lt( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_eq_signaling( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_le_quiet( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_lt_quiet( const extFloat80_t *, const extFloat80_t * );
bool coverFloat_extF80M_isSignalingNaN( const extFloat80_t * );

/*----------------------------------------------------------------------------
| 128-bit (quadruple-precision) floating-point operations.
*----------------------------------------------------------------------------*/
#ifdef SOFTFLOAT_FAST_INT64
    uint_fast32_t coverFloat_f128_to_ui32( float128_t, uint_fast8_t, bool );
    uint_fast64_t coverFloat_f128_to_ui64( float128_t, uint_fast8_t, bool );
    int_fast32_t coverFloat_f128_to_i32( float128_t, uint_fast8_t, bool );
    int_fast64_t coverFloat_f128_to_i64( float128_t, uint_fast8_t, bool );
    uint_fast32_t coverFloat_f128_to_ui32_r_minMag( float128_t, bool );
    uint_fast64_t coverFloat_f128_to_ui64_r_minMag( float128_t, bool );
    int_fast32_t coverFloat_f128_to_i32_r_minMag( float128_t, bool );
    int_fast64_t coverFloat_f128_to_i64_r_minMag( float128_t, bool );
    void coverFloat_f128_to_f16( float128_t, float16_t * );
    void coverFloat_f128_to_f32( float128_t, float32_t * );
    void coverFloat_f128_to_f64( float128_t, float64_t * );
    void coverFloat_f128_to_extF80( float128_t, extFloat80_t * );
    void coverFloat_f128_roundToInt( float128_t, uint_fast8_t, bool, float128_t * );
    void coverFloat_f128_add( float128_t, float128_t, float128_t * );
    void coverFloat_f128_sub( float128_t, float128_t, float128_t * );
    void coverFloat_f128_mul( float128_t, float128_t, float128_t * );
    void coverFloat_f128_mulAdd( float128_t, float128_t, float128_t, float128_t * );
    void coverFloat_f128_div( float128_t, float128_t, float128_t * );
    void coverFloat_f128_rem( float128_t, float128_t, float128_t * );
    void coverFloat_f128_sqrt( float128_t, float128_t * );
    bool coverFloat_f128_eq( float128_t, float128_t );
    bool coverFloat_f128_le( float128_t, float128_t );
    bool coverFloat_f128_lt( float128_t, float128_t );
    bool coverFloat_f128_eq_signaling( float128_t, float128_t );
    bool coverFloat_f128_le_quiet( float128_t, float128_t );
    bool coverFloat_f128_lt_quiet( float128_t, float128_t );
    bool coverFloat_f128_isSignalingNaN( float128_t );
    uint_fast16_t coverFloat_f128_classify( float128_t );
#endif
uint_fast32_t coverFloat_f128M_to_ui32( const float128_t *, uint_fast8_t, bool );
uint_fast64_t coverFloat_f128M_to_ui64( const float128_t *, uint_fast8_t, bool );
int_fast32_t coverFloat_f128M_to_i32( const float128_t *, uint_fast8_t, bool );
int_fast64_t coverFloat_f128M_to_i64( const float128_t *, uint_fast8_t, bool );
uint_fast32_t coverFloat_f128M_to_ui32_r_minMag( const float128_t *, bool );
uint_fast64_t coverFloat_f128M_to_ui64_r_minMag( const float128_t *, bool );
int_fast32_t coverFloat_f128M_to_i32_r_minMag( const float128_t *, bool );
int_fast64_t coverFloat_f128M_to_i64_r_minMag( const float128_t *, bool );
void coverFloat_f128M_to_f16( const float128_t *, float16_t * );
void coverFloat_f128M_to_f32( const float128_t *, float32_t * );
void coverFloat_f128M_to_f64( const float128_t *, float64_t * );
void coverFloat_f128M_to_extF80M( const float128_t *, extFloat80_t * );
void coverFloat_f128M_roundToInt( const float128_t *, uint_fast8_t, bool, float128_t * );
void coverFloat_f128M_add( const float128_t *, const float128_t *, float128_t * );
void coverFloat_f128M_sub( const float128_t *, const float128_t *, float128_t * );
void coverFloat_f128M_mul( const float128_t *, const float128_t *, float128_t * );
void
 coverFloat_f128M_mulAdd(
     const float128_t *, const float128_t *, const float128_t *, float128_t *
 );
void coverFloat_f128M_div( const float128_t *, const float128_t *, float128_t * );
void coverFloat_f128M_rem( const float128_t *, const float128_t *, float128_t * );
void coverFloat_f128M_sqrt( const float128_t *, float128_t * );
bool coverFloat_f128M_eq( const float128_t *, const float128_t * );
bool coverFloat_f128M_le( const float128_t *, const float128_t * );
bool coverFloat_f128M_lt( const float128_t *, const float128_t * );
bool coverFloat_f128M_eq_signaling( const float128_t *, const float128_t * );
bool coverFloat_f128M_le_quiet( const float128_t *, const float128_t * );
bool coverFloat_f128M_lt_quiet( const float128_t *, const float128_t * );
bool coverFloat_f128M_isSignalingNaN( const float128_t * );

#ifdef __cplusplus
}
#endif

#endif