package Ex5;

import java.util.Scanner;
import java.util.Stack;

public class BracketNumbers {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int T = scanner.nextInt();
        scanner.nextLine();

        for (int t = 0; t < T; t++) {
            String expression = scanner.nextLine();
            Stack<Integer> stack = new Stack<>();
            int bracketCount = 0;
            StringBuilder output = new StringBuilder();

            for (int i = 0; i < expression.length(); i++) {
                char ch = expression.charAt(i);
                if (ch == '(') {
                    bracketCount++;
                    stack.push(bracketCount);
                    output.append(bracketCount).append(" ");
                } else if (ch == ')') {
                    if (!stack.isEmpty()) {
                        int num = stack.pop();
                        output.append(num).append(" ");
                    }
                }
            }
            System.out.println(output.toString().trim());
        }
        scanner.close();
    }
}

