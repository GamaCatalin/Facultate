package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.*;
import Model.Expression.IExpression;
import Model.Types.IValue;
import Model.ProgramState;

public class AssignStatement implements IStatement{
    String id;
    IExpression expression;

    public AssignStatement(String id, IExpression expression){
        this.id = id;
        this.expression = expression;
    }


    @Override
    public ProgramState execute(ProgramState programState) throws exceptionVariableNotDeclared, exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation {
        IDictionary<String,IValue> symTable = programState.getSymbolTable();

        if(symTable.exists(this.id)){
            if(symTable.get(id).getType().equals(this.expression.getType())){
                symTable.update(this.id,this.expression.evaluate(programState.getSymbolTable(), programState.getHeap()));
            }
        }
        else{
            throw new exceptionVariableNotDeclared("Variable is not declared");
        }

        return null;
    }

    @Override
    public String toString() {
        return this.id+"="+this.expression;
    }
}
