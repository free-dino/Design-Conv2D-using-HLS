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

/* Function Declarations */
double fmod(double, double);
float fmodf(float, float);
long double fmodl(long double, long double);
void convolution2D(signed int (*llvm_cbe_input)[5], signed int (*llvm_cbe_kernel)[3], signed int (*llvm_cbe_output)[3]);


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

void convolution2D(signed int (*llvm_cbe_input)[5], signed int (*llvm_cbe_kernel)[3], signed int (*llvm_cbe_output)[3]) {
  static  unsigned long long aesl_llvm_cbe_1_count = 0;
  static  unsigned long long aesl_llvm_cbe_2_count = 0;
  static  unsigned long long aesl_llvm_cbe_3_count = 0;
  static  unsigned long long aesl_llvm_cbe_4_count = 0;
  static  unsigned long long aesl_llvm_cbe_5_count = 0;
  static  unsigned long long aesl_llvm_cbe_6_count = 0;
  static  unsigned long long aesl_llvm_cbe_7_count = 0;
  static  unsigned long long aesl_llvm_cbe_8_count = 0;
  static  unsigned long long aesl_llvm_cbe_9_count = 0;
  static  unsigned long long aesl_llvm_cbe_10_count = 0;
  static  unsigned long long aesl_llvm_cbe_11_count = 0;
  static  unsigned long long aesl_llvm_cbe_12_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge10_count = 0;
  unsigned int llvm_cbe_storemerge10;
  unsigned int llvm_cbe_storemerge10__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_13_count = 0;
  static  unsigned long long aesl_llvm_cbe_14_count = 0;
  static  unsigned long long aesl_llvm_cbe_15_count = 0;
  static  unsigned long long aesl_llvm_cbe_16_count = 0;
  static  unsigned long long aesl_llvm_cbe_17_count = 0;
  unsigned long long llvm_cbe_tmp__1;
  static  unsigned long long aesl_llvm_cbe_18_count = 0;
  unsigned int llvm_cbe_tmp__2;
  static  unsigned long long aesl_llvm_cbe_19_count = 0;
  unsigned long long llvm_cbe_tmp__3;
  static  unsigned long long aesl_llvm_cbe_20_count = 0;
  static  unsigned long long aesl_llvm_cbe_storemerge19_count = 0;
  unsigned int llvm_cbe_storemerge19;
  unsigned int llvm_cbe_storemerge19__PHI_TEMPORARY;
  static  unsigned long long aesl_llvm_cbe_21_count = 0;
  static  unsigned long long aesl_llvm_cbe_22_count = 0;
  static  unsigned long long aesl_llvm_cbe_23_count = 0;
  static  unsigned long long aesl_llvm_cbe_24_count = 0;
  static  unsigned long long aesl_llvm_cbe_25_count = 0;
  unsigned long long llvm_cbe_tmp__4;
  static  unsigned long long aesl_llvm_cbe_26_count = 0;
  static  unsigned long long aesl_llvm_cbe_27_count = 0;
  static  unsigned long long aesl_llvm_cbe_28_count = 0;
  static  unsigned long long aesl_llvm_cbe_29_count = 0;
  static  unsigned long long aesl_llvm_cbe_30_count = 0;
  signed int *llvm_cbe_tmp__5;
  static  unsigned long long aesl_llvm_cbe_31_count = 0;
  unsigned int llvm_cbe_tmp__6;
  static  unsigned long long aesl_llvm_cbe_32_count = 0;
  signed int *llvm_cbe_tmp__7;
  static  unsigned long long aesl_llvm_cbe_33_count = 0;
  unsigned int llvm_cbe_tmp__8;
  static  unsigned long long aesl_llvm_cbe_34_count = 0;
  unsigned int llvm_cbe_tmp__9;
  static  unsigned long long aesl_llvm_cbe_35_count = 0;
  static  unsigned long long aesl_llvm_cbe_36_count = 0;
  static  unsigned long long aesl_llvm_cbe_37_count = 0;
  static  unsigned long long aesl_llvm_cbe_38_count = 0;
  static  unsigned long long aesl_llvm_cbe_39_count = 0;
  static  unsigned long long aesl_llvm_cbe_40_count = 0;
  static  unsigned long long aesl_llvm_cbe_41_count = 0;
  static  unsigned long long aesl_llvm_cbe_42_count = 0;
  static  unsigned long long aesl_llvm_cbe_43_count = 0;
  unsigned int llvm_cbe_tmp__10;
  static  unsigned long long aesl_llvm_cbe_44_count = 0;
  unsigned long long llvm_cbe_tmp__11;
  static  unsigned long long aesl_llvm_cbe_45_count = 0;
  signed int *llvm_cbe_tmp__12;
  static  unsigned long long aesl_llvm_cbe_46_count = 0;
  unsigned int llvm_cbe_tmp__13;
  static  unsigned long long aesl_llvm_cbe_47_count = 0;
  signed int *llvm_cbe_tmp__14;
  static  unsigned long long aesl_llvm_cbe_48_count = 0;
  unsigned int llvm_cbe_tmp__15;
  static  unsigned long long aesl_llvm_cbe_49_count = 0;
  unsigned int llvm_cbe_tmp__16;
  static  unsigned long long aesl_llvm_cbe_50_count = 0;
  unsigned int llvm_cbe_tmp__17;
  static  unsigned long long aesl_llvm_cbe_51_count = 0;
  static  unsigned long long aesl_llvm_cbe_52_count = 0;
  static  unsigned long long aesl_llvm_cbe_53_count = 0;
  static  unsigned long long aesl_llvm_cbe_54_count = 0;
  static  unsigned long long aesl_llvm_cbe_55_count = 0;
  static  unsigned long long aesl_llvm_cbe_56_count = 0;
  static  unsigned long long aesl_llvm_cbe_57_count = 0;
  static  unsigned long long aesl_llvm_cbe_58_count = 0;
  static  unsigned long long aesl_llvm_cbe_59_count = 0;
  unsigned int llvm_cbe_tmp__18;
  static  unsigned long long aesl_llvm_cbe_60_count = 0;
  unsigned long long llvm_cbe_tmp__19;
  static  unsigned long long aesl_llvm_cbe_61_count = 0;
  signed int *llvm_cbe_tmp__20;
  static  unsigned long long aesl_llvm_cbe_62_count = 0;
  unsigned int llvm_cbe_tmp__21;
  static  unsigned long long aesl_llvm_cbe_63_count = 0;
  signed int *llvm_cbe_tmp__22;
  static  unsigned long long aesl_llvm_cbe_64_count = 0;
  unsigned int llvm_cbe_tmp__23;
  static  unsigned long long aesl_llvm_cbe_65_count = 0;
  unsigned int llvm_cbe_tmp__24;
  static  unsigned long long aesl_llvm_cbe_66_count = 0;
  unsigned int llvm_cbe_tmp__25;
  static  unsigned long long aesl_llvm_cbe_67_count = 0;
  static  unsigned long long aesl_llvm_cbe_68_count = 0;
  static  unsigned long long aesl_llvm_cbe_69_count = 0;
  static  unsigned long long aesl_llvm_cbe_70_count = 0;
  static  unsigned long long aesl_llvm_cbe_71_count = 0;
  static  unsigned long long aesl_llvm_cbe_72_count = 0;
  static  unsigned long long aesl_llvm_cbe_73_count = 0;
  static  unsigned long long aesl_llvm_cbe_74_count = 0;
  static  unsigned long long aesl_llvm_cbe_75_count = 0;
  static  unsigned long long aesl_llvm_cbe_76_count = 0;
  static  unsigned long long aesl_llvm_cbe_77_count = 0;
  static  unsigned long long aesl_llvm_cbe_78_count = 0;
  static  unsigned long long aesl_llvm_cbe_79_count = 0;
  static  unsigned long long aesl_llvm_cbe_80_count = 0;
  static  unsigned long long aesl_llvm_cbe_81_count = 0;
  static  unsigned long long aesl_llvm_cbe_82_count = 0;
  static  unsigned long long aesl_llvm_cbe_83_count = 0;
  static  unsigned long long aesl_llvm_cbe_84_count = 0;
  unsigned int llvm_cbe_tmp__26;
  static  unsigned long long aesl_llvm_cbe_85_count = 0;
  unsigned long long llvm_cbe_tmp__27;
  static  unsigned long long aesl_llvm_cbe_86_count = 0;
  signed int *llvm_cbe_tmp__28;
  static  unsigned long long aesl_llvm_cbe_87_count = 0;
  unsigned int llvm_cbe_tmp__29;
  static  unsigned long long aesl_llvm_cbe_88_count = 0;
  signed int *llvm_cbe_tmp__30;
  static  unsigned long long aesl_llvm_cbe_89_count = 0;
  unsigned int llvm_cbe_tmp__31;
  static  unsigned long long aesl_llvm_cbe_90_count = 0;
  unsigned int llvm_cbe_tmp__32;
  static  unsigned long long aesl_llvm_cbe_91_count = 0;
  unsigned int llvm_cbe_tmp__33;
  static  unsigned long long aesl_llvm_cbe_92_count = 0;
  static  unsigned long long aesl_llvm_cbe_93_count = 0;
  static  unsigned long long aesl_llvm_cbe_94_count = 0;
  static  unsigned long long aesl_llvm_cbe_95_count = 0;
  static  unsigned long long aesl_llvm_cbe_96_count = 0;
  static  unsigned long long aesl_llvm_cbe_97_count = 0;
  static  unsigned long long aesl_llvm_cbe_98_count = 0;
  static  unsigned long long aesl_llvm_cbe_99_count = 0;
  static  unsigned long long aesl_llvm_cbe_100_count = 0;
  signed int *llvm_cbe_tmp__34;
  static  unsigned long long aesl_llvm_cbe_101_count = 0;
  unsigned int llvm_cbe_tmp__35;
  static  unsigned long long aesl_llvm_cbe_102_count = 0;
  signed int *llvm_cbe_tmp__36;
  static  unsigned long long aesl_llvm_cbe_103_count = 0;
  unsigned int llvm_cbe_tmp__37;
  static  unsigned long long aesl_llvm_cbe_104_count = 0;
  unsigned int llvm_cbe_tmp__38;
  static  unsigned long long aesl_llvm_cbe_105_count = 0;
  unsigned int llvm_cbe_tmp__39;
  static  unsigned long long aesl_llvm_cbe_106_count = 0;
  static  unsigned long long aesl_llvm_cbe_107_count = 0;
  static  unsigned long long aesl_llvm_cbe_108_count = 0;
  static  unsigned long long aesl_llvm_cbe_109_count = 0;
  static  unsigned long long aesl_llvm_cbe_110_count = 0;
  static  unsigned long long aesl_llvm_cbe_111_count = 0;
  static  unsigned long long aesl_llvm_cbe_112_count = 0;
  static  unsigned long long aesl_llvm_cbe_113_count = 0;
  static  unsigned long long aesl_llvm_cbe_114_count = 0;
  signed int *llvm_cbe_tmp__40;
  static  unsigned long long aesl_llvm_cbe_115_count = 0;
  unsigned int llvm_cbe_tmp__41;
  static  unsigned long long aesl_llvm_cbe_116_count = 0;
  signed int *llvm_cbe_tmp__42;
  static  unsigned long long aesl_llvm_cbe_117_count = 0;
  unsigned int llvm_cbe_tmp__43;
  static  unsigned long long aesl_llvm_cbe_118_count = 0;
  unsigned int llvm_cbe_tmp__44;
  static  unsigned long long aesl_llvm_cbe_119_count = 0;
  unsigned int llvm_cbe_tmp__45;
  static  unsigned long long aesl_llvm_cbe_120_count = 0;
  static  unsigned long long aesl_llvm_cbe_121_count = 0;
  static  unsigned long long aesl_llvm_cbe_122_count = 0;
  static  unsigned long long aesl_llvm_cbe_123_count = 0;
  static  unsigned long long aesl_llvm_cbe_124_count = 0;
  static  unsigned long long aesl_llvm_cbe_125_count = 0;
  static  unsigned long long aesl_llvm_cbe_126_count = 0;
  static  unsigned long long aesl_llvm_cbe_127_count = 0;
  static  unsigned long long aesl_llvm_cbe_128_count = 0;
  static  unsigned long long aesl_llvm_cbe_129_count = 0;
  static  unsigned long long aesl_llvm_cbe_130_count = 0;
  static  unsigned long long aesl_llvm_cbe_131_count = 0;
  static  unsigned long long aesl_llvm_cbe_132_count = 0;
  static  unsigned long long aesl_llvm_cbe_133_count = 0;
  static  unsigned long long aesl_llvm_cbe_134_count = 0;
  static  unsigned long long aesl_llvm_cbe_135_count = 0;
  static  unsigned long long aesl_llvm_cbe_136_count = 0;
  static  unsigned long long aesl_llvm_cbe_137_count = 0;
  signed int *llvm_cbe_tmp__46;
  static  unsigned long long aesl_llvm_cbe_138_count = 0;
  unsigned int llvm_cbe_tmp__47;
  static  unsigned long long aesl_llvm_cbe_139_count = 0;
  signed int *llvm_cbe_tmp__48;
  static  unsigned long long aesl_llvm_cbe_140_count = 0;
  unsigned int llvm_cbe_tmp__49;
  static  unsigned long long aesl_llvm_cbe_141_count = 0;
  unsigned int llvm_cbe_tmp__50;
  static  unsigned long long aesl_llvm_cbe_142_count = 0;
  unsigned int llvm_cbe_tmp__51;
  static  unsigned long long aesl_llvm_cbe_143_count = 0;
  static  unsigned long long aesl_llvm_cbe_144_count = 0;
  static  unsigned long long aesl_llvm_cbe_145_count = 0;
  static  unsigned long long aesl_llvm_cbe_146_count = 0;
  static  unsigned long long aesl_llvm_cbe_147_count = 0;
  static  unsigned long long aesl_llvm_cbe_148_count = 0;
  static  unsigned long long aesl_llvm_cbe_149_count = 0;
  static  unsigned long long aesl_llvm_cbe_150_count = 0;
  static  unsigned long long aesl_llvm_cbe_151_count = 0;
  signed int *llvm_cbe_tmp__52;
  static  unsigned long long aesl_llvm_cbe_152_count = 0;
  unsigned int llvm_cbe_tmp__53;
  static  unsigned long long aesl_llvm_cbe_153_count = 0;
  signed int *llvm_cbe_tmp__54;
  static  unsigned long long aesl_llvm_cbe_154_count = 0;
  unsigned int llvm_cbe_tmp__55;
  static  unsigned long long aesl_llvm_cbe_155_count = 0;
  unsigned int llvm_cbe_tmp__56;
  static  unsigned long long aesl_llvm_cbe_156_count = 0;
  unsigned int llvm_cbe_tmp__57;
  static  unsigned long long aesl_llvm_cbe_157_count = 0;
  static  unsigned long long aesl_llvm_cbe_158_count = 0;
  static  unsigned long long aesl_llvm_cbe_159_count = 0;
  static  unsigned long long aesl_llvm_cbe_160_count = 0;
  static  unsigned long long aesl_llvm_cbe_161_count = 0;
  static  unsigned long long aesl_llvm_cbe_162_count = 0;
  static  unsigned long long aesl_llvm_cbe_163_count = 0;
  static  unsigned long long aesl_llvm_cbe_164_count = 0;
  static  unsigned long long aesl_llvm_cbe_165_count = 0;
  signed int *llvm_cbe_tmp__58;
  static  unsigned long long aesl_llvm_cbe_166_count = 0;
  unsigned int llvm_cbe_tmp__59;
  static  unsigned long long aesl_llvm_cbe_167_count = 0;
  signed int *llvm_cbe_tmp__60;
  static  unsigned long long aesl_llvm_cbe_168_count = 0;
  unsigned int llvm_cbe_tmp__61;
  static  unsigned long long aesl_llvm_cbe_169_count = 0;
  unsigned int llvm_cbe_tmp__62;
  static  unsigned long long aesl_llvm_cbe_170_count = 0;
  unsigned int llvm_cbe_tmp__63;
  static  unsigned long long aesl_llvm_cbe_171_count = 0;
  static  unsigned long long aesl_llvm_cbe_172_count = 0;
  static  unsigned long long aesl_llvm_cbe_173_count = 0;
  static  unsigned long long aesl_llvm_cbe_174_count = 0;
  static  unsigned long long aesl_llvm_cbe_175_count = 0;
  static  unsigned long long aesl_llvm_cbe_176_count = 0;
  static  unsigned long long aesl_llvm_cbe_177_count = 0;
  static  unsigned long long aesl_llvm_cbe_178_count = 0;
  static  unsigned long long aesl_llvm_cbe_179_count = 0;
  static  unsigned long long aesl_llvm_cbe_180_count = 0;
  static  unsigned long long aesl_llvm_cbe_181_count = 0;
  static  unsigned long long aesl_llvm_cbe_182_count = 0;
  static  unsigned long long aesl_llvm_cbe_183_count = 0;
  static  unsigned long long aesl_llvm_cbe_184_count = 0;
  signed int *llvm_cbe_tmp__64;
  static  unsigned long long aesl_llvm_cbe_185_count = 0;
  static  unsigned long long aesl_llvm_cbe_186_count = 0;
  static  unsigned long long aesl_llvm_cbe_187_count = 0;
  static  unsigned long long aesl_llvm_cbe_188_count = 0;
  static  unsigned long long aesl_llvm_cbe_189_count = 0;
  static  unsigned long long aesl_llvm_cbe_190_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond_count = 0;
  static  unsigned long long aesl_llvm_cbe_191_count = 0;
  static  unsigned long long aesl_llvm_cbe_192_count = 0;
  static  unsigned long long aesl_llvm_cbe_193_count = 0;
  static  unsigned long long aesl_llvm_cbe_194_count = 0;
  static  unsigned long long aesl_llvm_cbe_195_count = 0;
  static  unsigned long long aesl_llvm_cbe_196_count = 0;
  static  unsigned long long aesl_llvm_cbe_exitcond11_count = 0;
  static  unsigned long long aesl_llvm_cbe_197_count = 0;
  static  unsigned long long aesl_llvm_cbe_198_count = 0;

const char* AESL_DEBUG_TRACE = getenv("DEBUG_TRACE");
if (AESL_DEBUG_TRACE)
printf("\n\{ BEGIN @convolution2D\n");
  llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader8;

  do {     /* Syntactic loop '.preheader8' to make GCC happy */
llvm_cbe__2e_preheader8:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge10 = phi i32 [ 0, %%0 ], [ %%26, %%65  for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_storemerge10_count);
  llvm_cbe_storemerge10 = (unsigned int )llvm_cbe_storemerge10__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge10 = 0x%X",llvm_cbe_storemerge10);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__26);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%1 = sext i32 %%storemerge10 to i64, !dbg !4 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_17_count);
  llvm_cbe_tmp__1 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__1);
if (AESL_DEBUG_TRACE)
printf("\n  %%2 = add nsw i32 %%storemerge10, 2, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_18_count);
  llvm_cbe_tmp__2 = (unsigned int )((unsigned int )(llvm_cbe_storemerge10&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__2&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%3 = sext i32 %%2 to i64, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_19_count);
  llvm_cbe_tmp__3 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__2);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__3);
  llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )0u;   /* for PHI node */
  goto llvm_cbe__2e_preheader5;

