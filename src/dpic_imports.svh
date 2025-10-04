
/*============================================================================

This C header file is part of the SoftFloat IEEE Floating-Point Arithmetic
Package, Release 3d, by John R. Hauser.

Copyright 2011, 2012, 2013, 2014, 2015, 2016, 2017 The Regents of the
University of California.  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/


/*============================================================================
| Note:  If SoftFloat is made available as a general library for programs to
| use, it is strongly recommended that a platform-specific version of this
| header, "softfloat.h", be created that folds in "softfloat_types.h" and that
| eliminates all dependencies on compile-time macros.
*============================================================================*/

/*----------------------------------------------------------------------------
| Routine to raise any or all of the software floating-point exception flags.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic void softfloat_raiseFlags( input unsigned byte );

/*----------------------------------------------------------------------------
| Integer-to-floating-point conversion routines.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic bfloat16_t ui32_to_bf16( input unsigned int );
import "DPI-C" function automatic float16_t ui32_to_f16( input unsigned int );
import "DPI-C" function automatic float32_t ui32_to_f32( input unsigned int );
import "DPI-C" function automatic float64_t ui32_to_f64( input unsigned int );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t ui32_to_extF80( input unsigned int );
    import "DPI-C" function automatic float128_t ui32_to_f128( input unsigned int );
`endif
import "DPI-C" function automatic void ui32_to_extF80M( input unsigned int, output extFloat80_t );
import "DPI-C" function automatic void ui32_to_f128M( input unsigned int, output float128_t );
import "DPI-C" function automatic float16_t ui64_to_f16( input unsigned longint );
import "DPI-C" function automatic float32_t ui64_to_f32( input unsigned longint );
import "DPI-C" function automatic float64_t ui64_to_f64( input unsigned longint );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t ui64_to_extF80( input unsigned longint );
    import "DPI-C" function automatic float128_t ui64_to_f128( input unsigned longint );
`endif
import "DPI-C" function automatic void ui64_to_extF80M( input unsigned longint, output extFloat80_t );
import "DPI-C" function automatic void ui64_to_f128M( input unsigned longint, output float128_t );
import "DPI-C" function automatic bfloat16_t i32_to_bf16( input signed int );
import "DPI-C" function automatic float16_t i32_to_f16( input signed int );
import "DPI-C" function automatic float32_t i32_to_f32( input signed int );
import "DPI-C" function automatic float64_t i32_to_f64( input signed int );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t i32_to_extF80( input signed int );
    import "DPI-C" function automatic float128_t i32_to_f128( input signed int );
`endif
import "DPI-C" function automatic void i32_to_extF80M( input signed int, output extFloat80_t );
import "DPI-C" function automatic void i32_to_f128M( input signed int, output float128_t );
import "DPI-C" function automatic float16_t i64_to_f16( input signed longint );
import "DPI-C" function automatic float32_t i64_to_f32( input signed longint );
import "DPI-C" function automatic float64_t i64_to_f64( input signed longint );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t i64_to_extF80( input signed longint );
    import "DPI-C" function automatic float128_t i64_to_f128( input signed longint );
`endif
import "DPI-C" function automatic void i64_to_extF80M( input signed longint, output extFloat80_t );
import "DPI-C" function automatic void i64_to_f128M( input signed longint, output float128_t );

/*----------------------------------------------------------------------------
| 16-bit (half-precision) floating-point operations.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic unsigned byte f16_to_ui8( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned shortint f16_to_ui16( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f16_to_ui32( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned longint f16_to_ui64( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed byte f16_to_i8( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed shortint f16_to_i16( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int f16_to_i32( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed longint f16_to_i64( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f16_to_ui32_r_minMag( input float16_t, input bit );
import "DPI-C" function automatic unsigned longint f16_to_ui64_r_minMag( input float16_t, input bit );
import "DPI-C" function automatic signed int f16_to_i32_r_minMag( input float16_t, input bit );
import "DPI-C" function automatic signed longint f16_to_i64_r_minMag( input float16_t, input bit );
import "DPI-C" function automatic float32_t f16_to_f32( input float16_t );
import "DPI-C" function automatic float64_t f16_to_f64( input float16_t );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t f16_to_extF80( input float16_t );
    import "DPI-C" function automatic float128_t f16_to_f128( input float16_t );
`endif
import "DPI-C" function automatic void f16_to_extF80M( input float16_t, output extFloat80_t );
import "DPI-C" function automatic void f16_to_f128M( input float16_t, output float128_t );
import "DPI-C" function automatic float16_t f16_roundToInt( input float16_t, input unsigned byte, input bit );
import "DPI-C" function automatic float16_t f16_add( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_sub( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_max( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_min( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_mul( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_mulAdd( input float16_t, input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_div( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_rem( input float16_t, input float16_t );
import "DPI-C" function automatic float16_t f16_sqrt( input float16_t );
import "DPI-C" function automatic bit f16_eq( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_le( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_lt( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_eq_signaling( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_le_quiet( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_lt_quiet( input float16_t, input float16_t );
import "DPI-C" function automatic bit f16_isSignalingNaN( input float16_t );
import "DPI-C" function automatic bit f16_sign( input float16_t );
import "DPI-C" function automatic unsigned shortint f16_classify( input float16_t );
import "DPI-C" function automatic float16_t f16_rsqrte7( input float16_t );
import "DPI-C" function automatic float16_t f16_recip7( input float16_t );

/*----------------------------------------------------------------------------
| BFloat16 operations.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic unsigned byte bf16_to_ui8( input bfloat16_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int bf16_to_ui32( input bfloat16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed byte bf16_to_i8( input bfloat16_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int bf16_to_i32( input bfloat16_t, input unsigned byte, input bit );
import "DPI-C" function automatic float32_t bf16_to_f32( input bfloat16_t );
import "DPI-C" function automatic float64_t bf16_to_f64( input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_add( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_sub( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_mul( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_mulAdd( input bfloat16_t, input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_div( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_sqrt( input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_max( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_min( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bit bf16_eq( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bit bf16_le( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bit bf16_lt( input bfloat16_t, input bfloat16_t );
import "DPI-C" function automatic bit bf16_sign( input bfloat16_t );
import "DPI-C" function automatic unsigned shortint bf16_classify( input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_rsqrte7( input bfloat16_t );
import "DPI-C" function automatic bfloat16_t bf16_recip7( input bfloat16_t );

/*----------------------------------------------------------------------------
| 32-bit (single-precision) floating-point operations.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic unsigned shortint f32_to_ui16( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f32_to_ui32( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned longint f32_to_ui64( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed shortint f32_to_i16( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int f32_to_i32( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed longint f32_to_i64( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f32_to_ui32_r_minMag( input float32_t, input bit );
import "DPI-C" function automatic unsigned longint f32_to_ui64_r_minMag( input float32_t, input bit );
import "DPI-C" function automatic signed int f32_to_i32_r_minMag( input float32_t, input bit );
import "DPI-C" function automatic signed longint f32_to_i64_r_minMag( input float32_t, input bit );
import "DPI-C" function automatic bfloat16_t f32_to_bf16( input float32_t );
import "DPI-C" function automatic float16_t f32_to_f16( input float32_t );
import "DPI-C" function automatic float64_t f32_to_f64( input float32_t );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t f32_to_extF80( input float32_t );
    import "DPI-C" function automatic float128_t f32_to_f128( input float32_t );
`endif
import "DPI-C" function automatic void f32_to_extF80M( input float32_t, output extFloat80_t );
import "DPI-C" function automatic void f32_to_f128M( input float32_t, output float128_t );
import "DPI-C" function automatic float32_t f32_roundToInt( input float32_t, input unsigned byte, input bit );
import "DPI-C" function automatic float32_t f32_add( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_sub( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_max( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_min( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_mul( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_mulAdd( input float32_t, input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_div( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_rem( input float32_t, input float32_t );
import "DPI-C" function automatic float32_t f32_sqrt( input float32_t );
import "DPI-C" function automatic bit f32_eq( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_le( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_lt( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_eq_signaling( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_le_quiet( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_lt_quiet( input float32_t, input float32_t );
import "DPI-C" function automatic bit f32_isSignalingNaN( input float32_t );
import "DPI-C" function automatic bit f32_sign( input float32_t );
import "DPI-C" function automatic unsigned shortint f32_classify( input float32_t );
import "DPI-C" function automatic float32_t f32_rsqrte7( input float32_t );
import "DPI-C" function automatic float32_t f32_recip7( input float32_t );

/*----------------------------------------------------------------------------
| 64-bit (double-precision) floating-point operations.
*----------------------------------------------------------------------------*/
import "DPI-C" function automatic unsigned int f64_to_ui32( input float64_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned longint f64_to_ui64( input float64_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int f64_to_i32( input float64_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed longint f64_to_i64( input float64_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f64_to_ui32_r_minMag( input float64_t, input bit );
import "DPI-C" function automatic unsigned longint f64_to_ui64_r_minMag( input float64_t, input bit );
import "DPI-C" function automatic signed int f64_to_i32_r_minMag( input float64_t, input bit );
import "DPI-C" function automatic signed longint f64_to_i64_r_minMag( input float64_t, input bit );
import "DPI-C" function automatic bfloat16_t f64_to_bf16( input float64_t );
import "DPI-C" function automatic float16_t f64_to_f16( input float64_t );
import "DPI-C" function automatic float32_t f64_to_f32( input float64_t );
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic extFloat80_t f64_to_extF80( input float64_t );
    import "DPI-C" function automatic float128_t f64_to_f128( input float64_t );
`endif
import "DPI-C" function automatic void f64_to_extF80M( input float64_t, output extFloat80_t );
import "DPI-C" function automatic void f64_to_f128M( input float64_t, output float128_t );
import "DPI-C" function automatic float64_t f64_roundToInt( input float64_t, input unsigned byte, input bit );
import "DPI-C" function automatic float64_t f64_add( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_sub( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_max( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_min( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_mul( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_mulAdd( input float64_t, input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_div( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_rem( input float64_t, input float64_t );
import "DPI-C" function automatic float64_t f64_sqrt( input float64_t );
import "DPI-C" function automatic bit f64_eq( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_le( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_lt( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_eq_signaling( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_le_quiet( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_lt_quiet( input float64_t, input float64_t );
import "DPI-C" function automatic bit f64_isSignalingNaN( input float64_t );
import "DPI-C" function automatic bit f64_sign( input float64_t );
import "DPI-C" function automatic unsigned shortint f64_classify( input float64_t );
import "DPI-C" function automatic float64_t f64_rsqrte7( input float64_t );
import "DPI-C" function automatic float64_t f64_recip7( input float64_t );


/*----------------------------------------------------------------------------
| 80-bit extended double-precision floating-point operations.
*----------------------------------------------------------------------------*/

/*
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic unsigned int extF80_to_ui32( input extFloat80_t, input unsigned byte, input bit );
    import "DPI-C" function automatic unsigned longint extF80_to_ui64( input extFloat80_t, input unsigned byte, input bit );
    import "DPI-C" function automatic signed int extF80_to_i32( input extFloat80_t, input unsigned byte, input bit );
    import "DPI-C" function automatic signed longint extF80_to_i64( input extFloat80_t, input unsigned byte, input bit );
    import "DPI-C" function automatic unsigned int extF80_to_ui32_r_minMag( input extFloat80_t, input bit );
    import "DPI-C" function automatic unsigned longint extF80_to_ui64_r_minMag( input extFloat80_t, input bit );
    import "DPI-C" function automatic signed int extF80_to_i32_r_minMag( input extFloat80_t, input bit );
    import "DPI-C" function automatic signed longint extF80_to_i64_r_minMag( input extFloat80_t, input bit );
    import "DPI-C" function automatic float16_t extF80_to_f16( input extFloat80_t );
    import "DPI-C" function automatic float32_t extF80_to_f32( input extFloat80_t );
    import "DPI-C" function automatic float64_t extF80_to_f64( input extFloat80_t );
    import "DPI-C" function automatic float128_t extF80_to_f128( input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_roundToInt( input extFloat80_t, input unsigned byte, input bit );
    import "DPI-C" function automatic extFloat80_t extF80_add( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_sub( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_mul( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_div( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_rem( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic extFloat80_t extF80_sqrt( input extFloat80_t );
    import "DPI-C" function automatic bit extF80_eq( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_le( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_lt( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_eq_signaling( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_le_quiet( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_lt_quiet( input extFloat80_t, input extFloat80_t );
    import "DPI-C" function automatic bit extF80_isSignalingNaN( input extFloat80_t );
`endif
import "DPI-C" function automatic unsigned int extF80M_to_ui32( output extFloat80_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned longint extF80M_to_ui64( output extFloat80_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int extF80M_to_i32( output extFloat80_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed longint extF80M_to_i64( output extFloat80_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int extF80M_to_ui32_r_minMag( output extFloat80_t, input bit );
import "DPI-C" function automatic unsigned longint extF80M_to_ui64_r_minMag( output extFloat80_t, input bit );
import "DPI-C" function automatic signed int extF80M_to_i32_r_minMag( output extFloat80_t, input bit );
import "DPI-C" function automatic signed longint extF80M_to_i64_r_minMag( output extFloat80_t, input bit );
import "DPI-C" function automatic float16_t extF80M_to_f16( output extFloat80_t );
import "DPI-C" function automatic float32_t extF80M_to_f32( output extFloat80_t );
import "DPI-C" function automatic float64_t extF80M_to_f64( output extFloat80_t );
import "DPI-C" function automatic void extF80M_to_f128M( output extFloat80_t, output float128_t );
import "DPI-C" function automatic void extF80M_roundToInt(output extFloat80_t, input unsigned byte, input bit, output extFloat80_t );
import "DPI-C" function automatic void extF80M_add( output extFloat80_t, output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic void extF80M_sub( output extFloat80_t, output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic void extF80M_mul( output extFloat80_t, output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic void extF80M_div( output extFloat80_t, output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic void extF80M_rem( output extFloat80_t, output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic void extF80M_sqrt( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_eq( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_le( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_lt( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_eq_signaling( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_le_quiet( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_lt_quiet( output extFloat80_t, output extFloat80_t );
import "DPI-C" function automatic bit extF80M_isSignalingNaN( output extFloat80_t );
*/

/*----------------------------------------------------------------------------
| 128-bit (quadruple-precision) floating-point operations.
*----------------------------------------------------------------------------*/
`ifdef SOFTFLOAT_FAST_INT64
    import "DPI-C" function automatic unsigned int f128_to_ui32( input float128_t, input unsigned byte, input bit );
    import "DPI-C" function automatic unsigned longint f128_to_ui64( input float128_t, input unsigned byte, input bit );
    import "DPI-C" function automatic signed int f128_to_i32( input float128_t, input unsigned byte, input bit );
    import "DPI-C" function automatic signed longint f128_to_i64( input float128_t, input unsigned byte, input bit );
    import "DPI-C" function automatic unsigned int f128_to_ui32_r_minMag( input float128_t, input bit );
    import "DPI-C" function automatic unsigned longint f128_to_ui64_r_minMag( input float128_t, input bit );
    import "DPI-C" function automatic signed int f128_to_i32_r_minMag( input float128_t, input bit );
    import "DPI-C" function automatic signed longint f128_to_i64_r_minMag( input float128_t, input bit );
    import "DPI-C" function automatic float16_t f128_to_f16( input float128_t );
    import "DPI-C" function automatic float32_t f128_to_f32( input float128_t );
    import "DPI-C" function automatic float64_t f128_to_f64( input float128_t );
    import "DPI-C" function automatic extFloat80_t f128_to_extF80( input float128_t );
    import "DPI-C" function automatic float128_t f128_roundToInt( input float128_t, input unsigned byte, input bit );
    import "DPI-C" function automatic float128_t f128_add( input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_sub( input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_mul( input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_mulAdd( input float128_t, input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_div( input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_rem( input float128_t, input float128_t );
    import "DPI-C" function automatic float128_t f128_sqrt( input float128_t );
    import "DPI-C" function automatic bit f128_eq( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_le( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_lt( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_eq_signaling( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_le_quiet( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_lt_quiet( input float128_t, input float128_t );
    import "DPI-C" function automatic bit f128_isSignalingNaN( input float128_t );
    import "DPI-C" function automatic unsigned shortint f128_classify( input float128_t );
`endif
import "DPI-C" function automatic unsigned int f128M_to_ui32( output float128_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned longint f128M_to_ui64( output float128_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed int f128M_to_i32( output float128_t, input unsigned byte, input bit );
import "DPI-C" function automatic signed longint f128M_to_i64( output float128_t, input unsigned byte, input bit );
import "DPI-C" function automatic unsigned int f128M_to_ui32_r_minMag( output float128_t, input bit );
import "DPI-C" function automatic unsigned longint f128M_to_ui64_r_minMag( output float128_t, input bit );
import "DPI-C" function automatic signed int f128M_to_i32_r_minMag( output float128_t, input bit );
import "DPI-C" function automatic signed longint f128M_to_i64_r_minMag( output float128_t, input bit );
import "DPI-C" function automatic float16_t f128M_to_f16( output float128_t );
import "DPI-C" function automatic float32_t f128M_to_f32( output float128_t );
import "DPI-C" function automatic float64_t f128M_to_f64( output float128_t );
import "DPI-C" function automatic void f128M_to_extF80M( output float128_t, output extFloat80_t );
import "DPI-C" function automatic void f128M_roundToInt( output float128_t, input unsigned byte, input bit, output float128_t );
import "DPI-C" function automatic void f128M_add( output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_sub( output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_mul( output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_mulAdd( output float128_t, output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_div( output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_rem( output float128_t, output float128_t, output float128_t );
import "DPI-C" function automatic void f128M_sqrt( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_eq( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_le( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_lt( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_eq_signaling( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_le_quiet( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_lt_quiet( output float128_t, output float128_t );
import "DPI-C" function automatic bit f128M_isSignalingNaN( output float128_t );


