package Model.Statement;

import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.IValue;
import Model.Types.Reference;
import Model.Types.Type;


public class NewStatement implements IStatement{

    private final String varName;
    private final IExpression expression;

    public NewStatement(String varName, IExpression expression){
        this.varName=varName;
        this.expression=expression;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation{
        if(!programState.getSymbolTable().exists(varName)){
            throw new exceptionKeyNotFound("Variable not declared!");
        }

        if(!programState.getSymbolTable().get(varName).getType().getType().equals(Type.Reference)){
            throw new exceptionInvalidOperation("Value not of type reference!");
        }


        IValue evaluatedExpr = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());
        IValue currentSymbol = programState.getSymbolTable().get(this.varName);



        if(!evaluatedExpr.getType().equals(currentSymbol.getType().getInner())){
            throw new exceptionDifferentOperandTypes("Types don't match!");
        }


        int addedKey;

        addedKey = programState.getHeap().add(this.expression.evaluate(programState.getSymbolTable(), programState.getHeap()));


        programState.getSymbolTable().update(this.varName,new Reference(addedKey,evaluatedExpr.getType()));


        return null;
    }

    @Override
    public String toString() {
        return "New @(" + this.varName+","+expression.toString()+")";
    }
}
