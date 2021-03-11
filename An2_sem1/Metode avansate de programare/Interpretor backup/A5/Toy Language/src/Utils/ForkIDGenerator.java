package Utils;

public class ForkIDGenerator {
    private static int id = 1;


    public static Integer generateId(){
        return id++;
    }
}
