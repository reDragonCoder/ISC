import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;

public class numberGeneratorUI {
    private JSpinner spinner1;
    private JSpinner spinner2;
    private JTextField textField1;
    private JButton generateButton;
    private JPanel panelMain;

    public numberGeneratorUI() {
        generateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                generateNumber();
            }
        });
    }

    private void generateNumber(){
        int num1 = (Integer) spinner1.getValue();
        int num2 = (Integer) spinner2.getValue();
        Random rand = new Random();
        int upperBound;
        int lowerBound;

        if(num1 > num2){
            upperBound = num1;
            lowerBound = num2;
        }else{
            upperBound = num2;
            lowerBound = num1;
        }
        int randomNumber = rand.nextInt(upperBound - lowerBound + 1) + lowerBound;
        textField1.setText(String.valueOf(randomNumber));
    }

    public JPanel getPanelMain(){
        return panelMain;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Number Generator");
        frame.setContentPane(new numberGeneratorUI().getPanelMain());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
