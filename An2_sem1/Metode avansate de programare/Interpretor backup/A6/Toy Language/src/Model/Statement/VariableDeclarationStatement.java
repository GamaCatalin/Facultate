package Model.Statement;

import DataStructures.IDictionary;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionInvalidValue;
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

        return null;
    }

    @Override
    public String toString() {
        return "@Declare( " + this.id +" @"+this.value.toString()+")";
    }

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes {
        try {
            typeEnv.add(this.id,this.value.getType());
        } catch (Exceptions.exceptionKeyAlreadyInDictionary exceptionKeyAlreadyInDictionary) {
            System.out.println(exceptionKeyAlreadyInDictionary.getMessage());
        }
        return typeEnv;
    }
}
