package Model.Statement;

import DataStructures.IStack;
import Model.ProgramState;

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
}
