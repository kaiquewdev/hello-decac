package jllvm;

import jllvm.llvm.ExecutionEngine;
import jllvm.llvm.SWIGTYPE_p_LLVMOpaqueValue;
import jllvm.llvm.SWIGTYPE_p_LLVMOpaqueExecutionEngine;
import jllvm.llvm.SWIGTYPE_p_p_LLVMOpaqueExecutionEngine;
import jllvm.llvm.SWIGTYPE_p_p_char;

public class LLVMJitCompiler extends LLVMExecutionEngine {
	public LLVMJitCompiler(LLVMModule mod) throws Exception {
		super(null);
		SWIGTYPE_p_p_LLVMOpaqueExecutionEngine engines = ExecutionEngine.new_LLVMExecutionEngineRefArray(1);
		SWIGTYPE_p_p_char outerrs = ExecutionEngine.new_StringArray(1);
		int success = ExecutionEngine.LLVMCreateJITCompilerForModule(engines,mod.getInstance(),0,outerrs);
		String outerr = ExecutionEngine.StringArray_getitem(outerrs,0);
		ExecutionEngine.delete_StringArray(outerrs); outerrs = null;
		instance = ExecutionEngine.LLVMExecutionEngineRefArray_getitem(engines,0);
		ExecutionEngine.delete_LLVMExecutionEngineRefArray(engines); engines = null;
		if(success == 0)
			throw new Exception(outerr);
	}
}
