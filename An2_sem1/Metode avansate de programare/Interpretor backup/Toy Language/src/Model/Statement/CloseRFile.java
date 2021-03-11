package Model.Statement;

import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.IValue;
import Model.Types.StringType;
import Model.Types.StringVal;
import Model.Types.Type;

import java.io.BufferedReader;
import java.io.IOException;


public class CloseRFile implements IStatement{
    IExpression expression;

    public CloseRFile(IExpression expr){
        this.expression=expr;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws exceptionDifferentOperandTypes, exceptionDivisionByZero, exceptionInvalidOperation, exceptionKeyNotFound, exceptionExpressionNotOfStringType, IOException, exceptionFileNotFound {

        IValue computedValue = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());

        if(!computedValue.getType().equals(new StringType())){
            throw new exceptionExpressionNotOfStringType("Expression is not of string type!");
        }
        else{
            if(programState.getFileTable().exists((StringVal)computedValue)){
                BufferedReader bufferedReader = programState.getFileTable().get((StringVal)computedValue);
                bufferedReader.close();
                programState.getFileTable().remove((StringVal)computedValue);
            }
            else{
                throw new exceptionFileNotFound("File "+((StringVal) computedValue).getValue()+" not found!");
            }
        }


        return programState;
    }


    @Override
    public String toString() {
        return "Close file @ "+this.expression.toString();
    }
}