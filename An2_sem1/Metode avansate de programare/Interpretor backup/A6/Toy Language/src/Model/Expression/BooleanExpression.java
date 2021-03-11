package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.*;
import Model.Types.*;
import Model.Types.Boolean;

public class BooleanExpression implements IExpression {
    IExpression left;
    IExpression right;
    String op;

    public BooleanExpression(IExpression left){
        this.left=left;
        this.op="";
        this.right=null;
    }

    public BooleanExpression(IExpression left, String op, IExpression right){
        this.left=left;
        this.op=op;
        this.right=right;
    }

    private boolean checkType(IDictionary<String,IValue> dictionary,IHeap<IValue> heap) throws exceptionDivisionByZero, exceptionInvalidOperation, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        if(this.right==null)
            return true;
        return this.left.evaluate(dictionary,heap).getType().equals(this.right.evaluate(dictionary,heap).getType());
    }


    private IValue evalBoolean(IDictionary<String,IValue> dictionary,IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDifferentOperandTypes, exceptionDivisionByZero, exceptionKeyNotFound {
        Boolean leftEval = (Boolean) this.left.evaluate(dictionary,heap);
        boolean leftValue = leftEval.getValue();
        if(this.right==null){
            return new Boolean(leftValue);
        }

        Boolean rightEval = (Boolean) this.right.evaluate(dictionary,heap);


        boolean rightValue = rightEval.getValue();

        switch (this.op) {
            case "and" -> {
                if (leftValue && rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "or" -> {
                if (leftValue || rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "==" -> {
                if(leftValue==rightValue){
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "!=" -> {
                if(leftValue!=rightValue){
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            default -> throw new exceptionInvalidOperation("Invalid operation!");
        }

    }

    @Override
    public IValue evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        IValue leftEval = this.left.evaluate(dictionary,heap);

        if (!this.checkType(dictionary,heap)) {
            throw new exceptionDifferentOperandTypes("Different operand types!");
        }


        if(leftEval.getType().equals(new BooleanType())){
            return this.evalBoolean(dictionary,heap);
        }
        else{
            throw new exceptionInvalidOperation("Invalid operand types!");
        }
    }

    @Override
    public IType getType() {
        return new BooleanType();
    }

    @Override
    public String toString() {
        if(this.right==null){
            return "("+this.left.toString()+")";
        }

        return "("+this.left.toString()+" "+this.op+" "+this.right.toString()+")";
    }

    @Override
    public IType typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue {
        IType type1,type2;
        type1 = this.left.typeCheck(typeEnv);
        type2 = this.right.typeCheck(typeEnv);

        if(type1.equals(Type.Boolean)){
            if(type2.equals(Type.Boolean)){
                return Type.Boolean;
            }
            else{
                throw new exceptionInvalidValue("Second operand not of boolean type!");
            }
        }
        else {
            throw new exceptionInvalidValue("First operand not of boolean type!");
        }
    }
}
