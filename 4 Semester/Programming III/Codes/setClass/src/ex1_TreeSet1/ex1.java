package ex1_TreeSet1;
import java.util.NavigableSet;
import java.util.Scanner;
import java.util.TreeSet;

public class ex1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        NavigableSet<Integer> treeSet = new TreeSet<>();

        System.out.println("Enter the numbers tou want to store in the tree set");
        System.out.println("When you finish, enter * to exit");
        while(sc.hasNextInt()) {
            int n = sc.nextInt();
            treeSet.add(n);
        }
        System.out.println("This are the numbers in the tree set in order: ");
        for (Integer integer : treeSet) {
            System.out.print(integer);
            System.out.print(" ");
        }

        sc.close();
    }
}
