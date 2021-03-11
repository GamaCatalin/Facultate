package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionDivisionByZero;
import Exceptions.exceptionInvalidOperation;
import Exceptions.exceptionKeyNotFound;
import Model.Expression.IExpression;

public class Reference implements IValue, IExpression {
    int address;
    IType location;

    public Reference(int address,IType location){
       this.address=address;
       this.location=location;
    }

    @Override
    public IType getType() {
        return location;
    }

    public int getAddress(){
        return this.address;
    }

    @Override
    public IValue evaluate(IDictionary<String, IValue> dictionary, IHeap<IValue> heap) throws exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation {
        if(this.location==Type.Reference){
            heap.get(this.address).evaluate(dictionary,heap);
        }
        return heap.get(this.address);
    }

    @Override
    public String toString() {
        return "*->"+this.location.toString()+"@"+this.address;
    }
}
