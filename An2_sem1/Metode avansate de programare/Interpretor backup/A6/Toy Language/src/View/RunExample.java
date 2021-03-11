package View;

import Controller.Controller;

public class RunExample extends Command {
    private final Controller controller;


    public RunExample(String key, String desc,Controller ctr){
        super(key, desc);
        this.controller=ctr;
    }

    @Override
    public void execute() {
        controller.runAll();

    }
}