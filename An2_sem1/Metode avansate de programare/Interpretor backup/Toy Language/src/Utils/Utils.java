package Utils;

import Model.Statement.CompoundStatement;
import Model.Statement.IStatement;
import Model.Statement.NopStatement;
import Model.Types.IValue;
import Model.Types.NumberType;
import Model.Types.Reference;
import Model.Types.ReferenceType;

import java.util.*;
import java.util.stream.Collectors;

public class Utils {

    public static IStatement mergeStatements(IStatement... statements){
        if(statements.length==0){
            return new NopStatement();
        }

        return new CompoundStatement(statements[0],mergeStatements(Arrays.copyOfRange(statements,1,statements.length)));
    }


    public static Map<Integer, IValue> GarbageCollector(List<Integer> symTableAddr, Map<Integer,IValue> heap){
        return heap.entrySet().stream()
                .filter(e->symTableAddr.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey,Map.Entry::getValue));
    }


    public static List<Integer> getAddrFromSymTable(Collection<IValue> symTable){
        return symTable.stream()
                .filter(v-> v.getType().equals(new ReferenceType(new NumberType())))
                .map(v -> {
                    Reference v1 = (Reference) v;
                    return v1.getAddress();
                 })
                .collect(Collectors.toList());
    }

}