llvm_cbe_tmp__65:
  if (((llvm_cbe_tmp__26&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__66;
  } else {
    llvm_cbe_storemerge10__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__26;   /* for PHI node */
    goto llvm_cbe__2e_preheader8;
  }

  do {     /* Syntactic loop '.preheader5' to make GCC happy */
llvm_cbe__2e_preheader5:
if (AESL_DEBUG_TRACE)
printf("\n  %%storemerge19 = phi i32 [ 0, %%.preheader8 ], [ %%10, %%.preheader5  for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_storemerge19_count);
  llvm_cbe_storemerge19 = (unsigned int )llvm_cbe_storemerge19__PHI_TEMPORARY;
if (AESL_DEBUG_TRACE) {
printf("\nstoremerge19 = 0x%X",llvm_cbe_storemerge19);
printf("\n = 0x%X",0u);
printf("\n = 0x%X",llvm_cbe_tmp__10);
}
if (AESL_DEBUG_TRACE)
printf("\n  %%4 = sext i32 %%storemerge19 to i64, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_25_count);
  llvm_cbe_tmp__4 = (unsigned long long )((signed long long )(signed int )llvm_cbe_storemerge19);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__4);
if (AESL_DEBUG_TRACE)
printf("\n  %%5 = getelementptr inbounds [5 x i32]* %%input, i64 %%1, i64 %%4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_30_count);
  llvm_cbe_tmp__5 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__4) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%6 = load i32* %%5, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_31_count);
  llvm_cbe_tmp__6 = (unsigned int )*llvm_cbe_tmp__5;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__6);
if (AESL_DEBUG_TRACE)
printf("\n  %%7 = getelementptr inbounds [3 x i32]* %%kernel, i64 0, i64 0, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_32_count);
  llvm_cbe_tmp__7 = (signed int *)(&(*llvm_cbe_kernel)[(((signed long long )0ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%8 = load i32* %%7, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_33_count);
  llvm_cbe_tmp__8 = (unsigned int )*llvm_cbe_tmp__7;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__8);
if (AESL_DEBUG_TRACE)
printf("\n  %%9 = mul nsw i32 %%8, %%6, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_34_count);
  llvm_cbe_tmp__9 = (unsigned int )((unsigned int )(llvm_cbe_tmp__8&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__6&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__9&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%10 = add nsw i32 %%storemerge19, 1, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_43_count);
  llvm_cbe_tmp__10 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__10&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%11 = sext i32 %%10 to i64, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_44_count);
  llvm_cbe_tmp__11 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__10);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__11);
if (AESL_DEBUG_TRACE)
printf("\n  %%12 = getelementptr inbounds [5 x i32]* %%input, i64 %%1, i64 %%11, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_45_count);
  llvm_cbe_tmp__12 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__11) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%13 = load i32* %%12, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_46_count);
  llvm_cbe_tmp__13 = (unsigned int )*llvm_cbe_tmp__12;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__13);
if (AESL_DEBUG_TRACE)
printf("\n  %%14 = getelementptr inbounds [3 x i32]* %%kernel, i64 0, i64 1, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_47_count);
  llvm_cbe_tmp__14 = (signed int *)(&(*llvm_cbe_kernel)[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%15 = load i32* %%14, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_48_count);
  llvm_cbe_tmp__15 = (unsigned int )*llvm_cbe_tmp__14;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__15);
if (AESL_DEBUG_TRACE)
printf("\n  %%16 = mul nsw i32 %%15, %%13, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_49_count);
  llvm_cbe_tmp__16 = (unsigned int )((unsigned int )(llvm_cbe_tmp__15&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__13&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__16&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%17 = add nsw i32 %%16, %%9, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_50_count);
  llvm_cbe_tmp__17 = (unsigned int )((unsigned int )(llvm_cbe_tmp__16&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__9&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__17&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%18 = add nsw i32 %%storemerge19, 2, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_59_count);
  llvm_cbe_tmp__18 = (unsigned int )((unsigned int )(llvm_cbe_storemerge19&4294967295ull)) + ((unsigned int )(2u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__18&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%19 = sext i32 %%18 to i64, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_60_count);
  llvm_cbe_tmp__19 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__18);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__19);
if (AESL_DEBUG_TRACE)
printf("\n  %%20 = getelementptr inbounds [5 x i32]* %%input, i64 %%1, i64 %%19, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_61_count);
  llvm_cbe_tmp__20 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__19) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%21 = load i32* %%20, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_62_count);
  llvm_cbe_tmp__21 = (unsigned int )*llvm_cbe_tmp__20;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__21);
if (AESL_DEBUG_TRACE)
printf("\n  %%22 = getelementptr inbounds [3 x i32]* %%kernel, i64 0, i64 2, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_63_count);
  llvm_cbe_tmp__22 = (signed int *)(&(*llvm_cbe_kernel)[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%23 = load i32* %%22, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_64_count);
  llvm_cbe_tmp__23 = (unsigned int )*llvm_cbe_tmp__22;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__23);
if (AESL_DEBUG_TRACE)
printf("\n  %%24 = mul nsw i32 %%23, %%21, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_65_count);
  llvm_cbe_tmp__24 = (unsigned int )((unsigned int )(llvm_cbe_tmp__23&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__21&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__24&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%25 = add nsw i32 %%24, %%17, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_66_count);
  llvm_cbe_tmp__25 = (unsigned int )((unsigned int )(llvm_cbe_tmp__24&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__17&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__25&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%26 = add nsw i32 %%storemerge10, 1, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_84_count);
  llvm_cbe_tmp__26 = (unsigned int )((unsigned int )(llvm_cbe_storemerge10&4294967295ull)) + ((unsigned int )(1u&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__26&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%27 = sext i32 %%26 to i64, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_85_count);
  llvm_cbe_tmp__27 = (unsigned long long )((signed long long )(signed int )llvm_cbe_tmp__26);
if (AESL_DEBUG_TRACE)
printf("\n = 0x%I64X\n", llvm_cbe_tmp__27);
if (AESL_DEBUG_TRACE)
printf("\n  %%28 = getelementptr inbounds [5 x i32]* %%input, i64 %%27, i64 %%4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_86_count);
  llvm_cbe_tmp__28 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__4) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%29 = load i32* %%28, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_87_count);
  llvm_cbe_tmp__29 = (unsigned int )*llvm_cbe_tmp__28;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__29);
if (AESL_DEBUG_TRACE)
printf("\n  %%30 = getelementptr inbounds [3 x i32]* %%kernel, i64 1, i64 0, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_88_count);
  llvm_cbe_tmp__30 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%31 = load i32* %%30, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_89_count);
  llvm_cbe_tmp__31 = (unsigned int )*llvm_cbe_tmp__30;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__31);
if (AESL_DEBUG_TRACE)
printf("\n  %%32 = mul nsw i32 %%31, %%29, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_90_count);
  llvm_cbe_tmp__32 = (unsigned int )((unsigned int )(llvm_cbe_tmp__31&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__29&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__32&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%33 = add nsw i32 %%32, %%25, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_91_count);
  llvm_cbe_tmp__33 = (unsigned int )((unsigned int )(llvm_cbe_tmp__32&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__25&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__33&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%34 = getelementptr inbounds [5 x i32]* %%input, i64 %%27, i64 %%11, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_100_count);
  llvm_cbe_tmp__34 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__11) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%35 = load i32* %%34, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_101_count);
  llvm_cbe_tmp__35 = (unsigned int )*llvm_cbe_tmp__34;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__35);
if (AESL_DEBUG_TRACE)
printf("\n  %%36 = getelementptr inbounds [3 x i32]* %%kernel, i64 1, i64 1, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_102_count);
  llvm_cbe_tmp__36 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%37 = load i32* %%36, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_103_count);
  llvm_cbe_tmp__37 = (unsigned int )*llvm_cbe_tmp__36;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__37);
if (AESL_DEBUG_TRACE)
printf("\n  %%38 = mul nsw i32 %%37, %%35, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_104_count);
  llvm_cbe_tmp__38 = (unsigned int )((unsigned int )(llvm_cbe_tmp__37&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__35&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__38&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%39 = add nsw i32 %%38, %%33, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_105_count);
  llvm_cbe_tmp__39 = (unsigned int )((unsigned int )(llvm_cbe_tmp__38&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__33&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__39&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%40 = getelementptr inbounds [5 x i32]* %%input, i64 %%27, i64 %%19, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_114_count);
  llvm_cbe_tmp__40 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__27))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__27));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__19) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%41 = load i32* %%40, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_115_count);
  llvm_cbe_tmp__41 = (unsigned int )*llvm_cbe_tmp__40;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__41);
