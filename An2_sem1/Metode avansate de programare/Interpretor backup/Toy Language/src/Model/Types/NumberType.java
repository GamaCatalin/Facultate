package Model.Types;

public class NumberType implements IType{

    public NumberType(){
    }

    @Override
    public Type getType() {
        return Type.Number;
    }

    @Override
    public IType getInner() {
        return null;
    }

    @Override
    public String toString() {
        return "NumberType";
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof NumberType;
    }
}
