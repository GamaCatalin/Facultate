package DataStructures;

import Exceptions.exceptionIndexOutOfBounds;

public interface IList<T> {
    T get(int index) throws exceptionIndexOutOfBounds;
    void add(T elem);
    void remove(int index) throws exceptionIndexOutOfBounds;
    boolean isEmpty();
    int getSize();
    String toString();
}
