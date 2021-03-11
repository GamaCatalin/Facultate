package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.*;
import Model.Types.IType;
import Model.Types.IValue;

public interface IExpression {
    IValue evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionKeyNotFound;
    IType getType();
    String toString();
    IType typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue;
}
