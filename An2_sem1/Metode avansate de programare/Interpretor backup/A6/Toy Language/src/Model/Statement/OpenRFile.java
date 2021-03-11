package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.*;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class OpenRFile implements IStatement{
    IExpression expression;

    public OpenRFile(IExpression expr){
        this.expression=expr;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws exceptionKeyNotFound, exceptionKeyAlreadyInDictionary, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionExpressionNotOfStringType, exceptionFileNotFound{

        IValue computedValue = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());

        if(computedValue.getType().equals(new StringType())){
            if(programState.getFileTable().exists((StringVal)computedValue)){
                throw new exceptionKeyAlreadyInDictionary("File already in file table!");
            }
            else{
                String baseLocation = "Toy Language/resources/files/";
                try{
                    BufferedReader fileReader = new BufferedReader(new FileReader( baseLocation +  ((StringVal) computedValue).getValue() ));
                    programState.getFileTable().add((StringVal) computedValue,fileReader);
                }
                catch (FileNotFoundException e) {
                    throw new exceptionFileNotFound("File "+((StringVal) computedValue).getValue()+" not found!");
                }
            }
        }
        else{
            throw new exceptionExpressionNotOfStringType("Expression is not of string type!");
        }



        return null;
    }


    @Override
    public String toString() {
        return "Open file @ " + this.expression.toString();
    }

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes, exceptionKeyAlreadyInDictionary {
        IType typeExpr = this.expression.typeCheck(typeEnv);
        if(typeExpr.equals(Type.String)){
            return typeEnv;
        }
        else{
            throw new exceptionDifferentOperandTypes("Open file: expression not of string value!");
        }
    }
}
