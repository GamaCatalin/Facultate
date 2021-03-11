package Model.Statement;

import DataStructures.IDictionary;
import DataStructures.IStack;
import Exceptions.*;
import Model.Types.Boolean;
import Model.Expression.IExpression;
import Model.Types.IType;
import Model.Types.IValue;
import Model.ProgramState;
import Model.Types.Type;

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

        return null;
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

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes, exceptionKeyAlreadyInDictionary {
        IType typeExpr = this.condition.typeCheck(typeEnv);
        if(typeExpr.equals(Type.Boolean)){
            this.ifExpression.typeCheck(typeEnv.copy());
            this.ifExpression.typeCheck(typeEnv.copy());
            return typeEnv;
        }
        else{
            throw new exceptionInvalidValue("Condition in IF not of boolean type!");
        }
    }
}
