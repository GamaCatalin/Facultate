package Model.Types;

public class ReferenceType implements IType{

    IType inner;

    public ReferenceType(IType inner){
        this.inner=inner;
    }

    @Override
    public IType getInner(){
        if(this.inner instanceof ReferenceType){
            return this.inner.getInner();
        }
        return this.inner;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof ReferenceType){
            return this.inner.equals(((ReferenceType) obj).getInner());
        }
        else{
            return false;
        }
    }

    @Override
    public Type getType() {
        return Type.Reference;
    }

    @Override
    public String toString() {
        return "Ref("+this.inner.toString()+")";
    }

    public IValue defaultValue(){
        return new Reference(0,this.inner);
    }
}
