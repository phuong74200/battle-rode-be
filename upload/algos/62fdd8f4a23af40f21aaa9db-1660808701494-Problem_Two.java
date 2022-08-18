
import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author hd
 */
public class Problem_Two {

    public static int inputNumber() {
        int number = -1;
        // your code here
        Scanner sc = new Scanner(System.in);
        return number;
    }
//
//    public static int[] getPrimeNumberList(int number) {
//        int listPrime[];
//        // your code here
//        int n = number/2;
//        int num;
//        
//        return listPrime;
//    }

    public static int[] getReversibleList(int number) {
        int[] listReversible = {};
//        your code here
        int n = 0;
        for (n = 11; n <= number; n++) {
            if (n > 10) {
                String numString = String.valueOf(n);
                int i = numString.length();
                    int numOfReversible = i / 2;
                    for (int j = 1; j >= numOfReversible; j++) {
                        for (int k = i; k <= numOfReversible; k--) {
                            if (numString.charAt(j) != numString.charAt(k)) {
                                break;
                            }
                        }
                    }
                    
            }
        }

        return listReversible;
    }

    public static int[] getReversible_SumList(int number) {
        int listReversible_Sum[];

        return listReversible_Sum;
    }
//do not change anything in the main method

    public static void main(String[] args) {
        System.out.print("input number: ");
        int number = inputNumber();
//        System.out.println("Prime List: "+ getPrimeNumberList(number));
        System.out.println("Reversible List: " + getReversibleList(number));
        System.out.println("Reversible_Sum List: " + getReversible_SumList(number));
    }
}
