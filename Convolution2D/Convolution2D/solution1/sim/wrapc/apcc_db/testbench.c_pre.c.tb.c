/* Provide Declarations */
#include <stdarg.h>
#include <setjmp.h>
#include <limits.h>
#ifdef NEED_CBEAPINT
#include <autopilot_cbe.h>
#else
#define aesl_fopen fopen
#define aesl_freopen freopen
#define aesl_tmpfile tmpfile
#endif
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#ifdef __STRICT_ANSI__
#define inline __inline__
#define typeof __typeof__ 
#endif
#define __isoc99_fscanf fscanf
#define __isoc99_sscanf sscanf
#undef ferror
#undef feof
/* get a declaration for alloca */
#if defined(__CYGWIN__) || defined(__MINGW32__)
#define  alloca(x) __builtin_alloca((x))
#define _alloca(x) __builtin_alloca((x))
#elif defined(__APPLE__)
extern void *__builtin_alloca(unsigned long);
#define alloca(x) __builtin_alloca(x)
#define longjmp _longjmp
#define setjmp _setjmp
#elif defined(__sun__)
#if defined(__sparcv9)
extern void *__builtin_alloca(unsigned long);
#else
extern void *__builtin_alloca(unsigned int);
#endif
#define alloca(x) __builtin_alloca(x)
#elif defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__) || defined(__DragonFly__) || defined(__arm__)
#define alloca(x) __builtin_alloca(x)
#elif defined(_MSC_VER)
#define inline _inline
#define alloca(x) _alloca(x)
#else
#include <alloca.h>
#endif

#ifndef __GNUC__  /* Can only support "linkonce" vars with GCC */
#define __attribute__(X)
#endif

#if defined(__GNUC__) && defined(__APPLE_CC__)
#define __EXTERNAL_WEAK__ __attribute__((weak_import))
#elif defined(__GNUC__)
#define __EXTERNAL_WEAK__ __attribute__((weak))
#else
#define __EXTERNAL_WEAK__
#endif

#if defined(__GNUC__) && (defined(__APPLE_CC__) || defined(__CYGWIN__) || defined(__MINGW32__))
#define __ATTRIBUTE_WEAK__
#elif defined(__GNUC__)
#define __ATTRIBUTE_WEAK__ __attribute__((weak))
#else
#define __ATTRIBUTE_WEAK__
#endif

#if defined(__GNUC__)
#define __HIDDEN__ __attribute__((visibility("hidden")))
#endif

#ifdef __GNUC__
#define LLVM_NAN(NanStr)   __builtin_nan(NanStr)   /* Double */
#define LLVM_NANF(NanStr)  __builtin_nanf(NanStr)  /* Float */
#define LLVM_NANS(NanStr)  __builtin_nans(NanStr)  /* Double */
#define LLVM_NANSF(NanStr) __builtin_nansf(NanStr) /* Float */
#define LLVM_INF           __builtin_inf()         /* Double */
#define LLVM_INFF          __builtin_inff()        /* Float */
#define LLVM_PREFETCH(addr,rw,locality) __builtin_prefetch(addr,rw,locality)
#define __ATTRIBUTE_CTOR__ __attribute__((constructor))
#define __ATTRIBUTE_DTOR__ __attribute__((destructor))
#define LLVM_ASM           __asm__
#else
#define LLVM_NAN(NanStr)   ((double)0.0)           /* Double */
#define LLVM_NANF(NanStr)  0.0F                    /* Float */
#define LLVM_NANS(NanStr)  ((double)0.0)           /* Double */
#define LLVM_NANSF(NanStr) 0.0F                    /* Float */
#define LLVM_INF           ((double)0.0)           /* Double */
#define LLVM_INFF          0.0F                    /* Float */
#define LLVM_PREFETCH(addr,rw,locality)            /* PREFETCH */
#define __ATTRIBUTE_CTOR__
#define __ATTRIBUTE_DTOR__
#define LLVM_ASM(X)
#endif

#if __GNUC__ < 4 /* Old GCC's, or compilers not GCC */ 
#define __builtin_stack_save() 0   /* not implemented */
#define __builtin_stack_restore(X) /* noop */
#endif

#if __GNUC__ && __LP64__ /* 128-bit integer types */
typedef int __attribute__((mode(TI))) llvmInt128;
typedef unsigned __attribute__((mode(TI))) llvmUInt128;
#endif

#define CODE_FOR_MAIN() /* Any target-specific code for main()*/

#ifndef __cplusplus
typedef unsigned char bool;
#endif


/* Support for floating point constants */
typedef unsigned long long ConstantDoubleTy;
typedef unsigned int        ConstantFloatTy;
typedef struct { unsigned long long f1; unsigned short f2; unsigned short pad[3]; } ConstantFP80Ty;
typedef struct { unsigned long long f1; unsigned long long f2; } ConstantFP128Ty;


/* Global Declarations */
/* Helper union for bitcasts */
typedef union {
  unsigned int Int32;
  unsigned long long Int64;
  float Float;
  double Double;
} llvmBitCastUnion;

/* External Global Variable Declarations */

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void test_case_1(void);
void AESL_WRAP_convolution2D(signed int (*)[5], signed int (*)[3], signed int (*)[3]);
void test_case_2(void);
void test_case_3(void);
void test_case_4(void);
void test_case_5(void);
signed int main(void);


/* Global Variable Definitions and Initialization */
static signed int aesl_internal_test_case_1_OC_expected_output[3][3] = { { 41u, 46u, 51u }, { 66u, 71u, 76u }, { 91u, 96u, 101u } };
static signed int aesl_internal_test_case_4_OC_input[5][5] = { { 1u, 2u, 3u, 4u, 5u }, { 6u, 7u, 8u, 9u, 10u }, { 11u, 12u, 13u, 14u, 15u }, { 16u, 17u, 18u, 19u, 20u }, { 21u, 22u, 23u, 24u, 25u } };
static signed int aesl_internal_test_case_4_OC_kernel[3][3] = { { 1u, 4294967295u, 1u }, { 4294967295u, 4u, 4294967295u }, { 1u, 4294967295u, 1u } };
static  char aesl_internal_str1[18] = "Test Case 1: FAIL";
static signed int aesl_internal_test_case_4_OC_expected_output[3][3] = { { 28u, 32u, 36u }, { 48u, 52u, 56u }, { 68u, 72u, 76u } };
static signed int aesl_internal_test_case_5_OC_input[5][5] = { { 4294967295u, 4294967294u, 4294967293u, 4294967292u, 4294967291u }, { 4294967290u, 4294967289u, 4294967288u, 4294967287u, 4294967286u }, { 4294967285u, 4294967284u, 4294967283u, 4294967282u, 4294967281u }, { 4294967280u, 4294967279u, 4294967278u, 4294967277u, 4294967276u }, { 4294967275u, 4294967274u, 4294967273u, 4294967272u, 4294967271u } };
static signed int aesl_internal_test_case_3_OC_kernel[3][3] = { { 1u, 1u, 1u }, { 1u, 1u, 1u }, { 1u, 1u, 1u } };
static signed int aesl_internal_test_case_3_OC_expected_output[3][3] = { { 63u, 72u, 81u }, { 108u, 117u, 126u }, { 153u, 162u, 171u } };
static signed int aesl_internal_test_case_5_OC_kernel[3][3] = { { 1u, 1u, 1u }, { 1u, 4294967292u, 1u }, { 1u, 1u, 2u } };
static signed int aesl_internal_test_case_5_OC_expected_output[3][3] = { { 4294967255u, 4294967250u, 4294967245u }, { 4294967230u, 4294967225u, 4294967220u }, { 4294967205u, 4294967200u, 4294967195u } };
static  char aesl_internal_str[18] = "Test Case 1: PASS";
static  char aesl_internal_str2[18] = "Test Case 2: PASS";
static  char aesl_internal_str3[18] = "Test Case 2: FAIL";
static  char aesl_internal_str5[18] = "Test Case 3: FAIL";
static  char aesl_internal_str8[18] = "Test Case 5: PASS";
static  char aesl_internal_str6[18] = "Test Case 4: PASS";
static  char aesl_internal_str9[18] = "Test Case 5: FAIL";
static  char aesl_internal_str4[18] = "Test Case 3: PASS";
static  char aesl_internal_str7[18] = "Test Case 4: FAIL";


