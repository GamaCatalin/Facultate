package Tests;

import DataStructures.MyDictionary;
import DataStructures.MyList;
import DataStructures.MyStack;
import Exceptions.*;


public class AllTests {

    public AllTests(){

    }



    public void runAll() throws exceptionDivisionByZero, exceptionInvalidOperation, exceptionIndexOutOfBounds, exceptionStackIsEmpty, exceptionKeyAlreadyInDictionary, exceptionKeyNotFound {
        MyList_addElem_addedSuccessful();
        MyList_getElem_returnSuccessful();
        MyList_removeElem_removedSuccessful();
        MyList_toString_stringReturned();
        MyStack_push_pushSuccessful();
        MyStack_pop_popSuccessful();
        MyStack_toString_stringReturned();
        MyDictionary_add_addedSuccessfully();
        MyDictionary_add_exceptionKeyAlreadyInDictionary();
        MyDictionary_get_returnedSuccessfully();
        MyDictionary_update_updatedSuccessfully();
        MyDictionary_remove_removedSuccessfully();
        MyDictionary_toString_stringReturned();
    }


    private void MyList_addElem_addedSuccessful(){
        MyList<String> list = new MyList<>();
        assert list.isEmpty() : "Wrong list empty!";
        list.add("Elem1");
        assert list.getSize()==1 : "Wrong list size";
    }

    private void MyList_removeElem_removedSuccessful() throws exceptionIndexOutOfBounds {
        MyList<String> list = new MyList<>();
        assert list.isEmpty() : "Wrong list empty!";
        list.add("Elem1");
        assert list.getSize()==1 : "Wrong list size";
        list.remove(0);
        assert list.isEmpty() : "Wrong remove!";
    }


    private void MyList_getElem_returnSuccessful() throws exceptionIndexOutOfBounds {
        MyList<String> list = new MyList<>();
        list.add("elem1");
        list.add("elem2");
        list.add("elem3");
        assert list.get(0).equals("elem1") && list.get(1).equals("elem2") : "Wrong list get!";
    }

    private void MyList_toString_stringReturned(){
        MyList<String> list = new MyList<>();
        list.add("elem1");
        list.add("elem2");
        list.add("elem3");
        assert list.toString().equals("[elem1,elem2,elem3]") : "Wrong toString!";
    }

    private void MyStack_push_pushSuccessful(){
        MyStack<String> stack = new MyStack<>();
        assert stack.isEmpty() : "Stack is not empty!";
        stack.push("elem1");
        stack.push("elem2");
        stack.push("elem3");
        assert !stack.isEmpty() : "Wrong push!";
    }

    private void MyStack_pop_popSuccessful() throws exceptionStackIsEmpty {
        MyStack<String> stack = new MyStack<>();
        stack.push("elem1");
        stack.push("elem2");
        stack.push("elem3");
        String elem = stack.pop();
        assert elem.equals("elem3") : "Wrong pop!";
    }

    private void MyStack_toString_stringReturned(){
        MyStack<String> stack = new MyStack<>();
        stack.push("elem1");
        stack.push("elem2");
        stack.push("elem3");
        assert stack.toString().equals("[elem3|elem2,elem1]") : "Wrong toString!";
    }

    private void MyDictionary_add_addedSuccessfully() throws exceptionKeyAlreadyInDictionary {
        MyDictionary<String,String> dictionary = new MyDictionary<>();
        assert dictionary.isEmpty() : "Wrong isEmpty!";
        dictionary.add("key1","value1");
        dictionary.add("key2","value2");
        dictionary.add("key3","value3");
        assert !dictionary.isEmpty() : "Wrong add!";
    }

    private void MyDictionary_add_exceptionKeyAlreadyInDictionary() throws exceptionKeyAlreadyInDictionary, exceptionKeyNotFound {
        MyDictionary<String,String> dictionary = new MyDictionary<>();

        dictionary.add("key1","value1");
        dictionary.add("key2","value2");
        try {
            dictionary.add("key2","value3");
        }
        catch (exceptionKeyAlreadyInDictionary e) {
            assert true;
        }

        assert dictionary.get("key2").equals("value2") : "Wrong exceptionKeyAlreadyInDictionary!";
    }

    public void MyDictionary_get_returnedSuccessfully() throws exceptionKeyAlreadyInDictionary, exceptionKeyNotFound {
        MyDictionary<String,String> dictionary = new MyDictionary<>();
        dictionary.add("key1","value1");
        dictionary.add("key2","value2");
        dictionary.add("key3","value3");
        assert dictionary.get("key2").equals("value2") : "Wrong get!";
    }

    public void MyDictionary_update_updatedSuccessfully() throws exceptionKeyAlreadyInDictionary, exceptionKeyNotFound {
        MyDictionary<String,String> dictionary = new MyDictionary<>();
        dictionary.add("key1","value1");
        dictionary.add("key2","value2");
        dictionary.add("key3","value3");
        dictionary.update("key1","value4");
        assert dictionary.get("key1").equals("value4") : "Wrong update!";
    }

    public void MyDictionary_remove_removedSuccessfully() throws exceptionKeyAlreadyInDictionary, exceptionKeyNotFound {
        MyDictionary<String,String> dictionary = new MyDictionary<>();
        dictionary.add("key1","value1");
        dictionary.remove("key1");
        assert dictionary.isEmpty() : "Wrong remove!";
    }

    public void MyDictionary_toString_stringReturned() throws exceptionKeyAlreadyInDictionary {
        MyDictionary<String,String> dictionary = new MyDictionary<>();
        dictionary.add("key1","value1");
        dictionary.add("key2","value2");
        dictionary.add("key3","value3");
        assert dictionary.toString().equals("{[key1=value1],[key2=value2],[key3=value3]}") : "Wrong toString!";
    }
}
