package View;

import Controller.Controller;
import Exceptions.*;

import java.io.IOException;

public class RunExample extends Command {
    private final Controller controller;


    public RunExample(String key, String desc,Controller ctr){
        super(key, desc);
        this.controller=ctr;
    }

    @Override
    public void execute() {
        try{
            controller.runAll();
        } catch (exceptionDivisionByZero | exceptionStackIsEmpty | exceptionKeyAlreadyInDictionary | exceptionDifferentOperandTypes | exceptionVariableNotDeclared | exceptionFileNotFound | exceptionKeyNotFound | exceptionInvalidOperation | exceptionExpressionNotOfStringType | IOException | exceptionInvalidValue exception) {
            exception.printStackTrace();
            //System.out.println(exception.getMessage());
        }

    }
}