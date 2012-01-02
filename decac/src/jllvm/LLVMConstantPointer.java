package jllvm;

import jllvm.llvm.Core;
import jllvm.llvm.SWIGTYPE_p_LLVMOpaqueValue;

public class LLVMConstantPointer extends LLVMConstant {
	public LLVMConstantPointer(SWIGTYPE_p_LLVMOpaqueValue c) {
		super(c);
		assert(typeOf() instanceof LLVMPointerType);
	}
	
	public LLVMConstantExpression toInteger(LLVMPointerType targetType) {
		return new LLVMConstantExpression(Core.LLVMConstPtrToInt(instance,targetType.getInstance()));
	}
}
