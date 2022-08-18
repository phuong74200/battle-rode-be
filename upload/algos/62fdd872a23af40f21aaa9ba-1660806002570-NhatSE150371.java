
import java.util.Scanner;


public class Problem_One {

     public static int inputNumber() {
        int number=-1;
        Scanner input = new Scanner(System.in);
        if(number < 0){
            number = input.nextInt();
        }
        return number;
    }

    public static int sumOfDigit(int number) {
        int sum=0;
        for(int i=0; i<=number ;i++){
            sum= sum + number;
            number -- ;
            if(number ==0){
                         break;   
            }
        }
        
        return sum;
    }
    
    public static int[] getPrimeFactorList (int number) {
        int[] primes = null;
        
        return primes;
    }

    public static int[] getDivisorList(int number) {
        int divisor[] = null;
        
        return divisor;
    }
//do not change anything in the main method
    public static void main(String[] args) {
        System.out.print("input number: ");
        int number = inputNumber();
        System.out.println("Sum of digit: "+ sumOfDigit(number));
        System.out.println("Prime Factor List: " +getPrimeFactorList(number));
        System.out.println("Divisor List: " +getDivisorList(number));
    
}
}