/* Function Bodies */
static inline int llvm_fcmp_ord(double X, double Y) { return X == X && Y == Y; }
static inline int llvm_fcmp_uno(double X, double Y) { return X != X || Y != Y; }
static inline int llvm_fcmp_ueq(double X, double Y) { return X == Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_une(double X, double Y) { return X != Y; }
static inline int llvm_fcmp_ult(double X, double Y) { return X <  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ugt(double X, double Y) { return X >  Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_ule(double X, double Y) { return X <= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_uge(double X, double Y) { return X >= Y || llvm_fcmp_uno(X, Y); }
static inline int llvm_fcmp_oeq(double X, double Y) { return X == Y ; }
static inline int llvm_fcmp_one(double X, double Y) { return X != Y && llvm_fcmp_ord(X, Y); }
static inline int llvm_fcmp_olt(double X, double Y) { return X <  Y ; }
static inline int llvm_fcmp_ogt(double X, double Y) { return X >  Y ; }
static inline int llvm_fcmp_ole(double X, double Y) { return X <= Y ; }
static inline int llvm_fcmp_oge(double X, double Y) { return X >= Y ; }

void test_case_1(void) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
   char *llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
   char *llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
   char *llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
   char *llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
   char *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
   char *llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  signed int (*llvm_cbe_tmp__7)[5];
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  signed int (*llvm_cbe_tmp__8)[3];
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  signed int (*llvm_cbe_tmp__9)[3];
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned long long llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  signed int *llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  signed int *llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  unsigned int llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  unsigned int llvm_cbe_tmp__16;
  unsigned int llvm_cbe_tmp__16__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_1;
  unsigned int llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  unsigned long long llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  signed int *llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  unsigned int llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  signed int *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__23;
  unsigned int llvm_cbe_tmp__23__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_2;
  unsigned int llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  unsigned long long llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  signed int *llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  signed int *llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  unsigned int llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @test_case_1\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = bitcast [5 x [5 x i32]]* %%input to i8*, !dbg !4 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_4_count);
  llvm_cbe_tmp__1 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memcpy(i8* %%0, i8* bitcast ([5 x [5 x i32]]* @aesl_internal_test_case_4.input to i8*), i64 100 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_5_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__1, ( char *)(( char *)(&aesl_internal_test_case_4_OC_input)), 100ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",100ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__2);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast [3 x [3 x i32]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_7_count);
  llvm_cbe_tmp__3 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memcpy(i8* %%2, i8* bitcast ([3 x [3 x i32]]* @aesl_internal_test_case_5.kernel to i8*), i64 36 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_8_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__3, ( char *)(( char *)(&aesl_internal_test_case_5_OC_kernel)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__4);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [3 x [3 x i32]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_10_count);
  llvm_cbe_tmp__5 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%4, i32 0, i64 36 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_11_count);
  ( char *)memset(( char *)llvm_cbe_tmp__5, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__6);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x [5 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_12_count);
  llvm_cbe_tmp__7 = (signed int (*)[5])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x [3 x i32]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_13_count);
  llvm_cbe_tmp__8 = (signed int (*)[3])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_14_count);
  llvm_cbe_tmp__9 = (signed int (*)[3])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_convolution2D([5 x i32]* %%6, [3 x i32]* %%7, [3 x i32]* %%8) nounwind, !dbg !5 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_15_count);
  AESL_WRAP_convolution2D(llvm_cbe_tmp__7, llvm_cbe_tmp__8, llvm_cbe_tmp__9);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__30;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__30:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%11 ], [ 0, %%.preheader  for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__15);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__31;
  } else {
    llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

llvm_cbe_tmp__31:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__10 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__11 = (signed int *)(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__10) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__12 = (unsigned int )*llvm_cbe_tmp__11;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__12);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_1.expected_output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__13 = (signed int *)(&aesl_internal_test_case_1_OC_expected_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__10))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__10));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__10) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_35_count);
  llvm_cbe_tmp__14 = (unsigned int )*llvm_cbe_tmp__13;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__14);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_37_count);
  llvm_cbe_tmp__15 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__15&4294967295ull)));
  if (((llvm_cbe_tmp__12&4294967295U) == (llvm_cbe_tmp__14&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__15;   /* for PHI node */
    goto llvm_cbe_tmp__30;
  } else {
    llvm_cbe_tmp__16__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 1, %%9 ], [ 0, %%11  for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_40_count);
  llvm_cbe_tmp__16 = (unsigned int )llvm_cbe_tmp__16__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__32;

llvm_cbe_tmp__33:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__34;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str1, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str1[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__34;

llvm_cbe_tmp__34:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @test_case_1}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__32:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.1 = phi i32 [ %%31, %%24 ], [ 0, %%.preheader.1  for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_storemerge1_2e_1_count);
  llvm_cbe_storemerge1_2e_1 = (unsigned int )llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.1 = 0x%X",llvm_cbe_storemerge1_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__22);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__35;
  } else {
    llvm_cbe_tmp__23__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__16;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

llvm_cbe_tmp__35:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%storemerge1.1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_56_count);
  llvm_cbe_tmp__17 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__17);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_57_count);
  llvm_cbe_tmp__18 = (signed int *)(&llvm_cbe_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__17))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__17) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_58_count);
  llvm_cbe_tmp__19 = (unsigned int )*llvm_cbe_tmp__18;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_1.expected_output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__20 = (signed int *)(&aesl_internal_test_case_1_OC_expected_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__17))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__17));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__17) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__21 = (unsigned int )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge1.1, 1, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__22 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__22&4294967295ull)));
  if (((llvm_cbe_tmp__19&4294967295U) == (llvm_cbe_tmp__21&4294967295U))) {
    llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__22;   /* for PHI node */
    goto llvm_cbe_tmp__32;
  } else {
    llvm_cbe_tmp__23__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i32 [ %%19, %%22 ], [ 0, %%24  for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__23 = (unsigned int )llvm_cbe_tmp__23__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__23);
printf("\n = 0x%X",llvm_cbe_tmp__16);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__36;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__36:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.2 = phi i32 [ %%42, %%35 ], [ 0, %%.preheader.2  for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_storemerge1_2e_2_count);
  llvm_cbe_storemerge1_2e_2 = (unsigned int )llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.2 = 0x%X",llvm_cbe_storemerge1_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__29);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_2) < ((signed int )3u))) {
    goto llvm_cbe_tmp__37;
  } else {
    goto llvm_cbe_tmp__38;
  }

