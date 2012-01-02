package jllvm;

import jllvm.llvm.Core;
import jllvm.llvm.LLVMTypeKind;
import jllvm.llvm.SWIGTYPE_p_LLVMOpaqueType;

public class LLVMX86FP80Type extends LLVMRealType {
	public LLVMX86FP80Type() {
		super(Core.LLVMX86FP80Type());
	}
	
	public LLVMX86FP80Type(SWIGTYPE_p_LLVMOpaqueType t) {
		super(t);
		assert(Core.LLVMGetTypeKind(t) == LLVMTypeKind.LLVMX86_FP80TypeKind);
	}
}
