package Model.Statement;

import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.*;
import Model.Types.Number;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements IStatement{

    IExpression expression;
    String varName;

    public ReadFile(IExpression expression,String varName){
        this.expression = expression;
        this.varName = varName;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws exceptionVariableNotDeclared, exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionExpressionNotOfStringType, exceptionFileNotFound{

        IValue computedValue = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());


        if(!programState.getSymbolTable().exists(varName)){

            throw new exceptionVariableNotDeclared("Variable " + varName + " is not declared!");
        }
        if(computedValue.getType().equals(new StringType())){
            if(!programState.getFileTable().exists((StringVal) computedValue)){
                throw new exceptionFileNotFound("File not found!");
            }
            else{
                BufferedReader bufferedReader = programState.getFileTable().get((StringVal) computedValue);
                String readValue;

                try {
                    readValue = bufferedReader.readLine();
                    Number readNumber;
                    if(readValue.equals("")){
                        readNumber = new Number(0);
                    }
                    else{
                        readNumber = new Number(Integer.parseInt(readValue));
                    }
                    programState.getSymbolTable().update(this.varName,readNumber);


                } catch (IOException exception) {
                    System.out.println(exception.getMessage());
                    exception.printStackTrace();
                }
            }
        }
        else{
            throw new exceptionExpressionNotOfStringType("Expression is not of string type!");
        }

        return programState;
    }

    @Override
    public String toString() {
        return "Read file @ "+this.expression.toString() + " on variable " +this.varName;
    }
}
