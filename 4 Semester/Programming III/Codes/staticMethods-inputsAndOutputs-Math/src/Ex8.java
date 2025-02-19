import javax.swing.*;

public class Ex8 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(null, "Enter 'n' value: ", "Input" , JOptionPane.PLAIN_MESSAGE);
        int n = Integer.parseInt(s);

        StringBuilder resultWithoutArrays = new StringBuilder("Triangle of Pascal (without arrays):\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                resultWithoutArrays.append(binomialCoefficient(i, j)).append(" ");
            }
            resultWithoutArrays.append("\n");
        }
        JOptionPane.showMessageDialog(null, resultWithoutArrays.toString(), "Triangle of Pascal", JOptionPane.PLAIN_MESSAGE);

        StringBuilder resultWithArrays = new StringBuilder("Triangle of Pascal (with arrays):\n");
        int[][] pascalTriangle = calculatePascalTriangle(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                resultWithArrays.append(pascalTriangle[i][j]).append(" ");
            }
            resultWithArrays.append("\n");
        }
        JOptionPane.showMessageDialog(null, resultWithArrays.toString(), "Triangle of Pascal", JOptionPane.PLAIN_MESSAGE);
    }

    public static int binomialCoefficient(int n, int k) {
        int result = 1;
        for (int i = 1; i <= k; i++) {
            result = result * (n - i + 1) / i;
        }
        return result;
    }

    public static int[][] calculatePascalTriangle(int n) {
        int[][] pascalTriangle = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    pascalTriangle[i][j] = 1;
                } else {
                    pascalTriangle[i][j] = pascalTriangle[i - 1][j - 1] + pascalTriangle[i - 1][j];
                }
            }
        }
        return pascalTriangle;
    }
}
