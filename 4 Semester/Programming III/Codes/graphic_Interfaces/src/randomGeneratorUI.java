import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;
import java.util.Random;

public class randomGeneratorUI {
    private JTextField randomSeed_TextField;
    private JButton generateButton;
    private JTextField randomList_TextField;
    private JTextField sortedList_TextField;
    private JPanel panelMain;

    public randomGeneratorUI() {
        generateButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                generateNumbers();
            }
        });
        randomSeed_TextField.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                generateNumbers();
            }
        });
    }

    private void generateNumbers(){
        try{
            Random r;
            List<Integer> list=new ArrayList<>();
            int n= Integer.parseInt(randomSeed_TextField.getText());
            while(n>0){
                r=new Random(n);
                list.add(r.nextInt(n));
                n--;
            }
            StringBuilder result=new StringBuilder();
            for(Integer i:list){
                result.append(i).append(" ");
            }
            randomList_TextField.setText(result.toString());

            Collections.sort(list);
            StringBuilder sorted=new StringBuilder();
            for(Integer i:list){
                sorted.append(i).append(" ");
            }
            sortedList_TextField.setText(sorted.toString());
        }catch(NumberFormatException ex){
            JOptionPane.showMessageDialog(null, "Enter a valid number!", "Error", JOptionPane.ERROR_MESSAGE);
        }
    }

    public JPanel getPanelMain(){
        return panelMain;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Random Generator");
        frame.setContentPane(new randomGeneratorUI().getPanelMain());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }

}
