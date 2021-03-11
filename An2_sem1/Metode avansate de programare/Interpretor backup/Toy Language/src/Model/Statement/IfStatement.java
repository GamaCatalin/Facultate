package Model.Statement;

import DataStructures.IDictionary;
import DataStructures.IStack;
import Exceptions.*;
import Model.Types.Boolean;
import Model.Expression.IExpression;
import Model.Types.IValue;
import Model.ProgramState;

public class IfStatement implements IStatement{
    IExpression condition;
    IStatement ifExpression;
    IStatement elseExpression=null;

    public IfStatement(IExpression condition,IStatement ifExpression){
        this.condition=condition;
        this.ifExpression=ifExpression;
    }

    public IfStatement(IExpression condition,IStatement ifExpression,IStatement elseExpression){
        this.condition=condition;
        this.ifExpression=ifExpression;
        this.elseExpression=elseExpression;
    }

    @Override
    public ProgramState execute(ProgramState programState) throws  exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation {
        IDictionary<String, IValue> symTable = programState.getSymbolTable();
        IStack<IStatement> executionStack = programState.getExecutionStack();

        Boolean result = (Boolean) this.condition.evaluate(symTable, programState.getHeap());

        if(result.getValue()){
            executionStack.push(ifExpression);
        }
        else{
            executionStack.push(elseExpression);
        }

        return programState;
    }

    @Override
    public String toString() {
        if(this.elseExpression == null){
            return "if ( " + this.condition.toString()+" )    then ( "+this.ifExpression.toString()+" )";
        }
        else{
            return "if ( " + this.condition.toString()+" )    then ( "+this.ifExpression.toString()+" )    else ( "+this.elseExpression.toString()+ " )";
        }
    }
}
