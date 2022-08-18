
import java.util.Scanner;


/**
 *
 * @author hd
 */
public class Problem_Two {
    public static int inputNumber() {
        int number=-1;
        // your code here
        Scanner sc = new Scanner(System.in);
        number = sc.nextInt();
        return number;
    }
    public static int[] findBigestAnd2ndBigest(int[] arr) {
        int array[] = new int[2];
        // your code here
        int temp = 0;
        for (int i = 0; i < arr.length; i++) {
            if(temp >= arr[i]){
                temp = arr[i];
            }
        }
        array[0] = temp;
        return array;
    }
    
    public static int[] sortBubble  (int[] number) {
        int[] sortedArray ;
//        your code here
        int temp;
        for (int i = 0; i < number.length; i++) {
            
            
        }

        return sortedArray;
    }

//    public static int[] insertValues(int number) {
//        int insertedArray[];
//        
//        return insertedArray;
//    }

    public static void main(String[] args) {
        System.out.print("input number: ");
        int len = inputNumber();
        int[] arr= new int[len];
        int c = 0;
        while(c < len){
            System.out.print("input number: ");
            arr[c] = inputNumber();
            c++;
        }
        System.out.println("Prime List: "+ findBigestAnd2ndBigest(arr));
//        System.out.println("Sorted Array: " +sortBubble(arr));
//        int number= inputNumber();
//        System.out.println("Insert values to Array: " +insertValues(number));
    }
}
