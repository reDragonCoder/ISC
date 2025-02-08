import javax.swing.*;

public class Ex4 {
    public static void main(String[] args) {
        String text = JOptionPane.showInputDialog("Enter your text: ");
        char[] chText = text.toCharArray();

        int digits = 0, letters = 0;

        for (char c : chText) {
            if (Character.isDigit(c)) {
                digits++;
            } else if (Character.isLetter(c)) {
                letters++;
            }
        }

        JOptionPane.showMessageDialog(null, "Digits: " + digits + "\nLetters: " + letters, "Results", JOptionPane.INFORMATION_MESSAGE);
    }
}
