// Author: reDragonCoder

import static java.lang.System.out; //to use out without writing System.out
import javax.swing.*; //GUI java elements

public class Dialogues {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(
                null, "Rows?\n", "Input", JOptionPane.PLAIN_MESSAGE);
        int rows = Integer.parseInt(s);

        s = JOptionPane.showInputDialog(
                null, "Columns?\n", "Input", JOptionPane.PLAIN_MESSAGE);
        int columns = Integer.parseInt(s);

        double[][] matrix = new double[rows][columns];
        JOptionPane.showMessageDialog(
                null, "Rows: " + rows + '\n' + "Columns: " + columns);

        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                matrix[i][j] = Math.random();
            }
        }
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                out.print(" (" + i + ", " + j + ") -> " + matrix[i][j]);
            }
            out.println();
        }
    }
}
