import javax.swing.*;

public class Ex3 {
    public static void main(String[] args) {
        JOptionPane.showMessageDialog(null, """
                Welcome, here's the key menu:\s
                S: UNIONIZED
                C: TRUST
                D: MANAGER
                E: EXECUTIVE
                """);

        String s = JOptionPane.showInputDialog(
                null, "Enter the category key: ", "Input", JOptionPane.PLAIN_MESSAGE);
        char key = s.charAt(0);
        char updatedKey = Character.toUpperCase(key);

        while(updatedKey!='S' && updatedKey!='C' && updatedKey!='D' && updatedKey!='E') {
            JOptionPane.showMessageDialog(null, "Enter a valid key!", "Error", JOptionPane.ERROR_MESSAGE);

            s = JOptionPane.showInputDialog(
                    null, "Enter the category key: ", "Input", JOptionPane.PLAIN_MESSAGE);
            key = s.charAt(0);
            updatedKey = Character.toUpperCase(key);
        }

        s = JOptionPane.showInputDialog(
                null, "Enter current salary: ", "Input", JOptionPane.PLAIN_MESSAGE);
        double salary = Double.parseDouble(s);

        switch (updatedKey){
            case 'S':
                salary *= 1.2;
                JOptionPane.showMessageDialog(null, "Key: UNIONIZED\n" + "The salary is: $" + salary, "Result", JOptionPane.PLAIN_MESSAGE);
                break;
            case 'C':
                salary *= 1.15;
                JOptionPane.showMessageDialog(null, "Key: TRUST\n" + "The salary is: $" + salary, "Result", JOptionPane.PLAIN_MESSAGE);
                break;
            case 'D':
                salary *= 1.1;
                JOptionPane.showMessageDialog(null, "Key: MANAGER\n" + "The salary is: $" + salary, "Result", JOptionPane.PLAIN_MESSAGE);
                break;
            case 'E':
                salary *= 1.05;
                JOptionPane.showMessageDialog(null, "Key: EXECUTIVE\n" + "The salary is: $" + salary, "Result", JOptionPane.PLAIN_MESSAGE);
                break;
        }
    }

}
