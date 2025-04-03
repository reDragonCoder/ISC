package ex2_LinkedHashSet;

import java.util.LinkedHashSet;
import java.util.Scanner;
import java.util.Set;

public class ex2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Set<Integer> linkedHashSet = new LinkedHashSet<>();
        System.out.println("Enter the numbers to be inserted into the linked hash set");
        System.out.println("When you finish, enter * to exit");
        while(sc.hasNextInt()) {
            int n = sc.nextInt();
            linkedHashSet.add(n);
        }
        System.out.println("This are the numbers in the linked hash set: ");
        System.out.println(linkedHashSet);

        sc.close();
    }
}
