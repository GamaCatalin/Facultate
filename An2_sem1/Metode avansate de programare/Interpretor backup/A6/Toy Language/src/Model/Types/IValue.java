package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionDivisionByZero;
import Exceptions.exceptionInvalidOperation;
import Exceptions.exceptionKeyNotFound;


public interface IValue{
    IType getType();
    String toString();
    IValue evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionKeyNotFound;
}
