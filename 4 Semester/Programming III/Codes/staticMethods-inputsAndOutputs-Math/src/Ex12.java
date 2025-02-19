import javax.swing.*;
import java.util.Objects;

public class Ex12 {
    public static void main(String[] args) {
        String s = "";
        while(!Objects.equals(s, "*")){
            s = JOptionPane.showInputDialog(null, "Enter a string or '*' to exit: ", "Input", JOptionPane.PLAIN_MESSAGE);
            if (!Objects.equals(s, "*")) {
                if (isTautogram(s)) {
                    JOptionPane.showMessageDialog(null, "Yes");
                } else {
                    JOptionPane.showMessageDialog(null, "No");
                }
            }
        }
    }

    public static boolean isTautogram(String s){
        s = s.toLowerCase();
        String[] words = s.replaceAll("[^a-zA-Z0-9\\s]", "").split("\\s+");

        if (words.length == 0) {
            return false;
        }

        char firstChar = words[0].charAt(0);
        for (String word : words) {
            if (word.charAt(0) != firstChar) {
                return false;
            }
        }
        return true;
    }
}

