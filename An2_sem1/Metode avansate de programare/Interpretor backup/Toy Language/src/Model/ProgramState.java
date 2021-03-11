package Model;
import DataStructures.*;
import Model.Types.IValue;
import Model.Statement.IStatement;
import Model.Types.StringVal;

import java.io.BufferedReader;

public class ProgramState {
    private IStack<IStatement> executionStack;
    private IDictionary<String, IValue> symbolTable;
    private IList<IValue> outputList;
    private IDictionary<StringVal, BufferedReader> fileTable;
    private IHeap<IValue> heap;

    public ProgramState(IStack<IStatement> stack, IDictionary<String, IValue> dictionary, IList<IValue> list){
        this.executionStack = stack;
        this.symbolTable = dictionary;
        this.outputList = list;
        this.fileTable = new MyTable<>();
        this.heap = new MyHeap<>();
    }

    public ProgramState(IStack<IStatement> stack, IDictionary<String, IValue> dictionary, IList<IValue> list,IDictionary<StringVal,BufferedReader> table){
        this.executionStack = stack;
        this.symbolTable = dictionary;
        this.outputList = list;
        this.fileTable = table;
        this.heap = new MyHeap<>();
    }

    public ProgramState(IStack<IStatement> stack, IDictionary<String, IValue> dictionary, IList<IValue> list, IDictionary<StringVal,BufferedReader> table, IHeap<IValue> heap){
        this.executionStack = stack;
        this.symbolTable = dictionary;
        this.outputList = list;
        this.fileTable = table;
        this.heap = heap;
    }

    public ProgramState(IStack<IStatement> stack, IDictionary<String, IValue> dictionary, IList<IValue> list, IHeap<IValue> heap){
        this.executionStack = stack;
        this.symbolTable = dictionary;
        this.outputList = list;
        this.fileTable = new MyTable<>();
        this.heap = heap;
    }

    public ProgramState(){
        this.executionStack = new MyStack<>();
        this.symbolTable = new MyDictionary<>();
        this.outputList = new MyList<>();
        this.fileTable = new MyTable<>();
        this.heap = new MyHeap<>();
    }

    public IStack<IStatement> getExecutionStack() {
        return executionStack;
    }

    public IDictionary<String, IValue> getSymbolTable() {
        return symbolTable;
    }

    public IList<IValue> getOutputList() {
        return outputList;
    }

    public IDictionary<StringVal,BufferedReader> getFileTable(){return fileTable;}

    public IHeap<IValue> getHeap() {return heap;}

    public void setExecutionStack(IStack<IStatement> stack){
        this.executionStack = stack;
    }

    public void setSymbolTable(IDictionary<String,IValue> dictionary){
        this.symbolTable = dictionary;
    }

    public void setOutputList(IList<IValue> list){
        this.outputList = list;
    }

    public void setFileTable(IDictionary<StringVal, BufferedReader> fileTable) {this.fileTable = fileTable; }

    public void setHeap(IHeap<IValue> heap){this.heap=heap;};

    public void printCurrentState(){
        System.out.println(this.toString());
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        builder.append("-------------------------------------------------------------------------------\n");
        builder.append("Execution Stack\n");
        builder.append(this.executionStack.toString());
        builder.append("\n\n");

        builder.append("Symbol table\n");
        builder.append(this.symbolTable.toString());
        builder.append("\n\n");

        builder.append("Output list\n");
        builder.append(this.outputList.toString());
        builder.append("\n\n");


        builder.append("File table\n");
        builder.append(this.fileTable.toString());
        builder.append("\n\n");

        builder.append("Heap\n");
        builder.append(this.heap.toString());
        builder.append("\n\n");


        return builder.toString();
    }


}
