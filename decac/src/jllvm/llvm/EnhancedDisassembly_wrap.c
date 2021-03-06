/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

#define SWIGJAVA

/* -----------------------------------------------------------------------------
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 * ----------------------------------------------------------------------------- */

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
# if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#  define SWIGTEMPLATEDISAMBIGUATOR template
# elif defined(__HP_aCC)
/* Needed even with `aCC -AA' when `aCC -V' reports HP ANSI C++ B3910B A.03.55 */
/* If we find a maximum version that requires this, the test would be __HP_aCC <= 35500 for A.03.55 */
#  define SWIGTEMPLATEDISAMBIGUATOR template
# else
#  define SWIGTEMPLATEDISAMBIGUATOR
# endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define SWIGUNUSED __attribute__ ((__unused__)) 
#   else
#     define SWIGUNUSED
#   endif
# elif defined(__ICC)
#   define SWIGUNUSED __attribute__ ((__unused__)) 
# else
#   define SWIGUNUSED 
# endif
#endif

#ifndef SWIG_MSC_UNSUPPRESS_4505
# if defined(_MSC_VER)
#   pragma warning(disable : 4505) /* unreferenced local function has been removed */
# endif 
#endif

#ifndef SWIGUNUSEDPARM
# ifdef __cplusplus
#   define SWIGUNUSEDPARM(p)
# else
#   define SWIGUNUSEDPARM(p) p SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods */
#if (__GNUC__ >= 4) || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4)
#  ifndef GCC_HASCLASSVISIBILITY
#    define GCC_HASCLASSVISIBILITY
#  endif
#endif

#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   if defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
#     define SWIGEXPORT __attribute__ ((visibility("default")))
#   else
#     define SWIGEXPORT
#   endif
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif

/* Deal with Microsoft's attempt at deprecating C standard runtime functions */
#if !defined(SWIG_NO_CRT_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
# define _CRT_SECURE_NO_DEPRECATE
#endif

/* Deal with Microsoft's attempt at deprecating methods in the standard C++ library */
#if !defined(SWIG_NO_SCL_SECURE_NO_DEPRECATE) && defined(_MSC_VER) && !defined(_SCL_SECURE_NO_DEPRECATE)
# define _SCL_SECURE_NO_DEPRECATE
#endif



/* Fix for jlong on some versions of gcc on Windows */
#if defined(__GNUC__) && !defined(__INTEL_COMPILER)
  typedef long long __int64;
#endif

/* Fix for jlong on 64-bit x86 Solaris */
#if defined(__x86_64)
# ifdef _LP64
#   undef _LP64
# endif
#endif

#include <jni.h>
#include <stdlib.h>
#include <string.h>


/* Support for throwing Java exceptions */
typedef enum {
  SWIG_JavaOutOfMemoryError = 1, 
  SWIG_JavaIOException, 
  SWIG_JavaRuntimeException, 
  SWIG_JavaIndexOutOfBoundsException,
  SWIG_JavaArithmeticException,
  SWIG_JavaIllegalArgumentException,
  SWIG_JavaNullPointerException,
  SWIG_JavaDirectorPureVirtual,
  SWIG_JavaUnknownError
} SWIG_JavaExceptionCodes;

typedef struct {
  SWIG_JavaExceptionCodes code;
  const char *java_exception;
} SWIG_JavaExceptions_t;


