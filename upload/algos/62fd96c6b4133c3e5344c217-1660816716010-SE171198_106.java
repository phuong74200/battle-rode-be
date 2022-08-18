/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package se171198_106;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 *
 * @author CTF
 */
public class SE171198_106 {

    static ArrayList<Integer> list1 = new ArrayList<>();
    static Scanner sc = new Scanner(System.in);

    public static int inputNumber() {
        int number = -1;
        number = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < number; i++) {
            list1.add(Integer.parseInt(sc.nextLine()));
        }
        return number;
    }

    public static ArrayList<String> findBigestAnd2ndBigest(int[] arr) {
        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(list1);
        Collections.sort(list);
        Collections.reverse(list);
        int max = list.get(0);
        int max2 = 0;
        for (int i = 1; i < list.size(); i++) {
            if (list.get(i) < max) {
                max2 = list.get(i);
                break;
            }
        }
        String max01 = max + "index:" + list1.indexOf(max);
        String max02 = max2 + "index:" + list1.indexOf(max2);
        ArrayList<String> list03 = new ArrayList<>();
        list03.add(max01);
        list03.add(max02);

        return list03;
    }

    public static ArrayList<Integer> sortBubble(int[] number) {
        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(list1);
        Collections.sort(list);
        Collections.reverse(list);
        return list;
    }

    public static ArrayList<Integer> insertValues(int number) {
        
        ArrayList<Integer> list = new ArrayList<>();
        list.addAll(list1);
        list.add(number);
        Collections.sort(list);
        Collections.reverse(list);
        return list;
    }

    public static void main(String[] args) {
        System.out.print("input number: ");
        int len = inputNumber();
        int[] arr = new int[len];
        System.out.println("Prime List: " + findBigestAnd2ndBigest(arr));
        System.out.println("Sorted Array: " + sortBubble(arr));
        int number = inputNumber();
        System.out.println("Insert values to Array: " + insertValues(number));
    }

}
