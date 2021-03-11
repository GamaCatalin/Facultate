package Model.Types;

public class BooleanType implements IType{

    public BooleanType(){

    }

    @Override
    public Type getType() {
        return Type.Boolean;
    }

    @Override
    public IType getInner() {
        return null;
    }

    @Override
    public String toString() {
        return "BooleanType";
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof BooleanType;
    }
}
