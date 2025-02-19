import javax.swing.*;

public class Ex1 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(
                null, "Enter 'a' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        double a = Double.parseDouble(s);

        s = JOptionPane.showInputDialog(
                null, "Enter 'b' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        double b = Double.parseDouble(s);

        s = JOptionPane.showInputDialog(
                null, "Enter 'c' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        double c = Double.parseDouble(s);

        s = JOptionPane.showInputDialog(
                null, "Enter 'd' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        double d = Double.parseDouble(s);

        double formula1 = (a+b+c)/d;
        double formula2 = ((Math.pow((a-b), 2))/c) - (Math.pow((a-b), 3)/(d/a));

        JOptionPane.showMessageDialog(
                null, "Result formula 1: " + formula1 +
                        "\nResult formula 2: " + formula2, "Result", JOptionPane.PLAIN_MESSAGE);

    }
}
