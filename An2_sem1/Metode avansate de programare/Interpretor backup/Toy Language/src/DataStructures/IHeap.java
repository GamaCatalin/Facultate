package DataStructures;

import Exceptions.exceptionKeyNotFound;

public interface IHeap<V> {

    V get(int key) throws exceptionKeyNotFound;
    int add(V value);
    void update(int key, V value) throws exceptionKeyNotFound;
    void delete(int key) throws exceptionKeyNotFound;
    boolean isEmpty();
    boolean exists(int key);
    String toString();
    void clear();
}
