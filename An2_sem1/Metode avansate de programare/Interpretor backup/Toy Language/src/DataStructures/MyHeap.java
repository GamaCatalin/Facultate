package DataStructures;
import Exceptions.*;
import java.util.HashMap;
import java.util.Map;

public class MyHeap<V> implements IHeap<V>{
    HashMap<Integer,V> elements = new HashMap<>();
    int lastAddress=0;

    int generateKey(){
        return ++this.lastAddress;
    }


    @Override
    public V get(int key) throws exceptionKeyNotFound {
       if(this.exists(key)){
           return this.elements.get(key);
       }
       else{
           throw new exceptionKeyNotFound("Address not declared in heap!");
       }
    }

    @Override
    public int add(V value) {
        int currentKey = this.generateKey();
        this.elements.put(currentKey,value);
        return currentKey;
    }

    @Override
    public void update(int key, V value) throws exceptionKeyNotFound {
        if(!this.exists(key)){
            throw new exceptionKeyNotFound("Address not declared in heap!");
        }
        this.elements.replace(key,value);
    }

    @Override
    public void delete(int key) throws exceptionKeyNotFound {
        if(!this.exists(key)){
            throw new exceptionKeyNotFound("Address not declared in heap!");
        }
        this.elements.remove(key);
    }

    @Override
    public boolean isEmpty() {
        return this.elements.isEmpty();
    }

    @Override
    public boolean exists(int key) {
        return this.elements.containsKey(key);
    }

    @Override
    public void clear() {
        this.elements.clear();
        this.lastAddress=0;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        builder.append("{");

        if(!this.isEmpty()) {
            builder.append("\n");
            for (Map.Entry<Integer, V> element : this.elements.entrySet()) {
                builder.append("[");
                builder.append(element);
                builder.append("]");
                builder.append("\n");
            }
            builder.deleteCharAt(builder.lastIndexOf("\n"));
        }
        builder.append("\n}");
        return builder.toString();
    }
}
