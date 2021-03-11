package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Model.Expression.IExpression;

public class StringVal implements IValue, IExpression {

    String value;

    public StringVal(String value){
        this.value=value;
    }


    public String getValue(){
        return this.value;
    }

    @Override
    public IType getType() {
        return new StringType();
    }

    @Override
    public IValue evaluate(IDictionary<String, IValue> dictionary, IHeap<IValue> heap){
        return this;
    }

    @Override
    public String toString() {
        return this.value;
    }
}
