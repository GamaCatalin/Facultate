package DataStructures;
import java.util.*;

import Exceptions.exceptionStackIsEmpty;

public class MyStack<T> implements IStack<T>{
    Deque<T> elements = new ArrayDeque<>();

    @Override
    public T pop() throws exceptionStackIsEmpty{
        if(this.isEmpty()){
            throw new exceptionStackIsEmpty("Stack is empty!");
        }
        else{
            return elements.pop();
        }
    }

    @Override
    public void push(T elem) {
        this.elements.push(elem);
    }

    @Override
    public boolean isEmpty() {
        return this.elements.size() == 0;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        Iterator<T> iter = this.elements.iterator();
        List<String> reverseIter = new ArrayList<>();

        if(!this.isEmpty()) {
            while (iter.hasNext())
                reverseIter.add(iter.next().toString());

        }

        builder.append("[\n");


        if(!this.isEmpty()) {
            if (reverseIter.size() > 1) {
                String firstString = reverseIter.get(reverseIter.size() - 1);
                reverseIter.remove(reverseIter.size() - 1);
                String secondString = reverseIter.get(reverseIter.size() - 1);
                reverseIter.remove(reverseIter.size() - 1);

                builder.append(secondString);
                builder.append("\n");
                builder.append(firstString);

            }
            while (reverseIter.size() > 0) {
                builder.append(reverseIter.get(reverseIter.size() - 1));
                reverseIter.remove(reverseIter.size() - 1);
            }
        }

        builder.append("\n]");
        return builder.toString();
    }

    @Override
    public T peek() throws exceptionStackIsEmpty {
        if(this.isEmpty()){
            throw new exceptionStackIsEmpty("Stack is empty!");
        }
        else{
            return elements.peek();
        }
    }
}