llvm_cbe_tmp__37:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%storemerge1.2 to i64, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_78_count);
  llvm_cbe_tmp__24 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__24);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_79_count);
  llvm_cbe_tmp__25 = (signed int *)(&llvm_cbe_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__24))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__24));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__24) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_80_count);
  llvm_cbe_tmp__26 = (unsigned int )*llvm_cbe_tmp__25;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_1.expected_output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_81_count);
  llvm_cbe_tmp__27 = (signed int *)(&aesl_internal_test_case_1_OC_expected_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__24))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__24));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__24) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_1.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_82_count);
  llvm_cbe_tmp__28 = (unsigned int )*llvm_cbe_tmp__27;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__28);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge1.2, 1, !dbg !6 for 0x%I64xth hint within @test_case_1  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__29 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__29&4294967295ull)));
  if (((llvm_cbe_tmp__26&4294967295U) == (llvm_cbe_tmp__28&4294967295U))) {
    llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__29;   /* for PHI node */
    goto llvm_cbe_tmp__36;
  } else {
    goto llvm_cbe__2e_thread;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__38:
  if (((llvm_cbe_tmp__23&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__33;
  }

}


void test_case_2(void) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_expected_output_count = 0;
  signed int llvm_cbe_expected_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
   char *llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
   char *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
   char *llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
   char *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  signed int *llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  signed int *llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  signed int *llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  signed int *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  signed int *llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
   char *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
   char *llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  signed int (*llvm_cbe_tmp__50)[5];
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  signed int (*llvm_cbe_tmp__51)[3];
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  signed int (*llvm_cbe_tmp__52)[3];
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
   char *llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
   char *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  unsigned long long llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  signed int *llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  signed int *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  unsigned int llvm_cbe_tmp__61;
  unsigned int llvm_cbe_tmp__61__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_1;
  unsigned int llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  unsigned long long llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  signed int *llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  unsigned int llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  signed int *llvm_cbe_tmp__65;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  unsigned int llvm_cbe_tmp__66;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  unsigned int llvm_cbe_tmp__67;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__68;
  unsigned int llvm_cbe_tmp__68__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_2;
  unsigned int llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  unsigned long long llvm_cbe_tmp__69;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  signed int *llvm_cbe_tmp__70;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  unsigned int llvm_cbe_tmp__71;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  signed int *llvm_cbe_tmp__72;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  unsigned int llvm_cbe_tmp__73;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  unsigned int llvm_cbe_tmp__74;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @test_case_2\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = bitcast [5 x [5 x i32]]* %%input to i8*, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_97_count);
  llvm_cbe_tmp__39 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memcpy(i8* %%0, i8* bitcast ([5 x [5 x i32]]* @aesl_internal_test_case_4.input to i8*), i64 100 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_98_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__39, ( char *)(( char *)(&aesl_internal_test_case_4_OC_input)), 100ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",100ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__40);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast [3 x [3 x i32]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__41 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memset(i8* %%2, i32 0, i64 36 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_101_count);
  ( char *)memset(( char *)llvm_cbe_tmp__41, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__42);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = getelementptr [3 x [3 x i32]]* %%kernel, i64 0, i64 0, i64 1, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__43 = (signed int *)(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )0ull) < 3 && "Write access out of array 'kernel' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%4, align 4, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_103_count);
  *llvm_cbe_tmp__43 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr [3 x [3 x i32]]* %%kernel, i64 0, i64 1, i64 0, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__44 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");
  assert(((signed long long )0ull) < 3 && "Write access out of array 'kernel' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%5, align 4, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_105_count);
  *llvm_cbe_tmp__44 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr [3 x [3 x i32]]* %%kernel, i64 0, i64 1, i64 1, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_106_count);
  llvm_cbe_tmp__45 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 -4, i32* %%6, align 4, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_107_count);
  *llvm_cbe_tmp__45 = 4294967292u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 4294967292u);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr [3 x [3 x i32]]* %%kernel, i64 0, i64 1, i64 2, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_108_count);
  llvm_cbe_tmp__46 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");
  assert(((signed long long )2ull) < 3 && "Write access out of array 'kernel' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%7, align 4, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_109_count);
  *llvm_cbe_tmp__46 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr [3 x [3 x i32]]* %%kernel, i64 0, i64 2, i64 1, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_110_count);
  llvm_cbe_tmp__47 = (signed int *)(&llvm_cbe_kernel[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  assert(((signed long long )2ull) < 3 && "Write access out of array 'kernel' bound?");
  assert(((signed long long )1ull) < 3 && "Write access out of array 'kernel' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 1, i32* %%8, align 4, !dbg !4 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_111_count);
  *llvm_cbe_tmp__47 = 1u;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", 1u);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = bitcast [3 x [3 x i32]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_113_count);
  llvm_cbe_tmp__48 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = call i8* @memset(i8* %%9, i32 0, i64 36 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_114_count);
  ( char *)memset(( char *)llvm_cbe_tmp__48, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__49);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = getelementptr inbounds [5 x [5 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__50 = (signed int (*)[5])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [3 x [3 x i32]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__51 = (signed int (*)[3])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__52 = (signed int (*)[3])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_convolution2D([5 x i32]* %%11, [3 x i32]* %%12, [3 x i32]* %%13) nounwind, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_118_count);
  AESL_WRAP_convolution2D(llvm_cbe_tmp__50, llvm_cbe_tmp__51, llvm_cbe_tmp__52);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = bitcast [3 x [3 x i32]]* %%expected_output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_120_count);
  llvm_cbe_tmp__53 = ( char *)(( char *)(&llvm_cbe_expected_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = call i8* @memset(i8* %%14, i32 0, i64 36 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_121_count);
  ( char *)memset(( char *)llvm_cbe_tmp__53, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__54);
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__75;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__75:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%25, %%18 ], [ 0, %%.preheader  for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__60);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__76;
  } else {
    llvm_cbe_tmp__61__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

llvm_cbe_tmp__76:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_136_count);
  llvm_cbe_tmp__55 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, i64 %%19, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__56 = (signed int *)(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__55))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__55));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__55) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__57 = (unsigned int )*llvm_cbe_tmp__56;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__57);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [3 x [3 x i32]]* %%expected_output, i64 0, i64 0, i64 %%19, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__58 = (signed int *)(&llvm_cbe_expected_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__55))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__55));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__55) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__59 = (unsigned int )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__60 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__60&4294967295ull)));
  if (((llvm_cbe_tmp__57&4294967295U) == (llvm_cbe_tmp__59&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__60;   /* for PHI node */
    goto llvm_cbe_tmp__75;
  } else {
    llvm_cbe_tmp__61__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = phi i32 [ 1, %%16 ], [ 0, %%18  for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_145_count);
  llvm_cbe_tmp__61 = (unsigned int )llvm_cbe_tmp__61__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__61);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__77;

llvm_cbe_tmp__78:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str2, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str2[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__79;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str3, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str3[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__79;

llvm_cbe_tmp__79:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @test_case_2}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__77:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.1 = phi i32 [ %%38, %%31 ], [ 0, %%.preheader.1  for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_storemerge1_2e_1_count);
  llvm_cbe_storemerge1_2e_1 = (unsigned int )llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.1 = 0x%X",llvm_cbe_storemerge1_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__67);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__80;
  } else {
    llvm_cbe_tmp__68__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__61;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

llvm_cbe_tmp__80:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = sext i32 %%storemerge1.1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_161_count);
  llvm_cbe_tmp__62 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__62);
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 1, i64 %%32, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_162_count);
  llvm_cbe_tmp__63 = (signed int *)(&llvm_cbe_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__62))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__62));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__62) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = load i32* %%33, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_163_count);
  llvm_cbe_tmp__64 = (unsigned int )*llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__64);
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = getelementptr inbounds [3 x [3 x i32]]* %%expected_output, i64 0, i64 1, i64 %%32, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_164_count);
  llvm_cbe_tmp__65 = (signed int *)(&llvm_cbe_expected_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__62))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__62));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__62) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = load i32* %%35, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__66 = (unsigned int )*llvm_cbe_tmp__65;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__66);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = add nsw i32 %%storemerge1.1, 1, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__67 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__67&4294967295ull)));
  if (((llvm_cbe_tmp__64&4294967295U) == (llvm_cbe_tmp__66&4294967295U))) {
    llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__67;   /* for PHI node */
    goto llvm_cbe_tmp__77;
  } else {
    llvm_cbe_tmp__68__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = phi i32 [ %%26, %%29 ], [ 0, %%31  for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__68 = (unsigned int )llvm_cbe_tmp__68__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__68);
printf("\n = 0x%X",llvm_cbe_tmp__61);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__81;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__81:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.2 = phi i32 [ %%49, %%42 ], [ 0, %%.preheader.2  for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_storemerge1_2e_2_count);
  llvm_cbe_storemerge1_2e_2 = (unsigned int )llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.2 = 0x%X",llvm_cbe_storemerge1_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__74);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_2) < ((signed int )3u))) {
    goto llvm_cbe_tmp__82;
  } else {
    goto llvm_cbe_tmp__83;
  }

