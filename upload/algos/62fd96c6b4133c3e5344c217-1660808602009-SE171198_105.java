/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package algorithm;

import java.util.Scanner;

/**
 *
 * @author CTF
 */
public class Algorithm {

    static Scanner sc = new Scanner(System.in);

    public static int inputNumber() {
        int number = -1;
        number = Integer.parseInt(sc.nextLine());
        return number;
    }

    static Boolean isprime(int x) {
        if (x <= 1) {
            return false;
        }
        for (int i = 2; i <= Math.round(Math.sqrt(x)); i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static int[] getPrimeNumberList(int number) {
        int y = (int) (Math.pow(10, number) - Math.pow(10, number - 1));
        int listPrime[];
        listPrime = new int[y];
        int count = 0;
        for (int i = (int) Math.pow(10, number - 1); i <= Math.pow(10, number) - 1; i++) {
            if (isprime(i)) {
                listPrime[0] = i;
                count++;
            }
        }
        return listPrime;
    }

    public static int[] getReversibleList(int number) {
        int y = (int) (Math.pow(10, number) - Math.pow(10, number - 1));
        int[] listReversible = new int[y];
        int count = 0;
        for (int i = (int) Math.pow(10, number - 1); i <= Math.pow(10, number) - 1; i++) {
            StringBuffer av=new StringBuffer(Integer.toString(i));
            av.reverse();
        
            int inv= Integer.parseInt(av.toString());
        
            if (i==inv) {
                listReversible[0] = i;
                count++;
            }
        }
        return listReversible;
    }

    public static int[] getReversible_SumList(int number) {
        int y = (int) (Math.pow(10, number) - Math.pow(10, number - 1));
        int[] listReversible = new int[y];
        int count = 0;
        for (int i = (int) Math.pow(10, number - 1); i <= Math.pow(10, number) - 1; i++) {
            int c=i;
            int sum1=0;
            while (c!=0){
                int cc=i%10;
                sum1+=cc;
                c=c/10;
            }
            
            StringBuffer av=new StringBuffer(Integer.toString(sum1));
            av.reverse();
        
            int inv= Integer.parseInt(av.toString());
        
            if (sum1==inv) {
                listReversible[0] = i;
                count++;
            }
        }
        return listReversible;
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