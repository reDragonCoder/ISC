import javax.swing.*;

public class Ex2 {
    public static void main(String[] args) {
        String s = JOptionPane.showInputDialog(
                null, "Enter 'n' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
        int n = Integer.parseInt(s);

        while(n<1) {
            JOptionPane.showMessageDialog(null, "Enter positive number!", "Error", JOptionPane.ERROR_MESSAGE);

            s = JOptionPane.showInputDialog(null, "Enter 'n' value: ", "Input", JOptionPane.PLAIN_MESSAGE);
            n = Integer.parseInt(s);
        }

        JTextArea text = new JTextArea(10, 20);
        text.setEditable(false);
        text.setText("Ullman's Sequence for " + n + ":\n\n");

        text.append(n + " ");
        while(n>1){
            if (n % 2 == 0) {
                n /= 2;
            } else {
                n = 3 * n + 1;
            }
            text.append(n + " ");
        }

        JFrame window = new JFrame("Ullman's Sequence");
        window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        window.add(new JScrollPane(text));
        window.pack();
        window.setLocationRelativeTo(null);
        window.setVisible(true);
    }
}
