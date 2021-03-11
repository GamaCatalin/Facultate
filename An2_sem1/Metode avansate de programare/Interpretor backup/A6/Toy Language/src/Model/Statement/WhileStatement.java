package Model.Statement;

import DataStructures.IDictionary;
import DataStructures.IStack;
import Exceptions.*;
import Model.Expression.IExpression;
import Model.ProgramState;
import Model.Types.*;
import Model.Types.Boolean;


public class WhileStatement implements IStatement{

    private final IExpression expression;
    private final IStatement statement;

    public WhileStatement(IExpression expression, IStatement statement){
        this.expression = expression;
        this.statement = statement;
    }


    @Override
    public ProgramState execute(ProgramState programState) throws exceptionDifferentOperandTypes, exceptionDivisionByZero, exceptionInvalidOperation, exceptionKeyNotFound{

        IValue eval = this.expression.evaluate(programState.getSymbolTable(), programState.getHeap());


        if(!eval.getType().equals(new BooleanType())){
            throw new exceptionInvalidOperation("Invalid operation type!");
        }

        Boolean boolEval = (Boolean) eval;

        IStack<IStatement> stack = programState.getExecutionStack();

        if(boolEval.getValue()){
            stack.push(new WhileStatement(this.expression,this.statement));
            stack.push(this.statement);
        }

        return null;
    }

    @Override
    public String toString() {
        return "While("+this.expression.toString()+")    Then("+this.statement.toString()+")";
    }

    @Override
    public IDictionary<String, IType> typeCheck(IDictionary<String, IType> typeEnv) throws exceptionInvalidValue, exceptionDifferentOperandTypes, exceptionKeyAlreadyInDictionary {
        IType typeExpr = this.expression.typeCheck(typeEnv);
        if(typeExpr.equals(Type.Boolean)){
            this.statement.typeCheck(typeEnv.copy());
            return typeEnv;
        }
        else{
            throw new exceptionInvalidValue("Condition in WHILE not of boolean type!");
        }
    }
}
