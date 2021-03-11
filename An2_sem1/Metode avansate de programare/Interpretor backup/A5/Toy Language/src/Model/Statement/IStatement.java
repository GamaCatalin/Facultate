package Model.Statement;
import Exceptions.*;
import Model.ProgramState;

import java.io.IOException;

public interface IStatement {
    ProgramState execute(ProgramState programState) throws exceptionVariableNotDeclared, exceptionKeyNotFound, exceptionKeyAlreadyInDictionary, exceptionDivisionByZero, exceptionDifferentOperandTypes, exceptionInvalidOperation, exceptionExpressionNotOfStringType, exceptionFileNotFound, IOException, exceptionInvalidValue;
    String toString();
}
