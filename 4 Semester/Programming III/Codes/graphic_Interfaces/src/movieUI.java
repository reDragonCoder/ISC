import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.List;

public class movieUI {
    private JPanel panelMain;
    private JTextField movie_textField;
    private JButton addButton;
    private JComboBox movies_comboBox;
    private List<String> list = new ArrayList<String>();

    public movieUI() {
        addButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                addMovie();
            }
        });
    }

    private void addMovie() {
        String movie = movie_textField.getText();
        list.add(movie);
        movies_comboBox.setModel(new DefaultComboBoxModel(list.toArray()));
    }

    public JPanel getPanelMain(){
        return panelMain;
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Movies");
        frame.setContentPane(new movieUI().getPanelMain());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.pack();
        frame.setLocationRelativeTo(null);
        frame.setVisible(true);
    }
}
