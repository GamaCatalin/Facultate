package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionInvalidValue;
import Model.Expression.IExpression;

public class Unknown implements IValue, IExpression {

    private final IType type;

    public Unknown(IType type){
        this.type = type;
        //System.out.println("################# "+ this.type.toString());
    }

    @Override
    public IType getType() {
        return this.type;
    }

    @Override
    public Unknown evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) {
        return this;
    }

    @Override
    public String toString() {
        return "Unknown @" + type.toString();
    }

    @Override
    public IType typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue {
        return this.type;
    }

}
