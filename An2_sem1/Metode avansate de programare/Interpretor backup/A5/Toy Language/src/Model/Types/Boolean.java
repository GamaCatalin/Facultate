package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Model.Expression.IExpression;

public class Boolean implements IValue, IExpression {
    boolean value;

    public Boolean(boolean value){
        this.value=value;
    }

    public boolean getValue(){
        return this.value;
    }

    @Override
    public IType getType() {
        return new BooleanType();
    }

    @Override
    public Boolean evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) {
        return this;
    }

    @Override
    public String toString() {
        return String.valueOf(this.getValue());
    }

    @Override
    public boolean equals(Object obj) {
        return super.equals(obj);
    }
}
