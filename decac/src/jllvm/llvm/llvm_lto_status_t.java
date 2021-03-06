/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.40
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package jllvm.llvm;

public final class llvm_lto_status_t {
  public final static llvm_lto_status_t LLVM_LTO_UNKNOWN = new llvm_lto_status_t("LLVM_LTO_UNKNOWN");
  public final static llvm_lto_status_t LLVM_LTO_OPT_SUCCESS = new llvm_lto_status_t("LLVM_LTO_OPT_SUCCESS");
  public final static llvm_lto_status_t LLVM_LTO_READ_SUCCESS = new llvm_lto_status_t("LLVM_LTO_READ_SUCCESS");
  public final static llvm_lto_status_t LLVM_LTO_READ_FAILURE = new llvm_lto_status_t("LLVM_LTO_READ_FAILURE");
  public final static llvm_lto_status_t LLVM_LTO_WRITE_FAILURE = new llvm_lto_status_t("LLVM_LTO_WRITE_FAILURE");
  public final static llvm_lto_status_t LLVM_LTO_NO_TARGET = new llvm_lto_status_t("LLVM_LTO_NO_TARGET");
  public final static llvm_lto_status_t LLVM_LTO_NO_WORK = new llvm_lto_status_t("LLVM_LTO_NO_WORK");
  public final static llvm_lto_status_t LLVM_LTO_MODULE_MERGE_FAILURE = new llvm_lto_status_t("LLVM_LTO_MODULE_MERGE_FAILURE");
  public final static llvm_lto_status_t LLVM_LTO_ASM_FAILURE = new llvm_lto_status_t("LLVM_LTO_ASM_FAILURE");
  public final static llvm_lto_status_t LLVM_LTO_NULL_OBJECT = new llvm_lto_status_t("LLVM_LTO_NULL_OBJECT");

  public final int swigValue() {
    return swigValue;
  }

  public String toString() {
    return swigName;
  }

  public static llvm_lto_status_t swigToEnum(int swigValue) {
    if (swigValue < swigValues.length && swigValue >= 0 && swigValues[swigValue].swigValue == swigValue)
      return swigValues[swigValue];
    for (int i = 0; i < swigValues.length; i++)
      if (swigValues[i].swigValue == swigValue)
        return swigValues[i];
    throw new IllegalArgumentException("No enum " + llvm_lto_status_t.class + " with value " + swigValue);
  }

  private llvm_lto_status_t(String swigName) {
    this.swigName = swigName;
    this.swigValue = swigNext++;
  }

  private llvm_lto_status_t(String swigName, int swigValue) {
    this.swigName = swigName;
    this.swigValue = swigValue;
    swigNext = swigValue+1;
  }

  private llvm_lto_status_t(String swigName, llvm_lto_status_t swigEnum) {
    this.swigName = swigName;
    this.swigValue = swigEnum.swigValue;
    swigNext = this.swigValue+1;
  }

  private static llvm_lto_status_t[] swigValues = { LLVM_LTO_UNKNOWN, LLVM_LTO_OPT_SUCCESS, LLVM_LTO_READ_SUCCESS, LLVM_LTO_READ_FAILURE, LLVM_LTO_WRITE_FAILURE, LLVM_LTO_NO_TARGET, LLVM_LTO_NO_WORK, LLVM_LTO_MODULE_MERGE_FAILURE, LLVM_LTO_ASM_FAILURE, LLVM_LTO_NULL_OBJECT };
  private static int swigNext = 0;
  private final int swigValue;
  private final String swigName;
}

