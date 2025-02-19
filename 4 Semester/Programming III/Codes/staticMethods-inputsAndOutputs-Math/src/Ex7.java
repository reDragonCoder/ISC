import java.util.ArrayList;
import javax.swing.*;

public class Ex7 {
    public static void main(String[] args) {
        String str = JOptionPane.showInputDialog(null, "Enter your string: ", "Input", JOptionPane.PLAIN_MESSAGE);
        ArrayList<String> wordList = processString(str);

        StringBuilder builder = new StringBuilder();
        for (String word : wordList) {
            builder.append(word).append("\n");
        }
        JOptionPane.showMessageDialog(null, builder.toString(), "Output", JOptionPane.PLAIN_MESSAGE);

    }

    public static ArrayList<String> processString(String str) {
        // replaceAll to delete not wanted characters
        //split("\\s+") to divide the string by spaces
        String[] words = str.replaceAll("[^a-zA-Z0-9\\s]", "").split("\\s+");
        ArrayList<String> fwordList = new ArrayList<>();

        for (String word : words) {
            String upperFirstLetter = word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
            int length = word.length();
            fwordList.add(upperFirstLetter + " " + length);
        }

        return fwordList;
    }
}
