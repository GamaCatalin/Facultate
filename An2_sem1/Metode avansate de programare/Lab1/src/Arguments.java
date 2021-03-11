
public class Arguments {

    public static void main(String[]args) {

        double sum=0;
        int i=0;

        if(args.length>=1){

            try{
                for(i=0;i<args.length;i++){
                    sum += Double.parseDouble(args[i]);
                }
            }
            catch (Exception exception){
                System.out.println("Argument " + i + " is not a number!");
            }


            System.out.println("Average is: " + sum/args.length);
        }


    }

}


