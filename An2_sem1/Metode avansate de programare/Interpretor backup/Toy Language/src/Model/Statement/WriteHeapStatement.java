package Model.Statement;

import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.IValue;
import Model.Types.Reference;

import java.io.IOException;

public class WriteHeapStatement implements IStatement{

    private final String varName;
    private final IExpression expression;

    public WriteHeapStatement(String varName, IExpression expression){
        this.varName=varName;
        this.expression=expression;
    }




    @Override
    public ProgramState execute(ProgramState programState) throws exceptionKeyNotFound, exceptionInvalidValue, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation {

        if(!programState.getSymbolTable().exists(this.varName)){
            throw new exceptionKeyNotFound("Invalid variable name!");
        }

        if(!(programState.getSymbolTable().get(this.varName) instanceof Reference)){
            throw new exceptionInvalidValue("Invalid operator type!");
        }

        Reference varRef = (Reference) programState.getSymbolTable().get(this.varName);

        int heapAddr = varRef.getAddress();

        if(!programState.getHeap().exists(heapAddr)){
            throw new exceptionKeyNotFound("Invalid heap address!");
        }

        IValue variable = programState.getHeap().get(heapAddr);
        IValue exprValue = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());

        if(!variable.getType().equals(exprValue.getType())){
            throw new exceptionDifferentOperandTypes("Invalid type match!");
        }

        programState.getHeap().update(heapAddr,exprValue);

        return programState;
    }
}