static void SWIGUNUSED SWIG_JavaThrowException(JNIEnv *jenv, SWIG_JavaExceptionCodes code, const char *msg) {
  jclass excep;
  static const SWIG_JavaExceptions_t java_exceptions[] = {
    { SWIG_JavaOutOfMemoryError, "java/lang/OutOfMemoryError" },
    { SWIG_JavaIOException, "java/io/IOException" },
    { SWIG_JavaRuntimeException, "java/lang/RuntimeException" },
    { SWIG_JavaIndexOutOfBoundsException, "java/lang/IndexOutOfBoundsException" },
    { SWIG_JavaArithmeticException, "java/lang/ArithmeticException" },
    { SWIG_JavaIllegalArgumentException, "java/lang/IllegalArgumentException" },
    { SWIG_JavaNullPointerException, "java/lang/NullPointerException" },
    { SWIG_JavaDirectorPureVirtual, "java/lang/RuntimeException" },
    { SWIG_JavaUnknownError,  "java/lang/UnknownError" },
    { (SWIG_JavaExceptionCodes)0,  "java/lang/UnknownError" }
  };
  const SWIG_JavaExceptions_t *except_ptr = java_exceptions;

  while (except_ptr->code != code && except_ptr->code)
    except_ptr++;

  (*jenv)->ExceptionClear(jenv);
  excep = (*jenv)->FindClass(jenv, except_ptr->java_exception);
  if (excep)
    (*jenv)->ThrowNew(jenv, excep, msg);
}


/* Contract support */

#define SWIG_contract_assert(nullreturn, expr, msg) if (!(expr)) {SWIG_JavaThrowException(jenv, SWIG_JavaIllegalArgumentException, msg); return nullreturn; } else


#include <llvm-c/EnhancedDisassembly.h>


static unsigned *new_UnsignedIntArray(int nelements) { 
  return (unsigned *) calloc(nelements,sizeof(unsigned)); 
}

static void delete_UnsignedIntArray(unsigned *ary) { 
  free(ary); 
}

static unsigned UnsignedIntArray_getitem(unsigned *ary, int index) {
    return ary[index];
}
static void UnsignedIntArray_setitem(unsigned *ary, int index, unsigned value) {
    ary[index] = value;
}


