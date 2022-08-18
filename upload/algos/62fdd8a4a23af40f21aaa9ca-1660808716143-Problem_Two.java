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
        while (true) {
            try {
                number = sc.nextInt();
                break;
            } catch (NumberFormatException e) {
                System.out.println("Hey! INPUT A NUMBER!");
            }
        }
        return number;
    }

    public static boolean isPrime(int n) {
        for (int i = 2; i < Math.sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static String getPrimeNumberList(int number) {
        String listPrime = "";
        // your code here
        int max = (int) Math.pow(10, number) - 1;
        int min = (int) Math.pow(10, number - 1);
        for (int i = min; i < max; i++) {
            if (isPrime(i)) {
                listPrime = listPrime + "  " + i;
            }
        }
        return listPrime;
    }
    public static int MAX = 1000000;

    public static boolean isReversible(int n,int d) {
        int[] s = new int[MAX];

        int index = 0;
        while (n / 10 > 0) {
            s[index] = n % 10;
            n = n / 10;
            index++;
        }
        s[index] = n % 10;
        boolean chk = false;
        for (index = 0; index < d / 2; index++) {
            chk = s[index] == s[d - index - 1];
        }
        return chk;
    }

    public static String getReversibleList(int number) {
        String listReversible = "";
//        your code here
        int max = (int) Math.pow(10, number) - 1;
        int min = (int) Math.pow(10, number - 1);
        for (int i = min; i < max; i++) {
            if (isReversible(i,number)) {
                listReversible = listReversible + "  " + i;
            }
        }
        return listReversible;
    }

    public static int SumDigits(int n) {
        int s = 0;
        while (n / 10 > 0) {
            s = s + (n % 10);
            n = n / 10;
        }
        s = s + (n % 10);
        return s;
    }
    public static int Index(int n){
        int[] s = new int[MAX];

        int index = 0;
        while (n / 10 > 0) {
            s[index] = n % 10;
            n = n / 10;
            index++;
        }
        s[index] = n % 10;
        return index;
    }
    public static String getReversible_SumList(int number) {
        String listReversible_Sum = "";
        int max = (int) Math.pow(10, number) - 1;
        int min = (int) Math.pow(10, number - 1);
        for (int i = min; i < max; i++) {
            int s = SumDigits(i);
            if (isReversible(s,Index(s))) {
                listReversible_Sum = listReversible_Sum + "  " + i;
            }
        }
        return listReversible_Sum;
    }
//do not change anything in the main method

    public static void main(String[] args) {
        System.out.print("input number: ");
        int number = inputNumber();
        System.out.println("Prime List: " + getPrimeNumberList(number));
        System.out.println("Reversible List: " + getReversibleList(number));
        System.out.println("Reversible_Sum List: " + getReversible_SumList(number));
    }
}