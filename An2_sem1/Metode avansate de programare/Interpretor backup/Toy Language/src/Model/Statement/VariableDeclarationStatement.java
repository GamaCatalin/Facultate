package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.exceptionKeyAlreadyInDictionary;
import Model.Types.IType;
import Model.Types.IValue;
import Model.Types.Unknown;
import Model.ProgramState;

public class VariableDeclarationStatement implements IStatement{
    String id;
    IValue value;

    public VariableDeclarationStatement(String id, IType type){
        this.id = id;
        this.value = new Unknown(type);
    }

    @Override
    public ProgramState execute(ProgramState programState) throws exceptionKeyAlreadyInDictionary {
        IDictionary<String,IValue> symTable = programState.getSymbolTable();
        if(symTable.exists(this.id)){
            throw new exceptionKeyAlreadyInDictionary("Variable is already declared!");
        }
        else{
            symTable.add(this.id,this.value);
        }

        return programState;
    }

    @Override
    public String toString() {
        return "@Declare( " + this.id +" @"+this.value.toString()+")";
    }
}
