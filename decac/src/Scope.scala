package decac

import scala.collection.mutable.Map
import scala.collection.mutable.HashMap
import jllvm.LLVMInstructionBuilder
import jllvm.LLVMArgument
import jllvm.LLVMValue

trait Scopeable {
  def name(): String
  def scope(): Scope[_]
}

trait VariableBinding extends Scopeable {
  def variableType: TauType
}

trait SpecializedVariableBinding extends VariableBinding {
  override def variableType: GammaType
  def compile(builder: LLVMInstructionBuilder): LLVMValue
  def load(builder: LLVMInstructionBuilder): LLVMValue
  def store(builder: LLVMInstructionBuilder,value: LLVMValue): LLVMValue
}

abstract class Scope[T <: Scopeable](p: Option[Scope[_]]) {
  val symbols: Map[String,T] = new HashMap[String,T]()

  def lookup(name: String): Scopeable = symbols.get(name) match {
    case Some(result) => result
    case None => parent match {
      case Some(p) => p.lookup(name)
      case None => throw new UndeclaredIdentifierException(name)
    }
  }
  
  def lookup(name: List[String]): Scopeable = name.tail match {
    case Nil => lookup(name.head)
    case _ => lookup(name.head) match {
      case scope: Scope[_] => scope.lookup(name.tail)
      case _ => throw new Exception("Name of non-scope " + name.head + " used as scope identifier in qualified identifier.")
    }
  }
  
  def typedLookup(name: String): T = {
    lookup(name).asInstanceOf[T]
  }
  
  def typedLookup(name: List[String]): T = name.tail match {
    case Nil => typedLookup(name.head)
    case _ => lookup(name.head) match {
      case scope: Scope[_] => scope.typedLookup(name.tail).asInstanceOf[T]
      case _ => throw new Exception("Name of non-scope or incorrectly-typed scope " + name.head + " used as scope identifier in qualified identifier.")
    }
  }
  
  protected def declare(obj: T) = {
    symbols.put(obj.name,obj)
  }
  
  val parent: Option[Scope[_]] = p
  
  def enclosed(s: Scope[_]): Boolean = parent match {
    case Some(p) => p == s || p.enclosed(s)
    case None => false
  }
  def scopeType: ScopeType
  
  override def toString: String = "Scope { " + symbols.toString + " }"
}

class UndeclaredIdentifierException(name: String) extends Exception("Undeclared identifier exception: " + name)
