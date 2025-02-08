import javax.swing.*;

public class Ex5 {
    public static void main(String[] args) {
        String orgText = JOptionPane.showInputDialog(null, "Enter your text: ", "Input", JOptionPane.PLAIN_MESSAGE);
        String updatedText = transformText(orgText);
        JOptionPane.showMessageDialog(null, "Updated text: " + updatedText, "Output", JOptionPane.PLAIN_MESSAGE);
    }

    public static String transformText(String orgText) {
        char[] chText = orgText.toCharArray();

        for(int i = 0; i < chText.length; i++) {
            if(Character.isUpperCase(chText[i])) {
                chText[i] = Character.toLowerCase(chText[i]);
            }else if(Character.isLowerCase(chText[i])) {
                chText[i] = Character.toUpperCase(chText[i]);
            }
        }

        StringBuilder newText = new StringBuilder();

        for(int i = chText.length-1; i >= 0; i--) {
            newText.append(chText[i]);
        }

        return newText.toString();
    }
}