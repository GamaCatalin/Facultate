package DataStructures;

import Exceptions.exceptionIndexOutOfBounds;

import java.util.ArrayList;

public class MyList<T> implements IList<T>{

    ArrayList<T> elements = new ArrayList<>();
    int size=0;


    @Override
    public T get(int index) throws exceptionIndexOutOfBounds {
        if(index >= this.size){
            throw new exceptionIndexOutOfBounds("Index out of bounds!");
        }
        return this.elements.get(index);
    }

    @Override
    public void add(T elem) {
        this.elements.add(elem);
        this.size++;
    }

    @Override
    public void remove(int index) throws exceptionIndexOutOfBounds {
        if(index >= this.size){
            throw new exceptionIndexOutOfBounds("Index out of bounds!");
        }
        this.elements.remove(index);
        this.size--;
    }

    @Override
    public boolean isEmpty() {
        return this.elements.size() == 0;
    }

    @Override
    public int getSize() {
        return this.size;
    }

    @Override
    public String toString() {
        StringBuilder builder = new StringBuilder();

        builder.append("[");

        if(!this.isEmpty()) {
            builder.append(this.elements.get(0));
            for (int i = 1; i < this.size; i++) {
                builder.append(",");
                builder.append(this.elements.get(i).toString());
            }
        }
        builder.append("]");
        return builder.toString();
    }
}
