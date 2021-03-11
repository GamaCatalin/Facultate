package Model.Types;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Model.Expression.IExpression;

public class Number implements IValue, IExpression {
    int value;

    public Number(int value) {
        this.value = value;
    }

    public int getValue() {
        return this.value;
    }

    @Override
    public IType getType() {
        return new NumberType();
    }

    @Override
    public Number evaluate(IDictionary<String, IValue> dictionary, IHeap<IValue> heap) {
        return this;
    }

    @Override
    public String toString() {
        return String.valueOf(this.getValue());
    }

    @Override
    public IType typeCheck(IDictionary<String, IType> typeEnv) {
        return Type.Number;
    }
}