if (AESL_DEBUG_TRACE)
printf("\n  %%42 = getelementptr inbounds [3 x i32]* %%kernel, i64 1, i64 2, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_116_count);
  llvm_cbe_tmp__42 = (signed int *)(&llvm_cbe_kernel[(((signed long long )1ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%43 = load i32* %%42, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_117_count);
  llvm_cbe_tmp__43 = (unsigned int )*llvm_cbe_tmp__42;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__43);
if (AESL_DEBUG_TRACE)
printf("\n  %%44 = mul nsw i32 %%43, %%41, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_118_count);
  llvm_cbe_tmp__44 = (unsigned int )((unsigned int )(llvm_cbe_tmp__43&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__41&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__44&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%45 = add nsw i32 %%44, %%39, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_119_count);
  llvm_cbe_tmp__45 = (unsigned int )((unsigned int )(llvm_cbe_tmp__44&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__39&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__45&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%46 = getelementptr inbounds [5 x i32]* %%input, i64 %%3, i64 %%4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_137_count);
  llvm_cbe_tmp__46 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__3))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__4) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%47 = load i32* %%46, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_138_count);
  llvm_cbe_tmp__47 = (unsigned int )*llvm_cbe_tmp__46;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__47);
if (AESL_DEBUG_TRACE)
printf("\n  %%48 = getelementptr inbounds [3 x i32]* %%kernel, i64 2, i64 0, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_139_count);
  llvm_cbe_tmp__48 = (signed int *)(&llvm_cbe_kernel[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )0ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )0ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%49 = load i32* %%48, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_140_count);
  llvm_cbe_tmp__49 = (unsigned int )*llvm_cbe_tmp__48;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__49);
