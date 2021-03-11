package DataStructures;
import Exceptions.exceptionStackIsEmpty;

public interface IStack<T> {
    T pop() throws exceptionStackIsEmpty;
    void push(T elem);
    boolean isEmpty();
    String toString();
    T peek() throws exceptionStackIsEmpty;
}
