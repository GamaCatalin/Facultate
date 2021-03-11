package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.*;
import Model.Expression.IExpression;
import Model.Types.IType;
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

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes {
        try {
            IType typeVar = typeEnv.get(this.id);
            IType typeExpr = this.expression.typeCheck(typeEnv);

            if(typeVar.equals(typeExpr)){
                return typeEnv;
            }
            else{
                throw new exceptionDifferentOperandTypes("Assignment: different types for the operands!");
            }
        } catch (Exceptions.exceptionKeyNotFound exceptionKeyNotFound) {
            System.out.println(exceptionKeyNotFound.getMessage());
        }
        return null;
    }
}