llvm_cbe_tmp__82:
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = sext i32 %%storemerge1.2 to i64, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_183_count);
  llvm_cbe_tmp__69 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__69);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 2, i64 %%43, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__70 = (signed int *)(&llvm_cbe_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__69) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = load i32* %%44, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_185_count);
  llvm_cbe_tmp__71 = (unsigned int )*llvm_cbe_tmp__70;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__71);
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [3 x [3 x i32]]* %%expected_output, i64 0, i64 2, i64 %%43, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_186_count);
  llvm_cbe_tmp__72 = (signed int *)(&llvm_cbe_expected_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__69))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__69));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__69) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i32* %%46, align 4, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_187_count);
  llvm_cbe_tmp__73 = (unsigned int )*llvm_cbe_tmp__72;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__73);
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = add nsw i32 %%storemerge1.2, 1, !dbg !6 for 0x%I64xth hint within @test_case_2  --> \n", ++aesl_llvm_cbe_189_count);
  llvm_cbe_tmp__74 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__74&4294967295ull)));
  if (((llvm_cbe_tmp__71&4294967295U) == (llvm_cbe_tmp__73&4294967295U))) {
    llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__74;   /* for PHI node */
    goto llvm_cbe_tmp__81;
  } else {
    goto llvm_cbe__2e_thread;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__83:
  if (((llvm_cbe_tmp__68&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__78;
  }

}


void test_case_3(void) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_199_count = 0;
  static  unsigned long long aesl_llvm_cbe_200_count = 0;
  static  unsigned long long aesl_llvm_cbe_201_count = 0;
  static  unsigned long long aesl_llvm_cbe_202_count = 0;
   char *llvm_cbe_tmp__84;
  static  unsigned long long aesl_llvm_cbe_203_count = 0;
   char *llvm_cbe_tmp__85;
  static  unsigned long long aesl_llvm_cbe_204_count = 0;
  static  unsigned long long aesl_llvm_cbe_205_count = 0;
   char *llvm_cbe_tmp__86;
  static  unsigned long long aesl_llvm_cbe_206_count = 0;
   char *llvm_cbe_tmp__87;
  static  unsigned long long aesl_llvm_cbe_207_count = 0;
  static  unsigned long long aesl_llvm_cbe_208_count = 0;
   char *llvm_cbe_tmp__88;
  static  unsigned long long aesl_llvm_cbe_209_count = 0;
   char *llvm_cbe_tmp__89;
  static  unsigned long long aesl_llvm_cbe_210_count = 0;
  signed int (*llvm_cbe_tmp__90)[5];
  static  unsigned long long aesl_llvm_cbe_211_count = 0;
  signed int (*llvm_cbe_tmp__91)[3];
  static  unsigned long long aesl_llvm_cbe_212_count = 0;
  signed int (*llvm_cbe_tmp__92)[3];
  static  unsigned long long aesl_llvm_cbe_213_count = 0;
  static  unsigned long long aesl_llvm_cbe_214_count = 0;
  static  unsigned long long aesl_llvm_cbe_215_count = 0;
  static  unsigned long long aesl_llvm_cbe_216_count = 0;
  static  unsigned long long aesl_llvm_cbe_217_count = 0;
  static  unsigned long long aesl_llvm_cbe_218_count = 0;
  static  unsigned long long aesl_llvm_cbe_219_count = 0;
  static  unsigned long long aesl_llvm_cbe_220_count = 0;
  static  unsigned long long aesl_llvm_cbe_221_count = 0;
  static  unsigned long long aesl_llvm_cbe_222_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_223_count = 0;
  static  unsigned long long aesl_llvm_cbe_224_count = 0;
  static  unsigned long long aesl_llvm_cbe_225_count = 0;
  static  unsigned long long aesl_llvm_cbe_226_count = 0;
  static  unsigned long long aesl_llvm_cbe_227_count = 0;
  static  unsigned long long aesl_llvm_cbe_228_count = 0;
  static  unsigned long long aesl_llvm_cbe_229_count = 0;
  unsigned long long llvm_cbe_tmp__93;
  static  unsigned long long aesl_llvm_cbe_230_count = 0;
  signed int *llvm_cbe_tmp__94;
  static  unsigned long long aesl_llvm_cbe_231_count = 0;
  unsigned int llvm_cbe_tmp__95;
  static  unsigned long long aesl_llvm_cbe_232_count = 0;
  signed int *llvm_cbe_tmp__96;
  static  unsigned long long aesl_llvm_cbe_233_count = 0;
  unsigned int llvm_cbe_tmp__97;
  static  unsigned long long aesl_llvm_cbe_234_count = 0;
  static  unsigned long long aesl_llvm_cbe_235_count = 0;
  unsigned int llvm_cbe_tmp__98;
  static  unsigned long long aesl_llvm_cbe_236_count = 0;
  static  unsigned long long aesl_llvm_cbe_237_count = 0;
  static  unsigned long long aesl_llvm_cbe_238_count = 0;
  unsigned int llvm_cbe_tmp__99;
  unsigned int llvm_cbe_tmp__99__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_239_count = 0;
  static  unsigned long long aesl_llvm_cbe_240_count = 0;
  static  unsigned long long aesl_llvm_cbe_241_count = 0;
  static  unsigned long long aesl_llvm_cbe_242_count = 0;
  static  unsigned long long aesl_llvm_cbe_243_count = 0;
  static  unsigned long long aesl_llvm_cbe_244_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_245_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_246_count = 0;
  static  unsigned long long aesl_llvm_cbe_247_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_1;
  unsigned int llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_248_count = 0;
  static  unsigned long long aesl_llvm_cbe_249_count = 0;
  static  unsigned long long aesl_llvm_cbe_250_count = 0;
  static  unsigned long long aesl_llvm_cbe_251_count = 0;
  static  unsigned long long aesl_llvm_cbe_252_count = 0;
  static  unsigned long long aesl_llvm_cbe_253_count = 0;
  static  unsigned long long aesl_llvm_cbe_254_count = 0;
  unsigned long long llvm_cbe_tmp__100;
  static  unsigned long long aesl_llvm_cbe_255_count = 0;
  signed int *llvm_cbe_tmp__101;
  static  unsigned long long aesl_llvm_cbe_256_count = 0;
  unsigned int llvm_cbe_tmp__102;
  static  unsigned long long aesl_llvm_cbe_257_count = 0;
  signed int *llvm_cbe_tmp__103;
  static  unsigned long long aesl_llvm_cbe_258_count = 0;
  unsigned int llvm_cbe_tmp__104;
  static  unsigned long long aesl_llvm_cbe_259_count = 0;
  static  unsigned long long aesl_llvm_cbe_260_count = 0;
  unsigned int llvm_cbe_tmp__105;
  static  unsigned long long aesl_llvm_cbe_261_count = 0;
  static  unsigned long long aesl_llvm_cbe_262_count = 0;
  static  unsigned long long aesl_llvm_cbe_263_count = 0;
  unsigned int llvm_cbe_tmp__106;
  unsigned int llvm_cbe_tmp__106__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_264_count = 0;
  static  unsigned long long aesl_llvm_cbe_265_count = 0;
  static  unsigned long long aesl_llvm_cbe_266_count = 0;
  static  unsigned long long aesl_llvm_cbe_267_count = 0;
  static  unsigned long long aesl_llvm_cbe_268_count = 0;
  static  unsigned long long aesl_llvm_cbe_269_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_2;
  unsigned int llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_270_count = 0;
  static  unsigned long long aesl_llvm_cbe_271_count = 0;
  static  unsigned long long aesl_llvm_cbe_272_count = 0;
  static  unsigned long long aesl_llvm_cbe_273_count = 0;
  static  unsigned long long aesl_llvm_cbe_274_count = 0;
  static  unsigned long long aesl_llvm_cbe_275_count = 0;
  static  unsigned long long aesl_llvm_cbe_276_count = 0;
  unsigned long long llvm_cbe_tmp__107;
  static  unsigned long long aesl_llvm_cbe_277_count = 0;
  signed int *llvm_cbe_tmp__108;
  static  unsigned long long aesl_llvm_cbe_278_count = 0;
  unsigned int llvm_cbe_tmp__109;
  static  unsigned long long aesl_llvm_cbe_279_count = 0;
  signed int *llvm_cbe_tmp__110;
  static  unsigned long long aesl_llvm_cbe_280_count = 0;
  unsigned int llvm_cbe_tmp__111;
  static  unsigned long long aesl_llvm_cbe_281_count = 0;
  static  unsigned long long aesl_llvm_cbe_282_count = 0;
  unsigned int llvm_cbe_tmp__112;
  static  unsigned long long aesl_llvm_cbe_283_count = 0;
  static  unsigned long long aesl_llvm_cbe_284_count = 0;
  static  unsigned long long aesl_llvm_cbe_285_count = 0;
  static  unsigned long long aesl_llvm_cbe_286_count = 0;
  static  unsigned long long aesl_llvm_cbe_287_count = 0;
  static  unsigned long long aesl_llvm_cbe_288_count = 0;
  static  unsigned long long aesl_llvm_cbe_289_count = 0;
  static  unsigned long long aesl_llvm_cbe_290_count = 0;
  static  unsigned long long aesl_llvm_cbe_291_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @test_case_3\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = bitcast [5 x [5 x i32]]* %%input to i8*, !dbg !4 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_202_count);
  llvm_cbe_tmp__84 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memcpy(i8* %%0, i8* bitcast ([5 x [5 x i32]]* @aesl_internal_test_case_4.input to i8*), i64 100 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_203_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__84, ( char *)(( char *)(&aesl_internal_test_case_4_OC_input)), 100ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",100ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__85);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast [3 x [3 x i32]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_205_count);
  llvm_cbe_tmp__86 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memcpy(i8* %%2, i8* bitcast ([3 x [3 x i32]]* @aesl_internal_test_case_3.kernel to i8*), i64 36 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_206_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__86, ( char *)(( char *)(&aesl_internal_test_case_3_OC_kernel)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__87);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [3 x [3 x i32]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_208_count);
  llvm_cbe_tmp__88 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%4, i32 0, i64 36 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_209_count);
  ( char *)memset(( char *)llvm_cbe_tmp__88, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__89);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x [5 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_210_count);
  llvm_cbe_tmp__90 = (signed int (*)[5])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x [3 x i32]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_211_count);
  llvm_cbe_tmp__91 = (signed int (*)[3])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_212_count);
  llvm_cbe_tmp__92 = (signed int (*)[3])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_convolution2D([5 x i32]* %%6, [3 x i32]* %%7, [3 x i32]* %%8) nounwind, !dbg !5 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_213_count);
  AESL_WRAP_convolution2D(llvm_cbe_tmp__90, llvm_cbe_tmp__91, llvm_cbe_tmp__92);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__113;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__113:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%11 ], [ 0, %%.preheader  for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__98);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__114;
  } else {
    llvm_cbe_tmp__99__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

llvm_cbe_tmp__114:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_229_count);
  llvm_cbe_tmp__93 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__93);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_230_count);
  llvm_cbe_tmp__94 = (signed int *)(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__93))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__93));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__93) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_231_count);
  llvm_cbe_tmp__95 = (unsigned int )*llvm_cbe_tmp__94;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__95);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_3.expected_output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_232_count);
  llvm_cbe_tmp__96 = (signed int *)(&aesl_internal_test_case_3_OC_expected_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__93))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__93));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__93) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_233_count);
  llvm_cbe_tmp__97 = (unsigned int )*llvm_cbe_tmp__96;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__97);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_235_count);
  llvm_cbe_tmp__98 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__98&4294967295ull)));
  if (((llvm_cbe_tmp__95&4294967295U) == (llvm_cbe_tmp__97&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__98;   /* for PHI node */
    goto llvm_cbe_tmp__113;
  } else {
    llvm_cbe_tmp__99__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 1, %%9 ], [ 0, %%11  for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_238_count);
  llvm_cbe_tmp__99 = (unsigned int )llvm_cbe_tmp__99__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__99);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__115;

llvm_cbe_tmp__116:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str4, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str4[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__117;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str5, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str5[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__117;

llvm_cbe_tmp__117:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @test_case_3}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__115:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.1 = phi i32 [ %%31, %%24 ], [ 0, %%.preheader.1  for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_storemerge1_2e_1_count);
  llvm_cbe_storemerge1_2e_1 = (unsigned int )llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.1 = 0x%X",llvm_cbe_storemerge1_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__105);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__118;
  } else {
    llvm_cbe_tmp__106__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__99;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

llvm_cbe_tmp__118:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%storemerge1.1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_254_count);
  llvm_cbe_tmp__100 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__100);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_255_count);
  llvm_cbe_tmp__101 = (signed int *)(&llvm_cbe_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__100))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__100));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__100) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_256_count);
  llvm_cbe_tmp__102 = (unsigned int )*llvm_cbe_tmp__101;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__102);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_3.expected_output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_257_count);
  llvm_cbe_tmp__103 = (signed int *)(&aesl_internal_test_case_3_OC_expected_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__100))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__100));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__100) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_258_count);
  llvm_cbe_tmp__104 = (unsigned int )*llvm_cbe_tmp__103;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__104);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge1.1, 1, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_260_count);
  llvm_cbe_tmp__105 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__105&4294967295ull)));
  if (((llvm_cbe_tmp__102&4294967295U) == (llvm_cbe_tmp__104&4294967295U))) {
    llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__105;   /* for PHI node */
    goto llvm_cbe_tmp__115;
  } else {
    llvm_cbe_tmp__106__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i32 [ %%19, %%22 ], [ 0, %%24  for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_263_count);
  llvm_cbe_tmp__106 = (unsigned int )llvm_cbe_tmp__106__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__106);
