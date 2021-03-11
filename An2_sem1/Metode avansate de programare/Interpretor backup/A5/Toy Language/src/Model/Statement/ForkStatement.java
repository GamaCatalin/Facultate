package Model.Statement;

import DataStructures.*;
import Exceptions.*;
import Model.ProgramState;
import Model.Types.IValue;
import Model.Types.StringVal;
import Utils.ForkIDGenerator;


import java.io.BufferedReader;
import java.io.IOException;

public class ForkStatement implements IStatement{

    private final IStatement statement;

    public ForkStatement(IStatement statement){
        this.statement=statement;
    }


    @Override
    public ProgramState execute(ProgramState programState) throws exceptionVariableNotDeclared, exceptionKeyNotFound, exceptionKeyAlreadyInDictionary, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionExpressionNotOfStringType, exceptionFileNotFound, IOException, exceptionInvalidValue {
        IStack<IStatement> newExeStack = new MyStack<>();
        newExeStack.push(this.statement);
        IDictionary<String, IValue> newSymTable = programState.getSymbolTable().copy();
        IList<IValue> newOutList = programState.getOutputList();
        IDictionary<StringVal, BufferedReader> newFileTable = programState.getFileTable();
        IHeap<IValue> newHeap = programState.getHeap();

        int id = ForkIDGenerator.generateId();

        ProgramState newProgState = new ProgramState(newExeStack,newSymTable,newOutList,newFileTable,newHeap);
        newProgState.setId(id);
        return newProgState;
    }

    @Override
    public String toString() {
        return super.toString();
    }
}