#ifdef __cplusplus
extern "C" {
#endif

SWIGEXPORT jlong JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_new_1UnsignedIntArray(JNIEnv *jenv, jclass jcls, jint jarg1) {
  jlong jresult = 0 ;
  int arg1 ;
  unsigned int *result = 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = (int)jarg1; 
  result = (unsigned int *)new_UnsignedIntArray(arg1);
  *(unsigned int **)&jresult = result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_delete_1UnsignedIntArray(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  unsigned int *arg1 = (unsigned int *) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  delete_UnsignedIntArray(arg1);
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_UnsignedIntArray_1getitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2) {
  jlong jresult = 0 ;
  unsigned int *arg1 = (unsigned int *) 0 ;
  int arg2 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  arg2 = (int)jarg2; 
  result = (unsigned int)UnsignedIntArray_getitem(arg1,arg2);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_UnsignedIntArray_1setitem(JNIEnv *jenv, jclass jcls, jlong jarg1, jint jarg2, jlong jarg3) {
  unsigned int *arg1 = (unsigned int *) 0 ;
  int arg2 ;
  unsigned int arg3 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  arg2 = (int)jarg2; 
  arg3 = (unsigned int)jarg3; 
  UnsignedIntArray_setitem(arg1,arg2,arg3);
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_kEDAssemblySyntaxX86Intel_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  EDAssemblySyntax_t result;
  
  (void)jenv;
  (void)jcls;
  result = (EDAssemblySyntax_t)kEDAssemblySyntaxX86Intel;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_kEDAssemblySyntaxX86ATT_1get(JNIEnv *jenv, jclass jcls) {
  jint jresult = 0 ;
  EDAssemblySyntax_t result;
  
  (void)jenv;
  (void)jcls;
  result = (EDAssemblySyntax_t)kEDAssemblySyntaxX86ATT;
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetDisassembler(JNIEnv *jenv, jclass jcls, jlong jarg1, jstring jarg2, jint jarg3) {
  jint jresult = 0 ;
  EDDisassemblerRef *arg1 = (EDDisassemblerRef *) 0 ;
  char *arg2 = (char *) 0 ;
  EDAssemblySyntax_t arg3 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDDisassemblerRef **)&jarg1; 
  arg2 = 0;
  if (jarg2) {
    arg2 = (char *)(*jenv)->GetStringUTFChars(jenv, jarg2, 0);
    if (!arg2) return 0;
  }
  arg3 = (EDAssemblySyntax_t)jarg3; 
  result = (int)EDGetDisassembler(arg1,(char const *)arg2,arg3);
  jresult = (jint)result; 
  if (arg2) (*jenv)->ReleaseStringUTFChars(jenv, jarg2, (const char *)arg2);
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetRegisterName(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3) {
  jint jresult = 0 ;
  char **arg1 = (char **) 0 ;
  EDDisassemblerRef arg2 = (EDDisassemblerRef) 0 ;
  unsigned int arg3 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(char ***)&jarg1; 
  arg2 = *(EDDisassemblerRef *)&jarg2; 
  arg3 = (unsigned int)jarg3; 
  result = (int)EDGetRegisterName((char const **)arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDRegisterIsStackPointer(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  EDDisassemblerRef arg1 = (EDDisassemblerRef) 0 ;
  unsigned int arg2 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDDisassemblerRef *)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  result = (int)EDRegisterIsStackPointer(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDRegisterIsProgramCounter(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  EDDisassemblerRef arg1 = (EDDisassemblerRef) 0 ;
  unsigned int arg2 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDDisassemblerRef *)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  result = (int)EDRegisterIsProgramCounter(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jlong JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDCreateInsts(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4, jlong jarg5, jlong jarg6) {
  jlong jresult = 0 ;
  EDInstRef *arg1 = (EDInstRef *) 0 ;
  unsigned int arg2 ;
  EDDisassemblerRef arg3 = (EDDisassemblerRef) 0 ;
  EDByteReaderCallback arg4 = (EDByteReaderCallback) 0 ;
  uint64_t arg5 ;
  void *arg6 = (void *) 0 ;
  uint64_t *argp5 ;
  unsigned int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef **)&jarg1; 
  arg2 = (unsigned int)jarg2; 
  arg3 = *(EDDisassemblerRef *)&jarg3; 
  arg4 = *(EDByteReaderCallback *)&jarg4; 
  argp5 = *(uint64_t **)&jarg5; 
  if (!argp5) {
    SWIG_JavaThrowException(jenv, SWIG_JavaNullPointerException, "Attempt to dereference null uint64_t");
    return 0;
  }
  arg5 = *argp5; 
  arg6 = *(void **)&jarg6; 
  result = (unsigned int)EDCreateInsts(arg1,arg2,arg3,arg4,arg5,arg6);
  jresult = (jlong)result; 
  return jresult;
}


SWIGEXPORT void JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDReleaseInst(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  EDInstRef arg1 = (EDInstRef) 0 ;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  EDReleaseInst(arg1);
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDInstByteSize(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDInstByteSize(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetInstString(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  char **arg1 = (char **) 0 ;
  EDInstRef arg2 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(char ***)&jarg1; 
  arg2 = *(EDInstRef *)&jarg2; 
  result = (int)EDGetInstString((char const **)arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDInstID(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  unsigned int *arg1 = (unsigned int *) 0 ;
  EDInstRef arg2 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  arg2 = *(EDInstRef *)&jarg2; 
  result = (int)EDInstID(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDInstIsBranch(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDInstIsBranch(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDInstIsMove(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDInstIsMove(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDBranchTargetID(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDBranchTargetID(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDMoveSourceID(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDMoveSourceID(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDMoveTargetID(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDMoveTargetID(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDNumTokens(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDNumTokens(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetToken(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jint jarg3) {
  jint jresult = 0 ;
  EDTokenRef *arg1 = (EDTokenRef *) 0 ;
  EDInstRef arg2 = (EDInstRef) 0 ;
  int arg3 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef **)&jarg1; 
  arg2 = *(EDInstRef *)&jarg2; 
  arg3 = (int)jarg3; 
  result = (int)EDGetToken(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetTokenString(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  char **arg1 = (char **) 0 ;
  EDTokenRef arg2 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(char ***)&jarg1; 
  arg2 = *(EDTokenRef *)&jarg2; 
  result = (int)EDGetTokenString((char const **)arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDOperandIndexForToken(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDOperandIndexForToken(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsWhitespace(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsWhitespace(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsPunctuation(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsPunctuation(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsOpcode(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsOpcode(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsLiteral(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsLiteral(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsRegister(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsRegister(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDTokenIsNegativeLiteral(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDTokenRef arg1 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDTokenRef *)&jarg1; 
  result = (int)EDTokenIsNegativeLiteral(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDLiteralTokenAbsoluteValue(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  uint64_t *arg1 = (uint64_t *) 0 ;
  EDTokenRef arg2 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(uint64_t **)&jarg1; 
  arg2 = *(EDTokenRef *)&jarg2; 
  result = (int)EDLiteralTokenAbsoluteValue(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDRegisterTokenValue(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  unsigned int *arg1 = (unsigned int *) 0 ;
  EDTokenRef arg2 = (EDTokenRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  arg2 = *(EDTokenRef *)&jarg2; 
  result = (int)EDRegisterTokenValue(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDNumOperands(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDInstRef arg1 = (EDInstRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDInstRef *)&jarg1; 
  result = (int)EDNumOperands(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDGetOperand(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jint jarg3) {
  jint jresult = 0 ;
  EDOperandRef *arg1 = (EDOperandRef *) 0 ;
  EDInstRef arg2 = (EDInstRef) 0 ;
  int arg3 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDOperandRef **)&jarg1; 
  arg2 = *(EDInstRef *)&jarg2; 
  arg3 = (int)jarg3; 
  result = (int)EDGetOperand(arg1,arg2,arg3);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDOperandIsRegister(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDOperandRef arg1 = (EDOperandRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDOperandRef *)&jarg1; 
  result = (int)EDOperandIsRegister(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDOperandIsImmediate(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDOperandRef arg1 = (EDOperandRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDOperandRef *)&jarg1; 
  result = (int)EDOperandIsImmediate(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDOperandIsMemory(JNIEnv *jenv, jclass jcls, jlong jarg1) {
  jint jresult = 0 ;
  EDOperandRef arg1 = (EDOperandRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(EDOperandRef *)&jarg1; 
  result = (int)EDOperandIsMemory(arg1);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDRegisterOperandValue(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  unsigned int *arg1 = (unsigned int *) 0 ;
  EDOperandRef arg2 = (EDOperandRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(unsigned int **)&jarg1; 
  arg2 = *(EDOperandRef *)&jarg2; 
  result = (int)EDRegisterOperandValue(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDImmediateOperandValue(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2) {
  jint jresult = 0 ;
  uint64_t *arg1 = (uint64_t *) 0 ;
  EDOperandRef arg2 = (EDOperandRef) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(uint64_t **)&jarg1; 
  arg2 = *(EDOperandRef *)&jarg2; 
  result = (int)EDImmediateOperandValue(arg1,arg2);
  jresult = (jint)result; 
  return jresult;
}


SWIGEXPORT jint JNICALL Java_jllvm_llvm_EnhancedDisassemblyJNI_EDEvaluateOperand(JNIEnv *jenv, jclass jcls, jlong jarg1, jlong jarg2, jlong jarg3, jlong jarg4) {
  jint jresult = 0 ;
  uint64_t *arg1 = (uint64_t *) 0 ;
  EDOperandRef arg2 = (EDOperandRef) 0 ;
  EDRegisterReaderCallback arg3 = (EDRegisterReaderCallback) 0 ;
  void *arg4 = (void *) 0 ;
  int result;
  
  (void)jenv;
  (void)jcls;
  arg1 = *(uint64_t **)&jarg1; 
  arg2 = *(EDOperandRef *)&jarg2; 
  arg3 = *(EDRegisterReaderCallback *)&jarg3; 
  arg4 = *(void **)&jarg4; 
  result = (int)EDEvaluateOperand(arg1,arg2,arg3,arg4);
  jresult = (jint)result; 
  return jresult;
}


#ifdef __cplusplus
}
#endif

