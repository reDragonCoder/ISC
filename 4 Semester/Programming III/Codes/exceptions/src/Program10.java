import java.util.InputMismatchException;
import java.util.Scanner;

public class Program10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean flag = false;

        while(!flag) {
            try {
                System.out.print("Enter the first number: ");
                double a = sc.nextDouble();

                System.out.print("Enter the second number: ");
                double b = sc.nextDouble();

                if(b == 0.0){
                    throw new ArithmeticException("Division by zero");
                }

                double r = a / b;
                System.out.println("Result: " + r);
                flag = true;
            }
            catch(ArithmeticException ae) {
                System.out.println(ae.getMessage());
                ae.printStackTrace(System.out);
                System.out.flush();
                System.out.println();
            }
            catch(InputMismatchException ime) {
                System.out.println(ime.getMessage());
                ime.printStackTrace(System.out);
                System.out.flush();
                System.out.println();
                sc.nextLine();
            }
        }
        sc.close();
    }
}
