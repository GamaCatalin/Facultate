package Controller;

import DataStructures.IStack;
import Exceptions.*;
import Model.ProgramState;
import Model.Statement.IStatement;
import Repository.IRepository;

import java.io.IOException;


public class Controller {
    private final IRepository repository;

    public Controller(IRepository repository){
        this.repository = repository;
    }

    public ProgramState oneStep() throws exceptionKeyNotFound, exceptionVariableNotDeclared, exceptionStackIsEmpty, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionDivisionByZero, exceptionKeyAlreadyInDictionary, exceptionFileNotFound, IOException, exceptionExpressionNotOfStringType, exceptionInvalidValue {
        ProgramState prgState = this.repository.getCurrentProgramState();

        IStack<IStatement> executionStack = prgState.getExecutionStack();

        IStatement currentStatement = executionStack.pop();
        currentStatement.execute(prgState);

        return prgState;
    }

    public void runAll() throws exceptionVariableNotDeclared, exceptionKeyAlreadyInDictionary, exceptionStackIsEmpty, exceptionInvalidOperation, exceptionDivisionByZero, exceptionKeyNotFound, exceptionDifferentOperandTypes, IOException, exceptionExpressionNotOfStringType, exceptionFileNotFound, exceptionInvalidValue {
        ProgramState prgState = this.repository.getCurrentProgramState();
        this.repository.logProgramState(prgState);
        while(!prgState.getExecutionStack().isEmpty()){
            prgState= this.oneStep();
            //prgState.printCurrentState();
            this.repository.logProgramState(prgState);
        }
    }

    public void logProgramState() throws IOException {
        this.repository.logProgramState(this.repository.getCurrentProgramState());
    }

    public void setRepoLogFilePath(String path){
        this.repository.setLogFilePath(path);
    }
}
