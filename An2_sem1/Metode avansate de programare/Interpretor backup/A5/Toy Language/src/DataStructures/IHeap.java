package DataStructures;

import Exceptions.exceptionKeyNotFound;

import java.util.HashMap;
import java.util.Map;

public interface IHeap<V> {

    V get(int key) throws exceptionKeyNotFound;
    int add(V value);
    void update(int key, V value) throws exceptionKeyNotFound;
    void delete(int key) throws exceptionKeyNotFound;
    boolean isEmpty();
    boolean exists(int key);
    void setContent(HashMap<Integer,V> newContent);
    Map<Integer,V> getContent();
    String toString();
    void clear();
}
