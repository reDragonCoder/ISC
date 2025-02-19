import javax.swing.*;

public class Ex9 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(null, "Enter 'n' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int n = Integer.parseInt(s);
        int[][] matrix = new int[n][n];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[i][j] = (int)(Math.random() * 100+1);
            }
        }

        StringBuilder matrixOutput = new StringBuilder();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrixOutput.append(String.format("%4d", matrix[i][j])).append(" ");
            }
            matrixOutput.append("\n");
        }

        int rowSum = 0, colSum = 0;
        StringBuilder row_sumOutput = new StringBuilder("--- Row Sums ---\n");
        StringBuilder col_sumOutput = new StringBuilder("--- Column Sums ---\n");

        for (int i = 0; i < n; i++) {
            row_sumOutput.append("Row ").append(i+1).append(": ");
            col_sumOutput.append("Col ").append(i+1).append(": ");
            for (int j = 0; j < n; j++) {
                rowSum += matrix[i][j];
                colSum += matrix[j][i];
            }
            row_sumOutput.append(rowSum).append("\n");
            col_sumOutput.append(colSum).append("\n");
            rowSum = 0;
            colSum = 0;
        }

        JOptionPane.showMessageDialog(null, "MATRIX:\n" + matrixOutput + "\n" + row_sumOutput + "\n" + col_sumOutput, "Output", JOptionPane.PLAIN_MESSAGE);
    }
}
