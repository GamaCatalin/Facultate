package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionDivisionByZero;
import Exceptions.exceptionInvalidOperation;
import Exceptions.exceptionKeyNotFound;
import Model.Types.*;
import Model.Types.Boolean;
import Model.Types.Number;

public class RelationalExpression implements IExpression{
    IExpression left;
    IExpression right;
    String op;

    public RelationalExpression(IExpression left, String op, IExpression right){
        this.left=left;
        this.op=op;
        this.right=right;
    }

    private boolean checkType(IDictionary<String,IValue> dictionary,IHeap<IValue> heap) throws exceptionDivisionByZero, exceptionInvalidOperation, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        return this.left.evaluate(dictionary,heap).getType().equals(this.right.evaluate(dictionary,heap).getType());
    }

    private IValue evalNumbers(IDictionary<String,IValue> dictionary, IHeap<IValue> heap) throws exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionKeyNotFound {
        Number leftEval = (Number) this.left.evaluate(dictionary,heap);
        Number rightEval = (Number) this.right.evaluate(dictionary,heap);

        int leftValue = leftEval.getValue();
        int rightValue = rightEval.getValue();

        switch (this.op) {
            case "==" -> {
                if (leftValue == rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "!=" -> {
                if (leftValue != rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "<" -> {
                if (leftValue < rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case "<=" -> {
                if (leftValue <= rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case ">" -> {
                if (leftValue > rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            case ">=" -> {
                if (leftValue >= rightValue) {
                    return new Boolean(true);
                }
                return new Boolean(false);
            }
            default -> throw new exceptionInvalidOperation("Invalid operation!");
        }


    }



    @Override
    public IValue evaluate(IDictionary<String,IValue> dictionary,IHeap<IValue> heap) throws exceptionInvalidOperation, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionKeyNotFound {
        IValue leftEval = this.left.evaluate(dictionary,heap);

        if (!this.checkType(dictionary,heap)) {
            throw new exceptionDifferentOperandTypes("Different operand types!");
        }

        if(leftEval.getType().equals(new NumberType())){
            return this.evalNumbers(dictionary,heap);
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
}
