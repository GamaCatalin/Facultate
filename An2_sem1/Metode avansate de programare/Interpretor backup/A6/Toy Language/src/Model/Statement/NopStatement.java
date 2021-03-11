package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionInvalidValue;
import Exceptions.exceptionKeyAlreadyInDictionary;
import Model.ProgramState;
import Model.Types.IType;

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

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes, exceptionKeyAlreadyInDictionary {
        return typeEnv;
    }
}
