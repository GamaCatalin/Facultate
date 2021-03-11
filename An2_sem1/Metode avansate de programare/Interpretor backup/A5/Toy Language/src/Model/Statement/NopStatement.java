package Model.Statement;

import Model.ProgramState;

public class NopStatement implements IStatement{


    public NopStatement(){

    }

    @Override
    public ProgramState execute(ProgramState programState){
        return null;
    }


    @Override
    public String toString() {
        return "@Nop";
    }
}
