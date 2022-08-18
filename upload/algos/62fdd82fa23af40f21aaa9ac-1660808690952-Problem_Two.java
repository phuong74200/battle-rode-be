package com.company;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @author hd
 */
public class Problem_Two {

    public static int inputNumber() {
        int number = -1;
        // your code here
        Scanner sc = new Scanner(System.in);
        number = sc.nextInt();
        return number;
    }

    public static int[] getPrimeNumberList(int number) {
        List<Integer> primes = new ArrayList<>();

        // your code here
        int maxNumberWithNdigit = 1;
        StringBuilder stringBuilder = new StringBuilder("");
        for (int i = 0; i < number; i++) {
            stringBuilder.append("9");
        }
        maxNumberWithNdigit = Integer.valueOf(stringBuilder.toString()).intValue();
        StringBuilder min = new StringBuilder("1");
        for (int i = 1; i < number; i++) {
            min.append("0");
        }
        int minNumberWithNDigit = Integer.valueOf(min.toString()).intValue();

        for (int i = minNumberWithNDigit; i < maxNumberWithNdigit; i++) {
            int count = 0;
            for (int j = 2; j <= i / 2; j++) {
                if (count > 2) {
                    break;
                }
                if (i % j == 0) {
                    count++;
                }
            }
            if (count == 0) {
                primes.add(i);
            }
        }

        return primes.stream().mapToInt(Integer::valueOf).toArray();
    }

    public static int[] getReversibleList(int number) {
        if (number == 0) {
            return new int[]{};
        }
        List<Integer> reuslt = new ArrayList<>();

        int maxNumberWithNdigit = 1;
        StringBuilder stringBuilder = new StringBuilder("");
        for (int i = 0; i < number; i++) {
            stringBuilder.append("9");
        }
        maxNumberWithNdigit = Integer.valueOf(stringBuilder.toString()).intValue();

        StringBuilder min = new StringBuilder("1");
        for (int i = 1; i < number; i++) {
            min.append("0");
        }
        int minNumberWithNDigit = Integer.valueOf(min.toString()).intValue();
        for (int i = minNumberWithNDigit; i < maxNumberWithNdigit; i++) {
            if (isReversibleNumber(i)) {
                reuslt.add(i);
            }
        }

        return reuslt.stream().mapToInt(Integer::valueOf).toArray();
    }

    static boolean isReversibleNumber(int number) {
        String s = Integer.valueOf(number).toString();
        int lenght = s.length();
        for (int i = 0; i < s.length() / 2; i++) {
            if (s.charAt(i) != s.charAt(lenght - i - 1)) {
                return false;
            }
        }
        return true;
    }

    public static int[] getReversible_SumList(int number) {
        List<Integer> result = new ArrayList<>();

        int maxNumberWithNdigit = 1;
        StringBuilder stringBuilder = new StringBuilder("");
        for (int i = 0; i < number; i++) {
            stringBuilder.append("9");
        }
        maxNumberWithNdigit = Integer.valueOf(stringBuilder.toString()).intValue();

        StringBuilder min = new StringBuilder("1");
        for (int i = 1; i < number; i++) {
            min.append("0");
        }
        int minNumberWithNDigit = Integer.valueOf(min.toString()).intValue();

        for (int i = minNumberWithNDigit; i < maxNumberWithNdigit; i++) {
            if (isReversibleNumber(sumOfNumber(i))) {
                result.add(i);
            }
        }


        return result.stream().mapToInt(Integer::valueOf).toArray();
    }

    static int sumOfNumber(int number) {
        int sum = 0;
        while (number / 10 == 0) {
            sum += number % 10;
            sum = sum / 10;
        }
        return sum;
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
