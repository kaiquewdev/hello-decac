/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package jllvm.llvm;

class BitReaderJNI {
  public final static native int LLVMParseBitcode(long jarg1, long jarg2, long jarg3);
  public final static native int LLVMParseBitcodeInContext(long jarg1, long jarg2, long jarg3, long jarg4);
  public final static native int LLVMGetBitcodeModuleInContext(long jarg1, long jarg2, long jarg3, long jarg4);
  public final static native int LLVMGetBitcodeModule(long jarg1, long jarg2, long jarg3);
  public final static native int LLVMGetBitcodeModuleProviderInContext(long jarg1, long jarg2, long jarg3, long jarg4);
  public final static native int LLVMGetBitcodeModuleProvider(long jarg1, long jarg2, long jarg3);
}
