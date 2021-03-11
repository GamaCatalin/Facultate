package DataStructures;

import Exceptions.exceptionKeyAlreadyInDictionary;
import Exceptions.exceptionKeyNotFound;

import java.util.List;

public interface IDictionary<T,V> {
    V get(T key) throws exceptionKeyNotFound;
    List<V> getValues();
    void add(T key, V value) throws exceptionKeyAlreadyInDictionary;
    void update(T key, V value) throws exceptionKeyNotFound;
    void remove(T key) throws exceptionKeyNotFound;
    boolean isEmpty();
    boolean exists(T key);
    String toString();
    void clear();
    IDictionary<T,V> copy() throws exceptionKeyAlreadyInDictionary;
}
