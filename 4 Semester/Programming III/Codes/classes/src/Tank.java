// Exercise 1 - Author: reDragonCoder

import javax.swing.*;

public class Tank {
    public static double capacity = 5000.0;
    public static double content;

    public Tank() {
        content = 0;
    }

    public double getContent(){
        return content;
    }

    public void add(double amount){
        if(content + amount > capacity){
            JOptionPane.showMessageDialog(null, "Tank Capacity Exceeded", "Error", JOptionPane.ERROR_MESSAGE);
        }else{
            content += amount;
        }
    }

    public void takeOut(double amount){
        if(content - amount < 0){
            JOptionPane.showMessageDialog(null, "The Tank Does Not Have That Much Content", "Error", JOptionPane.ERROR_MESSAGE);
        }else{
            content -= amount;
        }
    }

    public void takeOutHalf(){
        if(content!=0){
            content = content / 2;
        }
    }
}

class FirstMain{
    public static void main(String[] args) {
        Tank t = new Tank();
        t.add(100.0);
        while(t.getContent()>=1.0)
            t.takeOutHalf();
        JOptionPane.showMessageDialog(null, "The final content is: "+t.getContent() + "\n");
    }
}
