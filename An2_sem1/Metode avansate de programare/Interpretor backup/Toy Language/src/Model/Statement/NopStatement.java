package Model.Statement;

import Model.ProgramState;

public class NopStatement implements IStatement{


    public NopStatement(){

    }

    @Override
    public ProgramState execute(ProgramState programState){
        return programState;
    }


    @Override
    public String toString() {
        return "@Nop";
    }
}
