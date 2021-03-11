package View;

import Controller.Controller;
import DataStructures.*;
import Exceptions.*;
import Model.Expression.ArithmeticExpression;
import Model.Expression.BooleanExpression;
import Model.Expression.VariableExpression;
import Model.ProgramState;
import Model.Statement.*;
import Model.Types.*;
import Model.Types.Boolean;
import Model.Types.Number;
import Repository.RepositoryMemory;
import Utils.Utils;


import java.io.BufferedReader;
import java.io.IOException;
import java.util.Scanner;

public class UI {

    public boolean isRunning;

    public UI(){
        this.isRunning=true;
    }

    public IStatement init1(){
        return new CompoundStatement(new VariableDeclarationStatement("v", Type.Number),
                new CompoundStatement(new AssignStatement("v", new Number(2)),
                        new PrintStatement(new VariableExpression("v"))));
    }

    public IStatement init2(){

        /*
        return new CompoundStatement(new VariableDeclarationStatement("a", Type.Number),
                new CompoundStatement(new VariableDeclarationStatement("b", Type.Number),
                        new CompoundStatement(new AssignStatement("a",
                                new ArithmeticExpression(new Number(2), "+",
                                        new ArithmeticExpression(new Number(3),"*", new Number(5)))),
                                new CompoundStatement(new AssignStatement("b",new ArithmeticExpression(new VariableExpression("a"),"+",new Number(1))),
                                        new PrintStatement(new VariableExpression("b"))))));
*/
        return Utils.mergeStatements(
                new VariableDeclarationStatement("a", Type.Number),
                new VariableDeclarationStatement("b", Type.Number),
                new AssignStatement("a",
                        new ArithmeticExpression(new Number(2), "+",
                                new ArithmeticExpression(new Number(3),"*", new Number(5)))),
                new AssignStatement("b",
                        new ArithmeticExpression(
                                new VariableExpression("a"),"+",new Number(1))),
                new PrintStatement(new VariableExpression("b"))
                );
    }

    public IStatement init3(){
        return new CompoundStatement(new VariableDeclarationStatement("a", Type.Boolean),
                new CompoundStatement(new VariableDeclarationStatement("v",Type.Number),
                        new CompoundStatement(new AssignStatement("a",new Boolean(true)),
                                new CompoundStatement(new IfStatement(new BooleanExpression(new VariableExpression("a")),new AssignStatement("v",new Number(2)),new AssignStatement("v",new Number(3))),
                                        new PrintStatement(new VariableExpression("v"))))));
    }


    public IStatement testFile(){
        return Utils.mergeStatements(
          new VariableDeclarationStatement("varf",Type.String),
          new AssignStatement("varf",new StringVal("test.in")),
          new OpenRFile(new VariableExpression("varf")),
          new VariableDeclarationStatement("varc",Type.Number),
          new ReadFile(
                  new VariableExpression("varf"),
                  "varc"
          ),
          new PrintStatement(new VariableExpression("varc")),
          new ReadFile(
                  new VariableExpression("varf"),
                "varc"
          ),
          new PrintStatement(new VariableExpression("varc")),
          new CloseRFile(new VariableExpression("varf"))
        );
    }




    public void printMenu(){
        System.out.println("                Menu");
        System.out.println("1. int v; v=2;Print(v)");
        System.out.println("2. int a;int b; a=2+3*5;b=a+1;Print(b)");
        System.out.println("3. bool a; int v; a=true;(If a Then v=2 Else v=3);Print(v)");
        System.out.println("4. string varf; varf=\"test.in\"; openRFile(varf); int varc; readFile(varf,varc); print(varc); readFile(varf,varc); print(varc); closeRFile(varf)");
        System.out.println();
        System.out.println("0. Exit");
    }

    public String listenCommand(){
        Scanner input = new Scanner(System.in);
        return  input.nextLine();
    }

    public void stop(){
        this.isRunning=false;
    }


    public void run() throws exceptionKeyNotFound, exceptionVariableNotDeclared, exceptionStackIsEmpty, exceptionInvalidOperation, exceptionDivisionByZero, exceptionKeyAlreadyInDictionary, exceptionDifferentOperandTypes, IOException, exceptionExpressionNotOfStringType, exceptionFileNotFound, exceptionInvalidValue {
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        RepositoryMemory repo;
        Controller cont;


        while (this.isRunning){
            this.printMenu();

            String command = this.listenCommand();


            if ("0".equals(command)) {
                this.stop();
            } else if ("1".equals(command)) {
                dict = new MyDictionary<>();
                stack = new MyStack<>();
                list = new MyList<>();
                repo = new RepositoryMemory();
                stack.push(this.init1());
                repo.addProgramState(new ProgramState(stack, dict, list));
                cont = new Controller(repo);
                cont.setRepoLogFilePath("testLog1.txt");
                cont.runAll();
            } else if ("2".equals(command)) {
                dict = new MyDictionary<>();
                stack = new MyStack<>();
                list = new MyList<>();
                repo = new RepositoryMemory();
                stack.push(this.init2());
                repo.addProgramState(new ProgramState(stack, dict, list));
                cont = new Controller(repo);
                cont.setRepoLogFilePath("testLog2.txt");
                cont.runAll();

            } else if ("3".equals(command)) {
                dict = new MyDictionary<>();
                stack = new MyStack<>();
                list = new MyList<>();
                repo = new RepositoryMemory();
                stack.push(this.init3());
                repo.addProgramState(new ProgramState(stack, dict, list));
                cont = new Controller(repo);
                cont.setRepoLogFilePath("testLog3.txt");
                cont.runAll();
            } else if ("4".equals(command)){
                dict = new MyDictionary<>();
                stack = new MyStack<>();
                list = new MyList<>();
                table = new MyDictionary<>();
                repo = new RepositoryMemory();
                stack.push(this.testFile());
                repo.addProgramState(new ProgramState(stack, dict, list,table));
                cont = new Controller(repo);
                cont.setRepoLogFilePath("testLog4.txt");
                cont.runAll();
            }

            else {
                System.out.println("Unknown command!");
            }


        }

    }


}
