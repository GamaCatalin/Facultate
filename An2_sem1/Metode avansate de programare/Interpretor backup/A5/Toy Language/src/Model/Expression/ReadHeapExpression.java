package Model.Expression;

import DataStructures.IDictionary;
import DataStructures.IHeap;
import Exceptions.exceptionDifferentOperandTypes;
import Exceptions.exceptionDivisionByZero;
import Exceptions.exceptionInvalidOperation;
import Exceptions.exceptionKeyNotFound;
import Model.Types.IType;
import Model.Types.IValue;
import Model.Types.Reference;
import Model.Types.StringVal;

public class ReadHeapExpression implements IExpression,IValue{

    private final IExpression varName;

    public ReadHeapExpression(IExpression varName){
        this.varName = varName;
    }

    @Override
    public IValue evaluate(IDictionary<String, IValue> dictionary, IHeap<IValue> heap) throws exceptionKeyNotFound, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation {

        if(this.varName instanceof StringVal){
            if(!dictionary.exists(((StringVal)this.varName).getValue())){
                throw new exceptionKeyNotFound("Variable not in symbol table!");
            }

            Reference heapElem = (Reference) dictionary.get(((StringVal)this.varName).getValue());

            int heapAddr = heapElem.getAddress();

            if(!heap.exists(heapAddr)){
                throw new exceptionKeyNotFound("Heap does not contain given address!");
            }

            return heap.get(heapAddr);
        }


        return heap.get(((Reference) this.varName.evaluate(dictionary, heap)).getAddress());

    }

    @Override
    public IType getType() {
        return null;
    }

    @Override
    public String toString() {
        return "Read Heap @ " + this.varName;
    }
}
