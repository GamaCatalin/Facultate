package Model.Statement;

import DataStructures.IList;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionDivisionByZero;
import Exceptions.exceptionInvalidOperation;
import Exceptions.exceptionKeyNotFound;
import Model.ProgramState;
import Model.Types.IValue;

public class PrintStatement implements IStatement{
    IValue value;
    public PrintStatement(IValue value){
        this.value=value;
    }


    @Override
    public ProgramState execute(ProgramState programState) throws exceptionDifferentOperandTypes, exceptionDivisionByZero, exceptionInvalidOperation, exceptionKeyNotFound {
        IList<IValue> outList = programState.getOutputList();
        outList.add(this.value.evaluate(programState.getSymbolTable(),programState.getHeap()));
        //System.out.println(this.expression.toString());
        return programState;
    }

    @Override
    public String toString() {
        return "@Print + "+this.value.toString();
    }
}
