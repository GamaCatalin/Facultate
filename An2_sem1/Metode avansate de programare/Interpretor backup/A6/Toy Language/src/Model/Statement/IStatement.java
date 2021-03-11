package Model.Statement;
import DataStructures.IDictionary;
import Exceptions.*;
import Model.ProgramState;
import Model.Types.IType;

import java.io.IOException;

public interface IStatement {
    ProgramState execute(ProgramState programState) throws exceptionVariableNotDeclared, exceptionKeyNotFound, exceptionKeyAlreadyInDictionary, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionExpressionNotOfStringType, exceptionFileNotFound, IOException, exceptionInvalidValue;
    String toString();
    IDictionary<String, IType> typeCheck(IDictionary<String,IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes, exceptionKeyAlreadyInDictionary;
}
