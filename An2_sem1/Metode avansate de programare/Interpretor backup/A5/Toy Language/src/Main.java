import Controller.Controller;
import DataStructures.*;
import Model.Expression.*;
import Model.ProgramState;
import Model.Statement.*;
import Model.Types.*;
import Model.Types.Boolean;
import Model.Types.Number;
import Repository.RepositoryMemory;
import Utils.Utils;
import View.ExitCommand;
import View.RunExample;
import View.TextMenu;

import java.io.BufferedReader;

public class Main {


    private static IStatement init1(){
        return new CompoundStatement(new VariableDeclarationStatement("v", new NumberType()),
                new CompoundStatement(new AssignStatement("v", new Number(2)),
                        new PrintStatement(new VariableExpression("v"))));
    }

    private static Controller ex1(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        repo = new RepositoryMemory();
        stack.push(init1());
        repo.addProgramState(new ProgramState(stack, dict, list));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog1.txt");
        return cont;
    }

    private static IStatement init2(){

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
                new VariableDeclarationStatement("a", new NumberType()),
                new VariableDeclarationStatement("b", new NumberType()),
                new AssignStatement("a",
                        new ArithmeticExpression(new Number(2), "+",
                                new ArithmeticExpression(new Number(3),"*", new Number(5)))),
                new AssignStatement("b",
                        new ArithmeticExpression(
                                new VariableExpression("a"),"+",new Number(1))),
                new PrintStatement(new VariableExpression("b"))
        );
    }

    private static Controller ex2(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        repo = new RepositoryMemory();
        stack.push(init2());
        repo.addProgramState(new ProgramState(stack, dict, list));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog2.txt");
        return cont;
    }




    private static IStatement init3(){
        return new CompoundStatement(new VariableDeclarationStatement("a", new BooleanType()),
                new CompoundStatement(new VariableDeclarationStatement("v",new NumberType()),
                        new CompoundStatement(new AssignStatement("a",new Boolean(true)),
                                new CompoundStatement(new IfStatement(new BooleanExpression(new VariableExpression("a")),new AssignStatement("v",new Number(2)),new AssignStatement("v",new Number(3))),
                                        new PrintStatement(new VariableExpression("v"))))));
    }

    private static Controller ex3(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        repo = new RepositoryMemory();
        stack.push(init3());
        repo.addProgramState(new ProgramState(stack, dict, list));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog3.txt");
        return cont;
    }


    private static IStatement init4(){
        return Utils.mergeStatements(
                new VariableDeclarationStatement("varf",new StringType()),
                new AssignStatement("varf",new StringVal("test.in")),
                new OpenRFile(new VariableExpression("varf")),
                new VariableDeclarationStatement("varc",new NumberType()),
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


    private static Controller ex4(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        repo = new RepositoryMemory();
        stack.push(init4());
        repo.addProgramState(new ProgramState(stack, dict, list,table));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog4.txt");
        return cont;
    }


    private static IStatement init5(){
        //Ref int v;new(v,20);Ref Ref int a; new(a,v);print(v);print(a)

        return Utils.mergeStatements(
                new VariableDeclarationStatement(
                        "v",
                        new ReferenceType(new NumberType())),
                new NewStatement(
                        "v",
                        new Number(20)),
                new VariableDeclarationStatement(
                        "a",
                        new ReferenceType(
                                new ReferenceType(
                                        new NumberType()
                                )
                        )
                ),
                new NewStatement(
                        "a",
                        new VariableExpression("v")
                ),
                new PrintStatement(new VariableExpression("v")),
                new PrintStatement(new VariableExpression("a"))
        );
    }

    private static Controller ex5(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        IHeap<IValue> heap;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        heap = new MyHeap<>();
        repo = new RepositoryMemory();
        stack.push(init5());
        repo.addProgramState(new ProgramState(stack, dict, list,table,heap));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog5.txt");
        return cont;
    }

    private static IStatement init6(){
        //Ref int v;new(v,20);Ref Ref int a; new(a,v);print(rH(v));print(rH(rH(a))+5)

        return Utils.mergeStatements(
                new VariableDeclarationStatement(
                        "v",
                        new ReferenceType(new NumberType())),
                new NewStatement(
                        "v",
                        new Number(20)),
                new VariableDeclarationStatement(
                        "a",
                        new ReferenceType(
                                new ReferenceType(
                                        new NumberType()
                                )
                        )
                ),
                new NewStatement(
                        "a",
                        new VariableExpression("v")
                ),
                new PrintStatement(
                        new ReadHeapExpression(
                                new StringVal("v")
                                )
                ),
                new PrintStatement(
                        new ArithmeticExpression(
                                new ReadHeapExpression(
                                        new ReadHeapExpression(
                                                new StringVal("a")
                                        )
                                ),
                                "+",
                                new Number(5)
                        )
                        )
        );
    }

    private static Controller ex6(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        IHeap<IValue> heap;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        heap = new MyHeap<>();
        repo = new RepositoryMemory();
        stack.push(init6());
        repo.addProgramState(new ProgramState(stack, dict, list,table,heap));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog6.txt");
        return cont;
    }


    private static IStatement init7(){
        //Ref int v;new(v,20);print(rH(v)); wH(v,30);print(rH(v)+5);

        return Utils.mergeStatements(
                new VariableDeclarationStatement(
                        "v",
                        new ReferenceType(new NumberType())),
                new NewStatement(
                        "v",
                        new Number(20)),

                new PrintStatement(
                        new ReadHeapExpression(
                                new StringVal("v")
                        )
                ),
                new WriteHeapStatement(
                        "v",
                        new Number(30)
                        ),
                new PrintStatement(
                        new ArithmeticExpression(
                                new ReadHeapExpression(
                                        new StringVal("v")
                                ),
                                "+",
                                new Number(5)
                        )

                )
        );
    }

    private static Controller ex7(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        IHeap<IValue> heap;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        heap = new MyHeap<>();
        repo = new RepositoryMemory();
        stack.push(init7());
        repo.addProgramState(new ProgramState(stack, dict, list,table,heap));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog7.txt");
        return cont;
    }


    private static IStatement init8(){
        //int v; v=4; (while (v>0) print(v);v=v-1);print(v)


        return Utils.mergeStatements(
            new VariableDeclarationStatement("v",new NumberType()),
            new AssignStatement("v",new Number(4)),
            new WhileStatement(
                    new RelationalExpression(
                            new VariableExpression("v"),
                            ">",
                            new Number(0)
                    ),
                    new CompoundStatement(
                            new PrintStatement(
                                    new VariableExpression("v")
                            ),
                            new AssignStatement(
                                    "v",
                                        new ArithmeticExpression(
                                                new VariableExpression("v"),
                                                "-",
                                                new Number(1)
                                        )


                            )

                    )
            ),
            new PrintStatement(new VariableExpression("v"))
        );
    }


    private static Controller ex8(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        IHeap<IValue> heap;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        heap = new MyHeap<>();
        repo = new RepositoryMemory();
        stack.push(init8());
        repo.addProgramState(new ProgramState(stack, dict, list,table,heap));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog8.txt");
        return cont;
    }

    private static IStatement init9(){
        //int v; Ref int a; v=10;new(a,22);
        //fork(wH(a,30);v=32;print(v);print(rH(a)));
        //print(v);print(rH(a))


        return Utils.mergeStatements(
                new VariableDeclarationStatement("v",new NumberType()),
                new VariableDeclarationStatement("a", new ReferenceType(
                                                            new NumberType()
                                                                        )),
                new AssignStatement("v",new Number(10)),
                new NewStatement("a",new Number(22)),
                new ForkStatement(
                        Utils.mergeStatements(
                            new WriteHeapStatement("a",new Number(30)),
                            new AssignStatement("v",new Number(32)),
                            new PrintStatement(
                                    new VariableExpression("v")
                            ),
                            new PrintStatement(
                                    new ReadHeapExpression(
                                            new VariableExpression("a")
                                    ))
                        )),
                new PrintStatement(
                        new VariableExpression("v")
                ),
                new PrintStatement(
                        new ReadHeapExpression(
                                new VariableExpression("a")
                        )
                )
        );
    }


    private static Controller ex9(){
        IDictionary<String, IValue> dict;
        IStack<IStatement> stack;
        IList<IValue> list;
        IDictionary<StringVal, BufferedReader> table;
        IHeap<IValue> heap;
        RepositoryMemory repo;
        Controller cont;

        dict = new MyDictionary<>();
        stack = new MyStack<>();
        list = new MyList<>();
        table = new MyDictionary<>();
        heap = new MyHeap<>();
        repo = new RepositoryMemory();
        stack.push(init9());
        repo.addProgramState(new ProgramState(stack, dict, list,table,heap));
        cont = new Controller(repo);
        cont.setRepoLogFilePath("testLog9.txt");
        return cont;
    }


    public static void main(String[] args) {

        /*

        UI ui = new UI();

        try {
            ui.run();
        }  catch (exceptionVariableNotDeclared | exceptionStackIsEmpty | exceptionInvalidOperation | exceptionDivisionByZero | exceptionKeyAlreadyInDictionary | exceptionDifferentOperandTypes | exceptionKeyNotFound | IOException | exceptionExpressionNotOfStringType | exceptionFileNotFound exception) {
            //System.out.println(exception.getMessage());
            exception.printStackTrace();
        }

        */


        IStatement stm1 = init1();
        Controller cont1 = ex1();


        IStatement stm2 = init2();
        Controller cont2 = ex2();

        IStatement stm3 = init3();
        Controller cont3 = ex3();

        IStatement stm4 = init4();
        Controller cont4 = ex4();

        IStatement stm5 = init5();
        Controller cont5 = ex5();

        IStatement stm6 = init6();
        Controller cont6 = ex6();

        IStatement stm7 = init7();
        Controller cont7 = ex7();

        IStatement stm8 = init8();
        Controller cont8 = ex8();

        IStatement stm9 = init9();
        Controller cont9 = ex9();


        TextMenu menu = new TextMenu();

        menu.addCommand(new ExitCommand("0","Exit."));
        menu.addCommand(new RunExample("1", stm1.toString(),cont1));
        menu.addCommand(new RunExample("2", stm2.toString(),cont2));
        menu.addCommand(new RunExample("3", stm3.toString(),cont3));
        menu.addCommand(new RunExample("4", stm4.toString(),cont4));
        menu.addCommand(new RunExample("5", stm5.toString(),cont5));
        menu.addCommand(new RunExample("6", stm6.toString(),cont6));
        menu.addCommand(new RunExample("7", stm7.toString(),cont7));
        menu.addCommand(new RunExample("8", stm8.toString(),cont8));
        menu.addCommand(new RunExample("9", stm9.toString(),cont9));



        menu.show();

    }
}
