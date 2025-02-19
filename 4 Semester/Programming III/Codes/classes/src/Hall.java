// Exercise 2 - Cesar Andres Zuleta Malanco

import javax.swing.*;

public class Hall {
    private final String name;
    private final int width;
    private final int height;
    private final boolean equipped;

    public Hall(String n, int w, int h, boolean e) {
        name = n;
        width = w;
        height = h;
        equipped = e;
    }

    public String getName() {
        return name;
    }

    public int getWidth() {
        return width;
    }

    public int getHeight() {
        return height;
    }

    public boolean getEquipped() {
        return equipped;
    }

    public int calculateArea() {
        return width * height;
    }

    public int calculateCapacity(){
        double area = calculateArea();
        return (int)Math.round(area / 1.5);
    }

    public double calculateRent(){
        double area = calculateArea();
        if(equipped) {
            return area*45;
        }else{
            return area*32;
        }
    }

    public void showData(){
        double area = calculateArea(), rent = calculateRent();
        int capacity = calculateCapacity();

        if(equipped){
            JOptionPane.showMessageDialog(null, "Hall name: " + name + "\n" +
                    "Surface: " + area + " m^2 (Width: " + width + ", Height: " + height + ")"  + "\n" +
                    "Equipped?: Yes" + "\n" + "Capacity: " + capacity + " people"  + "\n" + "Rent: $" + rent + "\n");
        }else{
            JOptionPane.showMessageDialog(null, "Hall name: " + name + "\n" +
                    "Surface: " + area + " m^2 (Width: " + width + ", Height: " + height + ")"  + "\n" +
                    "Equipped?: No" + "\n" + "Capacity: " + capacity + " people"  + "\n" + "Rent: $" + rent + "\n");
        }

    }
}

class SecondMain{
    public static void main(String [] args) {
        Hall h1 = new Hall("Hall 1", 8,12,true);
        Hall h2 = new Hall("Hall 2", 18,20,false);
        Hall h3 = new Hall("Hall 3", 12,15,true);
        Hall []h = {h1,h2,h3};

        h1.showData();

        int [] events = {200,50,100,150};
        for(int i=0; i<4; i++)
            for(int j=0; j<3; j++)
                if(h[j].calculateCapacity()>=events[i] )
                    JOptionPane.showMessageDialog(null, "The " + h[j].getName() +
                            " has a capacity for " + events[i] + " people\n\n");
    }
}