printf("\n = 0x%X",llvm_cbe_tmp__99);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__119;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__119:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.2 = phi i32 [ %%42, %%35 ], [ 0, %%.preheader.2  for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_storemerge1_2e_2_count);
  llvm_cbe_storemerge1_2e_2 = (unsigned int )llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.2 = 0x%X",llvm_cbe_storemerge1_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__112);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_2) < ((signed int )3u))) {
    goto llvm_cbe_tmp__120;
  } else {
    goto llvm_cbe_tmp__121;
  }

llvm_cbe_tmp__120:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%storemerge1.2 to i64, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_276_count);
  llvm_cbe_tmp__107 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__107);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_277_count);
  llvm_cbe_tmp__108 = (signed int *)(&llvm_cbe_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__107))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__107));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__107) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_278_count);
  llvm_cbe_tmp__109 = (unsigned int )*llvm_cbe_tmp__108;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__109);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_3.expected_output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_279_count);
  llvm_cbe_tmp__110 = (signed int *)(&aesl_internal_test_case_3_OC_expected_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__107))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__107));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__107) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_3.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_280_count);
  llvm_cbe_tmp__111 = (unsigned int )*llvm_cbe_tmp__110;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__111);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge1.2, 1, !dbg !6 for 0x%I64xth hint within @test_case_3  --> \n", ++aesl_llvm_cbe_282_count);
  llvm_cbe_tmp__112 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__112&4294967295ull)));
  if (((llvm_cbe_tmp__109&4294967295U) == (llvm_cbe_tmp__111&4294967295U))) {
    llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__112;   /* for PHI node */
    goto llvm_cbe_tmp__119;
  } else {
    goto llvm_cbe__2e_thread;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__121:
  if (((llvm_cbe_tmp__106&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__116;
  }

}


void test_case_4(void) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_292_count = 0;
  static  unsigned long long aesl_llvm_cbe_293_count = 0;
  static  unsigned long long aesl_llvm_cbe_294_count = 0;
  static  unsigned long long aesl_llvm_cbe_295_count = 0;
   char *llvm_cbe_tmp__122;
  static  unsigned long long aesl_llvm_cbe_296_count = 0;
   char *llvm_cbe_tmp__123;
  static  unsigned long long aesl_llvm_cbe_297_count = 0;
  static  unsigned long long aesl_llvm_cbe_298_count = 0;
   char *llvm_cbe_tmp__124;
  static  unsigned long long aesl_llvm_cbe_299_count = 0;
   char *llvm_cbe_tmp__125;
  static  unsigned long long aesl_llvm_cbe_300_count = 0;
  static  unsigned long long aesl_llvm_cbe_301_count = 0;
   char *llvm_cbe_tmp__126;
  static  unsigned long long aesl_llvm_cbe_302_count = 0;
   char *llvm_cbe_tmp__127;
  static  unsigned long long aesl_llvm_cbe_303_count = 0;
  signed int (*llvm_cbe_tmp__128)[5];
  static  unsigned long long aesl_llvm_cbe_304_count = 0;
  signed int (*llvm_cbe_tmp__129)[3];
  static  unsigned long long aesl_llvm_cbe_305_count = 0;
  signed int (*llvm_cbe_tmp__130)[3];
  static  unsigned long long aesl_llvm_cbe_306_count = 0;
  static  unsigned long long aesl_llvm_cbe_307_count = 0;
  static  unsigned long long aesl_llvm_cbe_308_count = 0;
  static  unsigned long long aesl_llvm_cbe_309_count = 0;
  static  unsigned long long aesl_llvm_cbe_310_count = 0;
  static  unsigned long long aesl_llvm_cbe_311_count = 0;
  static  unsigned long long aesl_llvm_cbe_312_count = 0;
  static  unsigned long long aesl_llvm_cbe_313_count = 0;
  static  unsigned long long aesl_llvm_cbe_314_count = 0;
  static  unsigned long long aesl_llvm_cbe_315_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_316_count = 0;
  static  unsigned long long aesl_llvm_cbe_317_count = 0;
  static  unsigned long long aesl_llvm_cbe_318_count = 0;
  static  unsigned long long aesl_llvm_cbe_319_count = 0;
  static  unsigned long long aesl_llvm_cbe_320_count = 0;
  static  unsigned long long aesl_llvm_cbe_321_count = 0;
  static  unsigned long long aesl_llvm_cbe_322_count = 0;
  unsigned long long llvm_cbe_tmp__131;
  static  unsigned long long aesl_llvm_cbe_323_count = 0;
  signed int *llvm_cbe_tmp__132;
  static  unsigned long long aesl_llvm_cbe_324_count = 0;
  unsigned int llvm_cbe_tmp__133;
  static  unsigned long long aesl_llvm_cbe_325_count = 0;
  signed int *llvm_cbe_tmp__134;
  static  unsigned long long aesl_llvm_cbe_326_count = 0;
  unsigned int llvm_cbe_tmp__135;
  static  unsigned long long aesl_llvm_cbe_327_count = 0;
  static  unsigned long long aesl_llvm_cbe_328_count = 0;
  unsigned int llvm_cbe_tmp__136;
  static  unsigned long long aesl_llvm_cbe_329_count = 0;
  static  unsigned long long aesl_llvm_cbe_330_count = 0;
  static  unsigned long long aesl_llvm_cbe_331_count = 0;
  unsigned int llvm_cbe_tmp__137;
  unsigned int llvm_cbe_tmp__137__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_332_count = 0;
  static  unsigned long long aesl_llvm_cbe_333_count = 0;
  static  unsigned long long aesl_llvm_cbe_334_count = 0;
  static  unsigned long long aesl_llvm_cbe_335_count = 0;
  static  unsigned long long aesl_llvm_cbe_336_count = 0;
  static  unsigned long long aesl_llvm_cbe_337_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_338_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_339_count = 0;
  static  unsigned long long aesl_llvm_cbe_340_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_1;
  unsigned int llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_341_count = 0;
  static  unsigned long long aesl_llvm_cbe_342_count = 0;
  static  unsigned long long aesl_llvm_cbe_343_count = 0;
  static  unsigned long long aesl_llvm_cbe_344_count = 0;
  static  unsigned long long aesl_llvm_cbe_345_count = 0;
  static  unsigned long long aesl_llvm_cbe_346_count = 0;
  static  unsigned long long aesl_llvm_cbe_347_count = 0;
  unsigned long long llvm_cbe_tmp__138;
  static  unsigned long long aesl_llvm_cbe_348_count = 0;
  signed int *llvm_cbe_tmp__139;
  static  unsigned long long aesl_llvm_cbe_349_count = 0;
  unsigned int llvm_cbe_tmp__140;
  static  unsigned long long aesl_llvm_cbe_350_count = 0;
  signed int *llvm_cbe_tmp__141;
  static  unsigned long long aesl_llvm_cbe_351_count = 0;
  unsigned int llvm_cbe_tmp__142;
  static  unsigned long long aesl_llvm_cbe_352_count = 0;
  static  unsigned long long aesl_llvm_cbe_353_count = 0;
  unsigned int llvm_cbe_tmp__143;
  static  unsigned long long aesl_llvm_cbe_354_count = 0;
  static  unsigned long long aesl_llvm_cbe_355_count = 0;
  static  unsigned long long aesl_llvm_cbe_356_count = 0;
  unsigned int llvm_cbe_tmp__144;
  unsigned int llvm_cbe_tmp__144__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_357_count = 0;
  static  unsigned long long aesl_llvm_cbe_358_count = 0;
  static  unsigned long long aesl_llvm_cbe_359_count = 0;
  static  unsigned long long aesl_llvm_cbe_360_count = 0;
  static  unsigned long long aesl_llvm_cbe_361_count = 0;
  static  unsigned long long aesl_llvm_cbe_362_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_2;
  unsigned int llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_363_count = 0;
  static  unsigned long long aesl_llvm_cbe_364_count = 0;
  static  unsigned long long aesl_llvm_cbe_365_count = 0;
  static  unsigned long long aesl_llvm_cbe_366_count = 0;
  static  unsigned long long aesl_llvm_cbe_367_count = 0;
  static  unsigned long long aesl_llvm_cbe_368_count = 0;
  static  unsigned long long aesl_llvm_cbe_369_count = 0;
  unsigned long long llvm_cbe_tmp__145;
  static  unsigned long long aesl_llvm_cbe_370_count = 0;
  signed int *llvm_cbe_tmp__146;
  static  unsigned long long aesl_llvm_cbe_371_count = 0;
  unsigned int llvm_cbe_tmp__147;
  static  unsigned long long aesl_llvm_cbe_372_count = 0;
  signed int *llvm_cbe_tmp__148;
  static  unsigned long long aesl_llvm_cbe_373_count = 0;
  unsigned int llvm_cbe_tmp__149;
  static  unsigned long long aesl_llvm_cbe_374_count = 0;
  static  unsigned long long aesl_llvm_cbe_375_count = 0;
  unsigned int llvm_cbe_tmp__150;
  static  unsigned long long aesl_llvm_cbe_376_count = 0;
  static  unsigned long long aesl_llvm_cbe_377_count = 0;
  static  unsigned long long aesl_llvm_cbe_378_count = 0;
  static  unsigned long long aesl_llvm_cbe_379_count = 0;
  static  unsigned long long aesl_llvm_cbe_380_count = 0;
  static  unsigned long long aesl_llvm_cbe_381_count = 0;
  static  unsigned long long aesl_llvm_cbe_382_count = 0;
  static  unsigned long long aesl_llvm_cbe_383_count = 0;
  static  unsigned long long aesl_llvm_cbe_384_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @test_case_4\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = bitcast [5 x [5 x i32]]* %%input to i8*, !dbg !4 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_295_count);
  llvm_cbe_tmp__122 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memcpy(i8* %%0, i8* bitcast ([5 x [5 x i32]]* @aesl_internal_test_case_4.input to i8*), i64 100 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_296_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__122, ( char *)(( char *)(&aesl_internal_test_case_4_OC_input)), 100ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",100ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__123);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast [3 x [3 x i32]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_298_count);
  llvm_cbe_tmp__124 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memcpy(i8* %%2, i8* bitcast ([3 x [3 x i32]]* @aesl_internal_test_case_4.kernel to i8*), i64 36 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_299_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__124, ( char *)(( char *)(&aesl_internal_test_case_4_OC_kernel)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__125);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [3 x [3 x i32]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_301_count);
  llvm_cbe_tmp__126 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%4, i32 0, i64 36 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_302_count);
  ( char *)memset(( char *)llvm_cbe_tmp__126, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__127);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x [5 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_303_count);
  llvm_cbe_tmp__128 = (signed int (*)[5])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x [3 x i32]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_304_count);
  llvm_cbe_tmp__129 = (signed int (*)[3])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_305_count);
  llvm_cbe_tmp__130 = (signed int (*)[3])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_convolution2D([5 x i32]* %%6, [3 x i32]* %%7, [3 x i32]* %%8) nounwind, !dbg !5 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_306_count);
  AESL_WRAP_convolution2D(llvm_cbe_tmp__128, llvm_cbe_tmp__129, llvm_cbe_tmp__130);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__151;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__151:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%11 ], [ 0, %%.preheader  for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__136);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__152;
  } else {
    llvm_cbe_tmp__137__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

llvm_cbe_tmp__152:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_322_count);
  llvm_cbe_tmp__131 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__131);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_323_count);
  llvm_cbe_tmp__132 = (signed int *)(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__131))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__131) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_324_count);
  llvm_cbe_tmp__133 = (unsigned int )*llvm_cbe_tmp__132;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__133);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_4.expected_output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_325_count);
  llvm_cbe_tmp__134 = (signed int *)(&aesl_internal_test_case_4_OC_expected_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__131))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__131));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__131) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_326_count);
  llvm_cbe_tmp__135 = (unsigned int )*llvm_cbe_tmp__134;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__135);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_328_count);
  llvm_cbe_tmp__136 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__136&4294967295ull)));
  if (((llvm_cbe_tmp__133&4294967295U) == (llvm_cbe_tmp__135&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__136;   /* for PHI node */
    goto llvm_cbe_tmp__151;
  } else {
    llvm_cbe_tmp__137__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 1, %%9 ], [ 0, %%11  for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_331_count);
  llvm_cbe_tmp__137 = (unsigned int )llvm_cbe_tmp__137__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__137);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__153;

llvm_cbe_tmp__154:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str6, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str6[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__155;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str7, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str7[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__155;

llvm_cbe_tmp__155:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @test_case_4}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__153:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.1 = phi i32 [ %%31, %%24 ], [ 0, %%.preheader.1  for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_storemerge1_2e_1_count);
  llvm_cbe_storemerge1_2e_1 = (unsigned int )llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.1 = 0x%X",llvm_cbe_storemerge1_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__143);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__156;
  } else {
    llvm_cbe_tmp__144__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__137;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

llvm_cbe_tmp__156:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%storemerge1.1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_347_count);
  llvm_cbe_tmp__138 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__138);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_348_count);
  llvm_cbe_tmp__139 = (signed int *)(&llvm_cbe_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__138))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__138) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_349_count);
  llvm_cbe_tmp__140 = (unsigned int )*llvm_cbe_tmp__139;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__140);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_4.expected_output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_350_count);
  llvm_cbe_tmp__141 = (signed int *)(&aesl_internal_test_case_4_OC_expected_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__138))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__138));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__138) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_351_count);
  llvm_cbe_tmp__142 = (unsigned int )*llvm_cbe_tmp__141;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__142);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge1.1, 1, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_353_count);
  llvm_cbe_tmp__143 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__143&4294967295ull)));
  if (((llvm_cbe_tmp__140&4294967295U) == (llvm_cbe_tmp__142&4294967295U))) {
    llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__143;   /* for PHI node */
    goto llvm_cbe_tmp__153;
  } else {
    llvm_cbe_tmp__144__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i32 [ %%19, %%22 ], [ 0, %%24  for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_356_count);
  llvm_cbe_tmp__144 = (unsigned int )llvm_cbe_tmp__144__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__144);
