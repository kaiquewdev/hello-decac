package jllvm;

import jllvm.llvm.Core;

public class LLVMGlobalAlias extends LLVMGlobalValue {
	public LLVMGlobalAlias(LLVMModule parent,LLVMType type,LLVMConstant aliasee,String name) {
		super(Core.LLVMAddAlias(parent != null ? parent.getInstance() : null,type.getInstance(),aliasee.getInstance(),name));
	}
}
