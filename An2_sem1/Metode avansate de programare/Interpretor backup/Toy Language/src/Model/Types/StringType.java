package Model.Types;

public class StringType implements IType{

    public StringType(){

    }

    @Override
    public Type getType() {
        return Type.String;
    }

    @Override
    public IType getInner() {
        return null;
    }

    @Override
    public String toString() {
        return "StringType";
    }

    @Override
    public boolean equals(Object obj) {
        return obj instanceof StringType;
    }
}
