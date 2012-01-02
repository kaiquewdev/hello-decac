package jllvm;

import jllvm.llvm.Core;

public class LLVMLoadInstruction extends LLVMInstruction {
	public LLVMLoadInstruction(LLVMInstructionBuilder builder,LLVMValue pointer,String name) {
		assert(pointer.typeOf() instanceof LLVMPointerType);
		instance = Core.LLVMBuildLoad(builder.getInstance(),pointer.getInstance(),name);
	}
}