if (AESL_DEBUG_TRACE)
printf("\n  %%50 = mul nsw i32 %%49, %%47, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_141_count);
  llvm_cbe_tmp__50 = (unsigned int )((unsigned int )(llvm_cbe_tmp__49&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__47&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__50&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%51 = add nsw i32 %%50, %%45, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_142_count);
  llvm_cbe_tmp__51 = (unsigned int )((unsigned int )(llvm_cbe_tmp__50&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__45&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__51&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%52 = getelementptr inbounds [5 x i32]* %%input, i64 %%3, i64 %%11, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_151_count);
  llvm_cbe_tmp__52 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__3))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__11))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__11));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__11) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%53 = load i32* %%52, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_152_count);
  llvm_cbe_tmp__53 = (unsigned int )*llvm_cbe_tmp__52;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__53);
if (AESL_DEBUG_TRACE)
printf("\n  %%54 = getelementptr inbounds [3 x i32]* %%kernel, i64 2, i64 1, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_153_count);
  llvm_cbe_tmp__54 = (signed int *)(&llvm_cbe_kernel[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )1ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )1ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%55 = load i32* %%54, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_154_count);
  llvm_cbe_tmp__55 = (unsigned int )*llvm_cbe_tmp__54;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__55);
if (AESL_DEBUG_TRACE)
printf("\n  %%56 = mul nsw i32 %%55, %%53, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_155_count);
  llvm_cbe_tmp__56 = (unsigned int )((unsigned int )(llvm_cbe_tmp__55&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__53&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__56&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%57 = add nsw i32 %%56, %%51, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_156_count);
  llvm_cbe_tmp__57 = (unsigned int )((unsigned int )(llvm_cbe_tmp__56&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__51&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__57&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%58 = getelementptr inbounds [5 x i32]* %%input, i64 %%3, i64 %%19, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_165_count);
  llvm_cbe_tmp__58 = (signed int *)(&llvm_cbe_input[(((signed long long )llvm_cbe_tmp__3))
#ifdef AESL_BC_SIM
 % 5
#endif
][(((signed long long )llvm_cbe_tmp__19))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__3));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__19));
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )llvm_cbe_tmp__19) < 5)) fprintf(stderr, "%s:%d: warning: Read access out of array 'input' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%59 = load i32* %%58, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_166_count);
  llvm_cbe_tmp__59 = (unsigned int )*llvm_cbe_tmp__58;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__59);
