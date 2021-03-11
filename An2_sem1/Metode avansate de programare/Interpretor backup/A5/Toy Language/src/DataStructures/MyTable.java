package DataStructures;

import Exceptions.exceptionKeyAlreadyInDictionary;
import Exceptions.exceptionKeyNotFound;

import java.util.*;

public class MyTable<T,V> implements IDictionary<T,V>{

    HashMap<T,V> elements = new HashMap<>();



    @Override
    public V get(T key) throws exceptionKeyNotFound {
        V element = this.elements.get(key);
        if(element == null){
            throw new exceptionKeyNotFound("File name not found!");
        }
        return element;
    }

    @Override
    public List<V> getValues() {
        return new ArrayList<>(this.elements.values());
    }

    @Override
    public void add(T key, V value) throws exceptionKeyAlreadyInDictionary {
        if(this.elements.containsKey(key)){
            throw new exceptionKeyAlreadyInDictionary("File name is already in the table!");
        }
        this.elements.put(key,value);
    }

    @Override
    public void update(T key, V value) throws exceptionKeyNotFound {
        if(!this.elements.containsKey(key)){
            throw new exceptionKeyNotFound("File name not found!");
        }
        this.elements.put(key,value);
    }

    @Override
    public void remove(T key) throws exceptionKeyNotFound {
        if(!this.elements.containsKey(key)){
            throw new exceptionKeyNotFound("File name not found!");
        }
        this.elements.remove(key);
    }

    @Override
    public boolean isEmpty() {
        return elements.isEmpty();
    }

    @Override
    public boolean exists(T key) {
        return this.elements.containsKey(key);
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        builder.append("{");

        if(!this.isEmpty()) {
            builder.append("\n");
            for (Map.Entry<T, V> element : this.elements.entrySet()) {
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

    @Override
    public void clear() {
        Set<T> keySey = this.elements.keySet();
        for (T key: keySey) {
            elements.remove(key);
        }
    }

    @Override
    public IDictionary<T, V> copy() throws exceptionKeyAlreadyInDictionary {
        IDictionary<T,V> newDict = new MyDictionary<>();

        for (Map.Entry<T,V> element : this.elements.entrySet()) {
            newDict.add(element.getKey(),element.getValue());
        }
        return newDict;
    }
}
