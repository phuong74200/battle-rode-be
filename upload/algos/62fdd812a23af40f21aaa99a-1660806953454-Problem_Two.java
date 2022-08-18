/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package problem_two;

import java.util.Scanner;

/**
 *
 * @author DELL
 */
public class Problem_Two {

     public static int inputNumber() {
        int number=-1;
         
         number = sc.nextInt();
        
        return number;
    }

    public static int[] getPrimeNumberList(int number) {
        int listPrime[] = null;
        for(int i = 0;i<number;i++){
            if(listPrime[i] %2 ==0){
                
            }
        }
        
        return listPrime;
    }
    
    public static int[] getReversibleList  (int number) {
        int[] listReversible ;
//        your code here

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
        System.out.println("Prime List: "+ getPrimeNumberList(number));
        System.out.println("Reversible List: " +getReversibleList(number));
        System.out.println("Reversible_Sum List: " +getReversible_SumList(number));
    /**
     * @param args the command line arguments
     */
    
    
}