if (AESL_DEBUG_TRACE)
printf("\n  %%60 = getelementptr inbounds [3 x i32]* %%kernel, i64 2, i64 2, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_167_count);
  llvm_cbe_tmp__60 = (signed int *)(&llvm_cbe_kernel[(((signed long long )2ull))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )2ull))]);
if (AESL_DEBUG_TRACE) {
}

#ifdef AESL_BC_SIM
  if (!(((signed long long )2ull) < 3)) fprintf(stderr, "%s:%d: warning: Read access out of array 'kernel' bound?\n", __FILE__, __LINE__);

#endif
if (AESL_DEBUG_TRACE)
printf("\n  %%61 = load i32* %%60, align 4, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_168_count);
  llvm_cbe_tmp__61 = (unsigned int )*llvm_cbe_tmp__60;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__61);
if (AESL_DEBUG_TRACE)
printf("\n  %%62 = mul nsw i32 %%61, %%59, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_169_count);
  llvm_cbe_tmp__62 = (unsigned int )((unsigned int )(llvm_cbe_tmp__61&4294967295ull)) * ((unsigned int )(llvm_cbe_tmp__59&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__62&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%63 = add nsw i32 %%62, %%57, !dbg !2 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_170_count);
  llvm_cbe_tmp__63 = (unsigned int )((unsigned int )(llvm_cbe_tmp__62&4294967295ull)) + ((unsigned int )(llvm_cbe_tmp__57&4294967295ull));
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", ((unsigned int )(llvm_cbe_tmp__63&4294967295ull)));
if (AESL_DEBUG_TRACE)
printf("\n  %%64 = getelementptr inbounds [3 x i32]* %%output, i64 %%1, i64 %%4, !dbg !4 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_184_count);
  llvm_cbe_tmp__64 = (signed int *)(&llvm_cbe_output[(((signed long long )llvm_cbe_tmp__1))
#ifdef AESL_BC_SIM
 % 3
#endif
][(((signed long long )llvm_cbe_tmp__4))]);
if (AESL_DEBUG_TRACE) {
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__1));
printf("\n = 0x%I64X",((signed long long )llvm_cbe_tmp__4));
}

#ifdef AESL_BC_SIM
  assert(((signed long long )llvm_cbe_tmp__4) < 3 && "Write access out of array 'output' bound?");

#endif
if (AESL_DEBUG_TRACE)
printf("\n  store i32 %%63, i32* %%64, align 4, !dbg !4 for 0x%I64xth hint within @convolution2D  --> \n", ++aesl_llvm_cbe_185_count);
  *llvm_cbe_tmp__64 = llvm_cbe_tmp__63;
if (AESL_DEBUG_TRACE)
printf("\n = 0x%X\n", llvm_cbe_tmp__63);
  if (((llvm_cbe_tmp__10&4294967295U) == (3u&4294967295U))) {
    goto llvm_cbe_tmp__65;
  } else {
    llvm_cbe_storemerge19__PHI_TEMPORARY = (unsigned int )llvm_cbe_tmp__10;   /* for PHI node */
    goto llvm_cbe__2e_preheader5;
  }

  } while (1); /* end of syntactic loop '.preheader5' */
  } while (1); /* end of syntactic loop '.preheader8' */
llvm_cbe_tmp__66:
  if (AESL_DEBUG_TRACE)
      printf("\nEND @convolution2D}\n");
  return;
}

