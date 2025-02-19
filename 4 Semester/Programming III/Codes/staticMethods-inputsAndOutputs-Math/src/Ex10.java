import javax.swing.*;

public class Ex10 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(null, "Enter 'n' value for matrix 1: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int n1 = Integer.parseInt(s);

        s = JOptionPane.showInputDialog(null, "Enter 'm' value for matrix 1: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int m1 = Integer.parseInt(s);

        s = JOptionPane.showInputDialog(null, "Enter 'n' value for matrix 2: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int n2 = Integer.parseInt(s);

        s = JOptionPane.showInputDialog(null, "Enter 'm' value for matrix 2: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int m2 = Integer.parseInt(s);

        if(n1!=n2 || m1!=m2){
            JOptionPane.showMessageDialog(null, "Matrix 1 and Matrix 2 do not have the same dimension!", "Error", JOptionPane.ERROR_MESSAGE);
        }else{
            int[][] matrix1 = new int[n1][m1];
            int[][] matrix2 = new int[n2][m2];
            int[][] matrixR = new int[n1][m2];

            StringBuilder matrix1_Output = new StringBuilder("\n--- Matrix 1 ---\n");
            StringBuilder matrix2_Output = new StringBuilder("\n--- Matrix 2 ---\n");
            for(int i = 0; i < n1; i++){
                for(int j = 0; j < m1; j++){
                    matrix1[i][j] = (int)(Math.random()*100+1);
                    matrix1_Output.append(String.format("%4d", matrix1[i][j])).append(" ");
                    matrix2[i][j] = (int)(Math.random()*100+1);
                    matrix2_Output.append(String.format("%4d", matrix2[i][j])).append(" ");
                }
                matrix1_Output.append("\n");
                matrix2_Output.append("\n");
            }

            StringBuilder matrixR_Output = new StringBuilder("\n--- Result Matrix ---\n");
            for(int i = 0; i < n1; i++){
                for(int j = 0; j < m1; j++){
                    matrixR[i][j] = matrix1[i][j] + matrix2[i][j];
                    matrixR_Output.append(String.format("%4d", matrixR[i][j])).append(" ");
                }
                matrixR_Output.append("\n");
            }

            JOptionPane.showMessageDialog(null, "RESULTS\n" + matrix1_Output + matrix2_Output + matrixR_Output, "Results", JOptionPane.PLAIN_MESSAGE);
        }
    }
}
