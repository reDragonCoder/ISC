import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class conversionUI {
    private JPanel panelMain;
    private JTextField celsiusTextField;
    private JButton fahrenheitButton;
    private JTextField resultTextField;

    public conversionUI() {
        fahrenheitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                conversion();
            }
        });
        celsiusTextField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                conversion();
            }
        });
    }

    private void conversion() {
        try{
            double celsius = Double.parseDouble(celsiusTextField.getText());
            double fahrenheit=celsius*9.0/5.0+32;
            resultTextField.setText(String.valueOf(fahrenheit));
        }catch(NumberFormatException ex){
            JOptionPane.showMessageDialog(null, "Please enter a valid numeric value!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public JPanel getPanelMain(){
        return panelMain;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Conversion");
        frame.setContentPane(new conversionUI().getPanelMain());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
