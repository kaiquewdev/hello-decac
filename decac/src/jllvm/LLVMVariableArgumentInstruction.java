package jllvm;

import jllvm.llvm.Core;

public class LLVMVariableArgumentInstruction extends LLVMInstruction {
	public LLVMVariableArgumentInstruction(LLVMInstructionBuilder builder,LLVMValue valist,LLVMType vatype,String name) {
		instance = Core.LLVMBuildVAArg(builder.getInstance(),valist.getInstance(),vatype.getInstance(),name);
	}
}
