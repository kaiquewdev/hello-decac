package jllvm;

import jllvm.llvm.Core;
import jllvm.llvm.SWIGTYPE_p_LLVMOpaqueValue;
import java.math.BigInteger;

public class LLVMConstantBoolean extends LLVMConstantInteger {
	public LLVMConstantBoolean(SWIGTYPE_p_LLVMOpaqueValue c) {
		super(c);
		assert(typeOf().equals(LLVMIntegerType.i1));
	}
	
	public LLVMConstantBoolean(boolean val) {
		super((Core.LLVMConstInt(Core.LLVMInt1Type(),BigInteger.valueOf(val ? 1 : 0),1)));
	}
}
