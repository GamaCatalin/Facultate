/**
 * Provides the application entry point. It is completely manually written
 */

public class Main {
    /**
     *
     */
    public static void main(String[] args) {
        //create a Portofolio object
        Portofolio p = new Portofolio();
        //create, configure and register a Holding
        Holding h = new Holding();
        Stock s1 = new Stock(20);

		h.number = 1;
        h.setSecurity(s1);
        p.addHoldings(h);

        /**
         * loanValue is a constrained method. The call below triggers the checking of
         * its attached preconditions and postconditions
         */
        System.out.println(p.loanValue());

        System.out.println("The calculated value of this portofolio is " + p.value());
    }
}