printf("\n = 0x%X",llvm_cbe_tmp__137);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__157;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__157:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.2 = phi i32 [ %%42, %%35 ], [ 0, %%.preheader.2  for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_storemerge1_2e_2_count);
  llvm_cbe_storemerge1_2e_2 = (unsigned int )llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.2 = 0x%X",llvm_cbe_storemerge1_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__150);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_2) < ((signed int )3u))) {
    goto llvm_cbe_tmp__158;
  } else {
    goto llvm_cbe_tmp__159;
  }

llvm_cbe_tmp__158:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%storemerge1.2 to i64, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_369_count);
  llvm_cbe_tmp__145 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__145);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_370_count);
  llvm_cbe_tmp__146 = (signed int *)(&llvm_cbe_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__145))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__145) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_371_count);
  llvm_cbe_tmp__147 = (unsigned int )*llvm_cbe_tmp__146;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__147);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_4.expected_output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_372_count);
  llvm_cbe_tmp__148 = (signed int *)(&aesl_internal_test_case_4_OC_expected_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__145))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__145));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__145) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_4.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_373_count);
  llvm_cbe_tmp__149 = (unsigned int )*llvm_cbe_tmp__148;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__149);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge1.2, 1, !dbg !6 for 0x%I64xth hint within @test_case_4  --> \n", ++aesl_llvm_cbe_375_count);
  llvm_cbe_tmp__150 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__150&4294967295ull)));
  if (((llvm_cbe_tmp__147&4294967295U) == (llvm_cbe_tmp__149&4294967295U))) {
    llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__150;   /* for PHI node */
    goto llvm_cbe_tmp__157;
  } else {
    goto llvm_cbe__2e_thread;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__159:
  if (((llvm_cbe_tmp__144&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__154;
  }

}


void test_case_5(void) {
  static  unsigned long long aesl_llvm_cbe_input_count = 0;
  signed int llvm_cbe_input[5][5];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_kernel_count = 0;
  signed int llvm_cbe_kernel[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_output_count = 0;
  signed int llvm_cbe_output[3][3];    /* Address-exposed local */
  static  unsigned long long aesl_llvm_cbe_385_count = 0;
  static  unsigned long long aesl_llvm_cbe_386_count = 0;
  static  unsigned long long aesl_llvm_cbe_387_count = 0;
  static  unsigned long long aesl_llvm_cbe_388_count = 0;
   char *llvm_cbe_tmp__160;
  static  unsigned long long aesl_llvm_cbe_389_count = 0;
   char *llvm_cbe_tmp__161;
  static  unsigned long long aesl_llvm_cbe_390_count = 0;
  static  unsigned long long aesl_llvm_cbe_391_count = 0;
   char *llvm_cbe_tmp__162;
  static  unsigned long long aesl_llvm_cbe_392_count = 0;
   char *llvm_cbe_tmp__163;
  static  unsigned long long aesl_llvm_cbe_393_count = 0;
  static  unsigned long long aesl_llvm_cbe_394_count = 0;
   char *llvm_cbe_tmp__164;
  static  unsigned long long aesl_llvm_cbe_395_count = 0;
   char *llvm_cbe_tmp__165;
  static  unsigned long long aesl_llvm_cbe_396_count = 0;
  signed int (*llvm_cbe_tmp__166)[5];
  static  unsigned long long aesl_llvm_cbe_397_count = 0;
  signed int (*llvm_cbe_tmp__167)[3];
  static  unsigned long long aesl_llvm_cbe_398_count = 0;
  signed int (*llvm_cbe_tmp__168)[3];
  static  unsigned long long aesl_llvm_cbe_399_count = 0;
  static  unsigned long long aesl_llvm_cbe_400_count = 0;
  static  unsigned long long aesl_llvm_cbe_401_count = 0;
  static  unsigned long long aesl_llvm_cbe_402_count = 0;
  static  unsigned long long aesl_llvm_cbe_403_count = 0;
  static  unsigned long long aesl_llvm_cbe_404_count = 0;
  static  unsigned long long aesl_llvm_cbe_405_count = 0;
  static  unsigned long long aesl_llvm_cbe_406_count = 0;
  static  unsigned long long aesl_llvm_cbe_407_count = 0;
  static  unsigned long long aesl_llvm_cbe_408_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_count = 0;
  unsigned int llvm_cbe_storemerge1;
  unsigned int llvm_cbe_storemerge1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_409_count = 0;
  static  unsigned long long aesl_llvm_cbe_410_count = 0;
  static  unsigned long long aesl_llvm_cbe_411_count = 0;
  static  unsigned long long aesl_llvm_cbe_412_count = 0;
  static  unsigned long long aesl_llvm_cbe_413_count = 0;
  static  unsigned long long aesl_llvm_cbe_414_count = 0;
  static  unsigned long long aesl_llvm_cbe_415_count = 0;
  unsigned long long llvm_cbe_tmp__169;
  static  unsigned long long aesl_llvm_cbe_416_count = 0;
  signed int *llvm_cbe_tmp__170;
  static  unsigned long long aesl_llvm_cbe_417_count = 0;
  unsigned int llvm_cbe_tmp__171;
  static  unsigned long long aesl_llvm_cbe_418_count = 0;
  signed int *llvm_cbe_tmp__172;
  static  unsigned long long aesl_llvm_cbe_419_count = 0;
  unsigned int llvm_cbe_tmp__173;
  static  unsigned long long aesl_llvm_cbe_420_count = 0;
  static  unsigned long long aesl_llvm_cbe_421_count = 0;
  unsigned int llvm_cbe_tmp__174;
  static  unsigned long long aesl_llvm_cbe_422_count = 0;
  static  unsigned long long aesl_llvm_cbe_423_count = 0;
  static  unsigned long long aesl_llvm_cbe_424_count = 0;
  unsigned int llvm_cbe_tmp__175;
  unsigned int llvm_cbe_tmp__175__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_425_count = 0;
  static  unsigned long long aesl_llvm_cbe_426_count = 0;
  static  unsigned long long aesl_llvm_cbe_427_count = 0;
  static  unsigned long long aesl_llvm_cbe_428_count = 0;
  static  unsigned long long aesl_llvm_cbe_429_count = 0;
  static  unsigned long long aesl_llvm_cbe_430_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts_count = 0;
  unsigned int llvm_cbe_puts;
  static  unsigned long long aesl_llvm_cbe_431_count = 0;
  static  unsigned long long aesl_llvm_cbe_puts2_count = 0;
  unsigned int llvm_cbe_puts2;
  static  unsigned long long aesl_llvm_cbe_432_count = 0;
  static  unsigned long long aesl_llvm_cbe_433_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_1_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_1;
  unsigned int llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_434_count = 0;
  static  unsigned long long aesl_llvm_cbe_435_count = 0;
  static  unsigned long long aesl_llvm_cbe_436_count = 0;
  static  unsigned long long aesl_llvm_cbe_437_count = 0;
  static  unsigned long long aesl_llvm_cbe_438_count = 0;
  static  unsigned long long aesl_llvm_cbe_439_count = 0;
  static  unsigned long long aesl_llvm_cbe_440_count = 0;
  unsigned long long llvm_cbe_tmp__176;
  static  unsigned long long aesl_llvm_cbe_441_count = 0;
  signed int *llvm_cbe_tmp__177;
  static  unsigned long long aesl_llvm_cbe_442_count = 0;
  unsigned int llvm_cbe_tmp__178;
  static  unsigned long long aesl_llvm_cbe_443_count = 0;
  signed int *llvm_cbe_tmp__179;
  static  unsigned long long aesl_llvm_cbe_444_count = 0;
  unsigned int llvm_cbe_tmp__180;
  static  unsigned long long aesl_llvm_cbe_445_count = 0;
  static  unsigned long long aesl_llvm_cbe_446_count = 0;
  unsigned int llvm_cbe_tmp__181;
  static  unsigned long long aesl_llvm_cbe_447_count = 0;
  static  unsigned long long aesl_llvm_cbe_448_count = 0;
  static  unsigned long long aesl_llvm_cbe_449_count = 0;
  unsigned int llvm_cbe_tmp__182;
  unsigned int llvm_cbe_tmp__182__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_450_count = 0;
  static  unsigned long long aesl_llvm_cbe_451_count = 0;
  static  unsigned long long aesl_llvm_cbe_452_count = 0;
  static  unsigned long long aesl_llvm_cbe_453_count = 0;
  static  unsigned long long aesl_llvm_cbe_454_count = 0;
  static  unsigned long long aesl_llvm_cbe_455_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge1_2e_2_count = 0;
  unsigned int llvm_cbe_storemerge1_2e_2;
  unsigned int llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_456_count = 0;
  static  unsigned long long aesl_llvm_cbe_457_count = 0;
  static  unsigned long long aesl_llvm_cbe_458_count = 0;
  static  unsigned long long aesl_llvm_cbe_459_count = 0;
  static  unsigned long long aesl_llvm_cbe_460_count = 0;
  static  unsigned long long aesl_llvm_cbe_461_count = 0;
  static  unsigned long long aesl_llvm_cbe_462_count = 0;
  unsigned long long llvm_cbe_tmp__183;
  static  unsigned long long aesl_llvm_cbe_463_count = 0;
  signed int *llvm_cbe_tmp__184;
  static  unsigned long long aesl_llvm_cbe_464_count = 0;
  unsigned int llvm_cbe_tmp__185;
  static  unsigned long long aesl_llvm_cbe_465_count = 0;
  signed int *llvm_cbe_tmp__186;
  static  unsigned long long aesl_llvm_cbe_466_count = 0;
  unsigned int llvm_cbe_tmp__187;
  static  unsigned long long aesl_llvm_cbe_467_count = 0;
  static  unsigned long long aesl_llvm_cbe_468_count = 0;
  unsigned int llvm_cbe_tmp__188;
  static  unsigned long long aesl_llvm_cbe_469_count = 0;
  static  unsigned long long aesl_llvm_cbe_470_count = 0;
  static  unsigned long long aesl_llvm_cbe_471_count = 0;
  static  unsigned long long aesl_llvm_cbe_472_count = 0;
  static  unsigned long long aesl_llvm_cbe_473_count = 0;
  static  unsigned long long aesl_llvm_cbe_474_count = 0;
  static  unsigned long long aesl_llvm_cbe_475_count = 0;
  static  unsigned long long aesl_llvm_cbe_476_count = 0;
  static  unsigned long long aesl_llvm_cbe_477_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @test_case_5\n");
if (AESL_DEBUG_TRACE)
printf("\n  %%0 = bitcast [5 x [5 x i32]]* %%input to i8*, !dbg !4 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_388_count);
  llvm_cbe_tmp__160 = ( char *)(( char *)(&llvm_cbe_input));
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = call i8* @memcpy(i8* %%0, i8* bitcast ([5 x [5 x i32]]* @aesl_internal_test_case_5.input to i8*), i64 100 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_389_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__160, ( char *)(( char *)(&aesl_internal_test_case_5_OC_input)), 100ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",100ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__161);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = bitcast [3 x [3 x i32]]* %%kernel to i8*, !dbg !4 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_391_count);
  llvm_cbe_tmp__162 = ( char *)(( char *)(&llvm_cbe_kernel));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = call i8* @memcpy(i8* %%2, i8* bitcast ([3 x [3 x i32]]* @aesl_internal_test_case_5.kernel to i8*), i64 36 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_392_count);
  ( char *)memcpy(( char *)llvm_cbe_tmp__162, ( char *)(( char *)(&aesl_internal_test_case_5_OC_kernel)), 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__163);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = bitcast [3 x [3 x i32]]* %%output to i8*, !dbg !5 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_394_count);
  llvm_cbe_tmp__164 = ( char *)(( char *)(&llvm_cbe_output));
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = call i8* @memset(i8* %%4, i32 0, i64 36 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_395_count);
  ( char *)memset(( char *)llvm_cbe_tmp__164, 0u, 36ull);
if (AESL_DEBUG_TRACE) {
printf("\nArgument  = 0x%X",0u);
printf("\nArgument  = 0x%I64X",36ull);
printf("\nReturn  = 0x%X",llvm_cbe_tmp__165);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = getelementptr inbounds [5 x [5 x i32]]* %%input, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_396_count);
  llvm_cbe_tmp__166 = (signed int (*)[5])(&llvm_cbe_input[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 5
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x [3 x i32]]* %%kernel, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_397_count);
  llvm_cbe_tmp__167 = (signed int (*)[3])(&llvm_cbe_kernel[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, !dbg !5 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_398_count);
  llvm_cbe_tmp__168 = (signed int (*)[3])(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  call void @AESL_WRAP_convolution2D([5 x i32]* %%6, [3 x i32]* %%7, [3 x i32]* %%8) nounwind, !dbg !5 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_399_count);
  AESL_WRAP_convolution2D(llvm_cbe_tmp__166, llvm_cbe_tmp__167, llvm_cbe_tmp__168);
if (AESL_DEBUG_TRACE) {
}
  llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__189;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__189:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1 = phi i32 [ %%18, %%11 ], [ 0, %%.preheader  for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_storemerge1_count);
  llvm_cbe_storemerge1 = (unsigned int )llvm_cbe_storemerge1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1 = 0x%X",llvm_cbe_storemerge1);
printf("\n = 0x%X",llvm_cbe_tmp__174);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__190;
  } else {
    llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned int )1u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

llvm_cbe_tmp__190:
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = sext i32 %%storemerge1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_415_count);
  llvm_cbe_tmp__169 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__169);
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_416_count);
  llvm_cbe_tmp__170 = (signed int *)(&llvm_cbe_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__169))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__169));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__169) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = load i32* %%13, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_417_count);
  llvm_cbe_tmp__171 = (unsigned int )*llvm_cbe_tmp__170;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__171);
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_5.expected_output, i64 0, i64 0, i64 %%12, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_418_count);
  llvm_cbe_tmp__172 = (signed int *)(&aesl_internal_test_case_5_OC_expected_output[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__169))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__169));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__169) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = load i32* %%15, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_419_count);
  llvm_cbe_tmp__173 = (unsigned int )*llvm_cbe_tmp__172;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__173);
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge1, 1, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_421_count);
  llvm_cbe_tmp__174 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__174&4294967295ull)));
  if (((llvm_cbe_tmp__171&4294967295U) == (llvm_cbe_tmp__173&4294967295U))) {
    llvm_cbe_storemerge1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__174;   /* for PHI node */
    goto llvm_cbe_tmp__189;
  } else {
    llvm_cbe_tmp__175__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_1;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_1:
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = phi i32 [ 1, %%9 ], [ 0, %%11  for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_424_count);
  llvm_cbe_tmp__175 = (unsigned int )llvm_cbe_tmp__175__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__175);
