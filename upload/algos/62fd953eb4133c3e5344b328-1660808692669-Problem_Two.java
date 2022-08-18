
/**
 *
 * @author hd
 */
import java.util.ArrayList;
import java.util.List;
public class Problem_Two {
public static int inputNumber() {
        int number = -1;
        
        try {
            number = Integer.parseInt(System.console().readLine());
        } catch (Exception e) {
            
        }
        
        return number;
    }

    public static int[] getPrimeNumberList(int number) {        
        if (number <= 0) {
            return new int[]{};
        } else if (number == 1) {
            return new int[]{1};
        } else if (number == 2) {
            return new int[]{1, 2};
        } else if (number == 3) {
            return new int[]{1, 2, 3};
        }
        
        List<Integer> list = new ArrayList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        
        for (int i = 4; i <= number; i++) {
            boolean check = false;
            for (int j = 2; j <= i; j++) {
                if (i % j == 0) {
                    check = true;
                }
            }
            
            if (check == false) {
                list.add(i);
            }
        }
        
        int listPrime[] = new int[list.size()];
        for (int i = 0; i < list.size(); i ++) {
            listPrime[i] = list.get(i);
        }

        return listPrime;
    }

    public static int[] getReversibleList(int number) {        
        if (number == 1) {
            return new int[]{1};
        }
        
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < number; i++) {
            list.add(i);
        }
        list.add(number);
        for (int i = number - 1; i > 0; i--) {
            list.add(i);
        }
        
        int listReversible[] = new int[list.size()];
        for (int i = 0; i < list.size(); i ++) {
            listReversible[i] = list.get(i);
        }

        return listReversible;
    }

    public static int[] getReversible_SumList(int number) {
        if (number == 1) {
            return new int[]{1};
        }
        
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < number; i++) {
            list.add(i);
        }
        list.add(number);
        for (int i = number - 1; i > 0; i--) {
            list.add(i);
        }
        
        int listReversible_Sum[] = new int[list.size()];
        for (int i = 0; i < list.size(); i ++) {
            int count = 0;
            int currentNum = list.get(i);
            while (currentNum > 0) {
                currentNum = currentNum / 10;
                count++;
            }
            listReversible_Sum[i] = count;
        }

        return listReversible_Sum;
    }
//do not change anything in the main method
    public static void main(String[] args) {
        System.out.print("input number: ");
        int number = inputNumber();
        System.out.println("Prime List: "+ getPrimeNumberList(number));
        System.out.println("Reversible List: " +getReversibleList(number));
        System.out.println("Reversible_Sum List: " +getReversible_SumList(number));
    
}
