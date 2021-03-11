package Model.Statement;

import DataStructures.IDictionary;
import DataStructures.IStack;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionInvalidValue;
import Exceptions.exceptionKeyAlreadyInDictionary;
import Model.ProgramState;
import Model.Types.IType;

public class CompoundStatement implements IStatement{
    IStatement leftStatement;
    IStatement rightStatement;

    public CompoundStatement(IStatement leftStatement,IStatement rightStatement){
        this.leftStatement = leftStatement;
        this.rightStatement = rightStatement;
    }

    @Override
    public ProgramState execute(ProgramState programState) {
        IStack<IStatement> stack = programState.getExecutionStack();

        stack.push(this.rightStatement);
        stack.push(this.leftStatement);
        return null;
    }

    @Override
    public String toString() {
        return this.leftStatement.toString()+"|"+this.rightStatement.toString();
    }

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionDifferentOperandTypes, exceptionInvalidValue, exceptionKeyAlreadyInDictionary {
        IDictionary<String,IType> typeEnv1 = this.leftStatement.typeCheck(typeEnv);
        IDictionary<String,IType> typeEnv2 = this.rightStatement.typeCheck(typeEnv1);
        return typeEnv2;
    }
}