printf("\n = 0x%X",1u);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__191;

llvm_cbe_tmp__192:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str8, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_puts_count);
  puts(( char *)((&aesl_internal_str8[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts = 0x%X",llvm_cbe_puts);
}
  goto llvm_cbe_tmp__193;

llvm_cbe__2e_thread:
if (AESL_DEBUG_TRACE)
printf("\n  %%puts2 = call i32 @puts(i8* getelementptr inbounds ([18 x i8]* @aesl_internal_str9, i64 0, i64 0)), !dbg !7 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_puts2_count);
  puts(( char *)((&aesl_internal_str9[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 18
#endif
])));
if (AESL_DEBUG_TRACE) {
printf("\nReturn puts2 = 0x%X",llvm_cbe_puts2);
}
  goto llvm_cbe_tmp__193;

llvm_cbe_tmp__193:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @test_case_5}\n");
  return;
  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__191:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.1 = phi i32 [ %%31, %%24 ], [ 0, %%.preheader.1  for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_storemerge1_2e_1_count);
  llvm_cbe_storemerge1_2e_1 = (unsigned int )llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.1 = 0x%X",llvm_cbe_storemerge1_2e_1);
printf("\n = 0x%X",llvm_cbe_tmp__181);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_1) < ((signed int )3u))) {
    goto llvm_cbe_tmp__194;
  } else {
    llvm_cbe_tmp__182__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__175;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

llvm_cbe_tmp__194:
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = sext i32 %%storemerge1.1 to i64, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_440_count);
  llvm_cbe_tmp__176 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_1);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__176);
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_441_count);
  llvm_cbe_tmp__177 = (signed int *)(&llvm_cbe_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__176))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__176) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = load i32* %%26, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_442_count);
  llvm_cbe_tmp__178 = (unsigned int )*llvm_cbe_tmp__177;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__178);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_5.expected_output, i64 0, i64 1, i64 %%25, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_443_count);
  llvm_cbe_tmp__179 = (signed int *)(&aesl_internal_test_case_5_OC_expected_output[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__176))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__176));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__176) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_444_count);
  llvm_cbe_tmp__180 = (unsigned int )*llvm_cbe_tmp__179;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__180);
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = add nsw i32 %%storemerge1.1, 1, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_446_count);
  llvm_cbe_tmp__181 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_1&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__181&4294967295ull)));
  if (((llvm_cbe_tmp__178&4294967295U) == (llvm_cbe_tmp__180&4294967295U))) {
    llvm_cbe_storemerge1_2e_1__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__181;   /* for PHI node */
    goto llvm_cbe_tmp__191;
  } else {
    llvm_cbe_tmp__182__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
    goto llvm_cbe__2e_preheader_2e_2;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe__2e_preheader_2e_2:
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = phi i32 [ %%19, %%22 ], [ 0, %%24  for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_449_count);
  llvm_cbe_tmp__182 = (unsigned int )llvm_cbe_tmp__182__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%X",llvm_cbe_tmp__182);
printf("\n = 0x%X",llvm_cbe_tmp__175);
printf("\n = 0x%X",0u);
}
  llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe_tmp__195;

  do {     /* Syntactic loop '' to make GCC happy */
llvm_cbe_tmp__195:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge1.2 = phi i32 [ %%42, %%35 ], [ 0, %%.preheader.2  for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_storemerge1_2e_2_count);
  llvm_cbe_storemerge1_2e_2 = (unsigned int )llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge1.2 = 0x%X",llvm_cbe_storemerge1_2e_2);
printf("\n = 0x%X",llvm_cbe_tmp__188);
printf("\n = 0x%X",0u);
}
  if ((((signed int )llvm_cbe_storemerge1_2e_2) < ((signed int )3u))) {
    goto llvm_cbe_tmp__196;
  } else {
    goto llvm_cbe_tmp__197;
  }

