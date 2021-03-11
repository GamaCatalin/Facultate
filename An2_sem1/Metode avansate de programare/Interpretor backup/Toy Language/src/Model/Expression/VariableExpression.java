package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionKeyNotFound;
import Model.Types.IValue;
import Model.Types.Type;

public class VariableExpression implements IExpression, IValue{

    private final String id;

    public VariableExpression(String id){
        this.id = id;
    }


    @Override
    public IValue evaluate(IDictionary<String, IValue> dictionary, IHeap<IValue> heap) throws exceptionKeyNotFound {
        return dictionary.get(this.id);
    }

    @Override
    public Type getType() {
        return null;
    }

    @Override
    public String toString() {
        return this.id;
    }

}
