import javax.swing.*;

public class Ex11 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(null, "Enter the number of test cases: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int n = Integer.parseInt(s);

        while (n > 0) {
            s = JOptionPane.showInputDialog(null, "Enter the 's' string: ", "Input", JOptionPane.PLAIN_MESSAGE);
            String t = JOptionPane.showInputDialog(null, "Enter the 't' string: ", "Input", JOptionPane.PLAIN_MESSAGE);

            if (isSubsequence(s, t)) {
                JOptionPane.showMessageDialog(null, "Yes");
            } else {
                JOptionPane.showMessageDialog(null, "No");
            }
            n--;
        }
    }

    public static boolean isSubsequence(String s, String t) {
        int indexS = 0;

        for (int i = 0; i < t.length() && indexS < s.length(); i++) {
            if (s.charAt(indexS) == t.charAt(i)) {
                indexS++;
            }
        }

        return indexS == s.length();
    }
}
