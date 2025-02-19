import javax.swing.*;

public class Ex6 {
    public static void main(String[] args) {
        String s1 = JOptionPane.showInputDialog(null, "Enter the first string: ", "Input", JOptionPane.PLAIN_MESSAGE);
        String s2 = JOptionPane.showInputDialog(null, "Enter the second string: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int times = repeatedString(s1, s2);
        JOptionPane.showMessageDialog(null, "String 1 appears " + times + " times in string 2", "Input", JOptionPane.PLAIN_MESSAGE);
    }
    public static int repeatedString(String s1, String s2) {
        s1 = s1.toLowerCase();
        s2 = s2.toLowerCase();
        int count = 0;
        int index = s2.indexOf(s1); //indexOf() to search substrings
        while (index != -1) {
            count++;
            index = s2.indexOf(s1, index + s1.length());
        }
        return count;
    }
}
