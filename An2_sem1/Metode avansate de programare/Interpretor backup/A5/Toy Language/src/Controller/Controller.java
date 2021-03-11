package Controller;

import Exceptions.*;
import Model.ProgramState;
import Model.Types.IValue;
import Repository.IRepository;

import java.io.IOException;
import java.util.*;
import java.util.concurrent.*;
import java.util.stream.Collector;
import java.util.stream.Collectors;


public class Controller {
    private final IRepository repository;
    ExecutorService executor;

    public Controller(IRepository repository){
        this.repository = repository;
    }


    /*
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
     */


    public void oneStepForAll(List<ProgramState> programStatesList){

        programStatesList.forEach(programState -> {
            try {
                this.repository.logProgramState(programState);
            } catch (IOException exception) {
                System.out.println(exception.getMessage());
            }
        });

        List<Callable<ProgramState>> callableList = programStatesList.stream()
                                                                     .map((ProgramState p)->(Callable<ProgramState>)(()->{return p.oneStep();}))
                                                                     .collect(Collectors.toList());


        List<ProgramState> newProgramStatesList = null;
        try {
            newProgramStatesList = this.executor.invokeAll(callableList).stream()
                                                                                      .map(future ->
                                                                                      {
                                                                                          try {
                                                                                              return future.get();
                                                                                          }
                                                                                          catch (InterruptedException | ExecutionException e ) {
                                                                                              System.out.println(e.getMessage());
                                                                                          }
                                                                                          return null;
                                                                                      })
                                                                                      .filter(p->p!=null)
                                                                                      .collect(Collectors.toList());
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }

        programStatesList.addAll(newProgramStatesList);
        programStatesList.forEach(programState-> {
            try {
                this.repository.logProgramState(programState);
            } catch (IOException exception) {
                System.out.println(exception.getMessage());
            }
        });

        this.repository.setProgramStates(programStatesList);
    }




    public void runAll(){
        this.executor = Executors.newFixedThreadPool(2);
        List<ProgramState> programStateList = this.removeCompletedPrograms(this.repository.getAllProgramStates());
        while(programStateList.size()>0){
            this.oneStepForAll(programStateList);
            programStateList=this.removeCompletedPrograms(this.repository.getAllProgramStates());
        }
        this.executor.shutdownNow();
        this.repository.setProgramStates(programStateList);
    }



/*
    private HashMap<Integer,IValue> conservativeGarbageCollector(List<IValue> symbolTable, Map<Integer, IValue> heap){
        HashMap<Integer, IValue> map = new HashMap<>();
        for (Map.Entry<Integer, IValue> e : heap.entrySet()) {
            if (symbolTable.contains(e.getKey())) {
                if (map.put(e.getKey(), e.getValue())!=null)
                {
                    throw new IllegalStateException("Duplicate key");
                }
            }
        }
        return map;
    }


 */

    public List<ProgramState> removeCompletedPrograms(List<ProgramState> inputProgramStates){
        return inputProgramStates.stream()
                .filter(ProgramState::isNotCompleted)
                .collect(Collectors.toList());
    }




    public void setRepoLogFilePath(String path){
        this.repository.setLogFilePath(path);
    }
}
