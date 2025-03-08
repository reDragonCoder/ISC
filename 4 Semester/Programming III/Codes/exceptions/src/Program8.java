import java.util.Scanner;

public class Program8 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean flag = false;

        while(!flag) {
            try {
                System.out.print("Enter a number: ");
                int n = sc.nextInt();
                flag = true;
                System.out.println("Your number is: " + n);
            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
                sc.nextLine();
            }
        }
        sc.close();
    }
}
