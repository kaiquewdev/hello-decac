%module ExecutionEngine
%{
#include <llvm-c/ExecutionEngine.h>
%}

%include "carrays.i"
%array_functions(LLVMValueRef,LLVMValueRefArray)
%array_functions(LLVMGenericValueRef,LLVMGenericValueRefArray)
%array_functions(LLVMExecutionEngineRef,LLVMExecutionEngineRefArray)
%array_functions(LLVMModuleRef,LLVMModuleRefArray)
%array_functions(char*,StringArray)
/*===-- llvm-c/ExecutionEngine.h - ExecutionEngine Lib C Iface --*- C++ -*-===*\
|*                                                                            *|
|*                     The LLVM Compiler Infrastructure                       *|
|*                                                                            *|
|* This file is distributed under the University of Illinois Open Source      *|
|* License. See LICENSE.TXT for details.                                      *|
|*                                                                            *|
|*===----------------------------------------------------------------------===*|
|*                                                                            *|
|* This header declares the C interface to libLLVMExecutionEngine.o, which    *|
|* implements various analyses of the LLVM IR.                                *|
|*                                                                            *|
|* Many exotic languages can interoperate with C code but have a harder time  *|
|* with C++ due to name mangling. So in addition to C, this interface enables *|
|* tools written in such languages.                                           *|
|*                                                                            *|
\*===----------------------------------------------------------------------===*/

#ifndef LLVM_C_EXECUTIONENGINE_H
#define LLVM_C_EXECUTIONENGINE_H

#include "llvm-c/Core.h"
#include "llvm-c/Target.h"

#ifdef __cplusplus
extern "C" {
#endif

void LLVMLinkInJIT(void);
void LLVMLinkInInterpreter(void);

typedef int LLVMBool;
typedef struct LLVMOpaqueModule *LLVMModuleRef;
typedef struct LLVMOpaqueTargetData *LLVMTargetDataRef;
typedef struct LLVMOpaqueValue *LLVMValueRef;
typedef struct LLVMOpaqueGenericValue *LLVMGenericValueRef;
typedef struct LLVMOpaqueExecutionEngine *LLVMExecutionEngineRef;
typedef struct LLVMOpaqueType *LLVMTypeRef;
typedef struct LLVMOpaqueModule *LLVMModuleRef;

/*===-- Operations on generic values --------------------------------------===*/

LLVMGenericValueRef LLVMCreateGenericValueOfInt(LLVMTypeRef Ty,
                                                unsigned long long N,
                                                LLVMBool IsSigned);

LLVMGenericValueRef LLVMCreateGenericValueOfPointer(void *P);

LLVMGenericValueRef LLVMCreateGenericValueOfFloat(LLVMTypeRef Ty, double N);

unsigned LLVMGenericValueIntWidth(LLVMGenericValueRef GenValRef);

unsigned long long LLVMGenericValueToInt(LLVMGenericValueRef GenVal,
                                         LLVMBool IsSigned);

void *LLVMGenericValueToPointer(LLVMGenericValueRef GenVal);

double LLVMGenericValueToFloat(LLVMTypeRef TyRef, LLVMGenericValueRef GenVal);

void LLVMDisposeGenericValue(LLVMGenericValueRef GenVal);

/*===-- Operations on execution engines -----------------------------------===*/

LLVMBool LLVMCreateExecutionEngineForModule(LLVMExecutionEngineRef *OutEng,
                                            LLVMModuleRef M,
                                            char **OutError);

LLVMBool LLVMCreateInterpreterForModule(LLVMExecutionEngineRef *OutIntr,
                                        LLVMModuleRef M,
                                        char **OutError);

LLVMBool LLVMCreateJITCompilerForModule(LLVMExecutionEngineRef *OutJit,
                                        LLVMModuleRef M,
                                        unsigned OptLevel,
                                        char **OutError);

/** Deprecated: Use LLVMCreateExecutionEngineForModule instead. */
/*LLVMBool LLVMCreateExecutionEngine(LLVMExecutionEngineRef *OUTPUT,
                                   LLVMModuleProviderRef MP,
                                   char **OUTPUT);*/

/** Deprecated: Use LLVMCreateInterpreterForModule instead. */
/* LLVMBool LLVMCreateInterpreter(LLVMExecutionEngineRef *OUTPUT,
                               LLVMModuleProviderRef MP,
                               char **OUTPUT); */

/** Deprecated: Use LLVMCreateJITCompilerForModule instead. */
/* LLVMBool LLVMCreateJITCompiler(LLVMExecutionEngineRef *OUTPUT,
                               LLVMModuleProviderRef MP,
                               unsigned OptLevel,
                               char **OUTPUT); */

void LLVMDisposeExecutionEngine(LLVMExecutionEngineRef EE);

void LLVMRunStaticConstructors(LLVMExecutionEngineRef EE);

void LLVMRunStaticDestructors(LLVMExecutionEngineRef EE);

int LLVMRunFunctionAsMain(LLVMExecutionEngineRef EE, LLVMValueRef F,
                          unsigned ArgC, const char * const *ArgV,
                          const char * const *EnvP);

LLVMGenericValueRef LLVMRunFunction(LLVMExecutionEngineRef EE, LLVMValueRef F,
                                    unsigned NumArgs,
                                    LLVMGenericValueRef *Args);

void LLVMFreeMachineCodeForFunction(LLVMExecutionEngineRef EE, LLVMValueRef F);

void LLVMAddModule(LLVMExecutionEngineRef EE, LLVMModuleRef M);

/** Deprecated: Use LLVMAddModule instead. */
//void LLVMAddModuleProvider(LLVMExecutionEngineRef EE, LLVMModuleProviderRef MP);

LLVMBool LLVMRemoveModule(LLVMExecutionEngineRef EE, LLVMModuleRef M,
                          LLVMModuleRef *OutMod, char **OutErr);

/** Deprecated: Use LLVMRemoveModule instead. */
/* LLVMBool LLVMRemoveModuleProvider(LLVMExecutionEngineRef EE,
                                  LLVMModuleProviderRef MP,
                                  LLVMModuleRef *OutMod, char **OutError); */

LLVMBool LLVMFindFunction(LLVMExecutionEngineRef EE, const char *Name,
                          LLVMValueRef *OutFunc);

LLVMTargetDataRef LLVMGetExecutionEngineTargetData(LLVMExecutionEngineRef EE);

void LLVMAddGlobalMapping(LLVMExecutionEngineRef EE, LLVMValueRef Global,
                          void* Addr);

void *LLVMGetPointerToGlobal(LLVMExecutionEngineRef EE, LLVMValueRef Global);

#ifdef __cplusplus
}

namespace llvm {
  struct GenericValue;
  class ExecutionEngine;
  
  #define DEFINE_SIMPLE_CONVERSION_FUNCTIONS(ty, ref)   \
    inline ty *unwrap(ref P) {                          \
      return reinterpret_cast<ty*>(P);                  \
    }                                                   \
                                                        \
    inline ref wrap(const ty *P) {                      \
      return reinterpret_cast<ref>(const_cast<ty*>(P)); \
    }
  
  DEFINE_SIMPLE_CONVERSION_FUNCTIONS(GenericValue,    LLVMGenericValueRef   )
  DEFINE_SIMPLE_CONVERSION_FUNCTIONS(ExecutionEngine, LLVMExecutionEngineRef)
  
  #undef DEFINE_SIMPLE_CONVERSION_FUNCTIONS
}
  
#endif /* defined(__cplusplus) */

#endif
