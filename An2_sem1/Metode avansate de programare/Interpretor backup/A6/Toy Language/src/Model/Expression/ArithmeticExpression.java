package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.*;
import Model.Types.*;
import Model.Types.Number;

public class ArithmeticExpression implements IExpression, IValue{
    IExpression left;
    IExpression right;
    String op;

    public ArithmeticExpression(IExpression left, String op, IExpression right){
        this.left=left;
        this.op=op;
        this.right=right;
    }

    private boolean checkType(IDictionary<String,IValue> dictionary,IHeap<IValue> heap) throws exceptionDivisionByZero, exceptionInvalidOperation, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        return this.left.evaluate(dictionary,heap).getType().equals(this.right.evaluate(dictionary,heap).getType());
    }

    @Override
    public IValue evaluate(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        Number leftEval = (Number) this.left.evaluate(dictionary,heap);
        Number rightEval = (Number) this.right.evaluate(dictionary, heap);



        if (!this.checkType(dictionary,heap)) {
            throw new exceptionDifferentOperandTypes("Different operand types!");
        }

        if(!leftEval.getType().equals(new NumberType())){
            throw new exceptionInvalidOperation("Incompatible type for arithmetic operation!");
        }

        int leftValue = leftEval.getValue();
        int rightValue = rightEval.getValue();

        switch (this.op) {
            case "+" -> {
                return new Number(leftValue + rightValue);
            }
            case "-" -> {
                return new Number(leftValue - rightValue);
            }
            case "*" -> {
                return new Number(leftValue * rightValue);
            }
            case "/" -> {
                if (rightValue == 0)
                    throw new exceptionDivisionByZero("Can't divide by 0!");
                return new Number(leftValue / rightValue);
            }
            case "%" -> {
                if (rightValue == 0)
                    throw new exceptionDivisionByZero("Can't divide by 0!");
                return new Number(leftValue % rightValue);
            }
            default -> throw new exceptionInvalidOperation("Operation must be arithmetical!");
        }

    }

    @Override
    public IType getType() {
        return new NumberType();
    }

    @Override
    public String toString() {
        return "("+this.left.toString()+this.op+this.right.toString()+")";
    }




    @Override
    public IType typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue {
        IType type1,type2;
        type1 = this.left.typeCheck(typeEnv);
        type2 = this.right.typeCheck(typeEnv);

        if(type1.equals(Type.Number)){
            if(type2.equals(Type.Number)){
                return Type.Number;
            }
            else{
                throw new exceptionInvalidValue("Second operand not of number type!");
            }
        }
        else {
            throw new exceptionInvalidValue("First operand not of number type!");
        }
    }

}