llvm_cbe_tmp__196:
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = sext i32 %%storemerge1.2 to i64, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_462_count);
  llvm_cbe_tmp__183 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge1_2e_2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__183);
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = getelementptr inbounds [3 x [3 x i32]]* %%output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_463_count);
  llvm_cbe_tmp__184 = (signed int *)(&llvm_cbe_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__183))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__183) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = load i32* %%37, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_464_count);
  llvm_cbe_tmp__185 = (unsigned int )*llvm_cbe_tmp__184;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__185);
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = getelementptr inbounds [3 x [3 x i32]]* @aesl_internal_test_case_5.expected_output, i64 0, i64 2, i64 %%36, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_465_count);
  llvm_cbe_tmp__186 = (signed int *)(&aesl_internal_test_case_5_OC_expected_output[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__183))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__183));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);
  if (!(((signed long long )llvm_cbe_tmp__183) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'aesl_internal_test_case_5.expected_output' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = load i32* %%39, align 4, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_466_count);
  llvm_cbe_tmp__187 = (unsigned int )*llvm_cbe_tmp__186;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__187);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = add nsw i32 %%storemerge1.2, 1, !dbg !6 for 0x%I64xth hint within @test_case_5  --> \n", ++aesl_llvm_cbe_468_count);
  llvm_cbe_tmp__188 = (unsigned int )((unsigned int )(llvm_cbe_storemerge1_2e_2&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__188&4294967295ull)));
  if (((llvm_cbe_tmp__185&4294967295U) == (llvm_cbe_tmp__187&4294967295U))) {
    llvm_cbe_storemerge1_2e_2__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__188;   /* for PHI node */
    goto llvm_cbe_tmp__195;
  } else {
    goto llvm_cbe__2e_thread;
  }

  } while (1); /* end of syntactic loop '' */
llvm_cbe_tmp__197:
  if (((llvm_cbe_tmp__182&4294967295U) == (0u&4294967295U))) {
    goto llvm_cbe__2e_thread;
  } else {
    goto llvm_cbe_tmp__192;
  }

}


signed int main(void) {
  static  unsigned long long aesl_llvm_cbe_478_count = 0;
  static  unsigned long long aesl_llvm_cbe_479_count = 0;
  static  unsigned long long aesl_llvm_cbe_480_count = 0;
  static  unsigned long long aesl_llvm_cbe_481_count = 0;
  static  unsigned long long aesl_llvm_cbe_482_count = 0;
  static  unsigned long long aesl_llvm_cbe_483_count = 0;
  CODE_FOR_MAIN();
const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @main\n");
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @test_case_1(), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_478_count);
   /*tail*/ test_case_1();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @test_case_2(), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_479_count);
   /*tail*/ test_case_2();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @test_case_3(), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_480_count);
   /*tail*/ test_case_3();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @test_case_4(), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_481_count);
   /*tail*/ test_case_4();
if (AESL_DEBUG_TRACE) {
}
if (AESL_DEBUG_TRACE)
printf("\n  tail call void @test_case_5(), !dbg !3 for 0x%I64xth hint within @main  --> \n", ++aesl_llvm_cbe_482_count);
   /*tail*/ test_case_5();
if (AESL_DEBUG_TRACE) {
}
  if (AESL_DEBUG_TRACE)
      printf("\nEND @main}\n");
  return 0u;
}

