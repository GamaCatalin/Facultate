package Model.Types;

public enum Type implements IType{
    Number,Boolean,String,Reference;

    @Override
    public Type getType() {
        return null;
    }

    @Override
    public IType getInner() {
        return null;
    }
}
