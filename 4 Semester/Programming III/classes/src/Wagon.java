// Exercise 3 - Cesar Andres Zuleta Malanco

import javax.swing.*;
import java.util.Arrays;

public class Wagon {
    private final boolean [] seats;
    private boolean firstClass;

    public Wagon(boolean firstClass){
        seats = new boolean[40];
        Arrays.fill(seats, false);

        this.firstClass = firstClass;
    }

    public boolean getSeat(int ind){
        return seats[ind];
    }

    public boolean getFirstClass(){
        return firstClass;
    }

    public void setFirstClass(boolean first){
        firstClass = first;
    }

    public void occupy() {
        double probability = this.firstClass ? 0.1 : 0.4;
        for (int i = 0; i < 40; i++){
            this.seats[i] = Math.random() < probability;
        }
    }

    public int occupiedSeats(){
        int occupied = 0;
        for(int i = 0; i < 40; i++){
            if(seats[i]){
                occupied++;
            }
        }
        return occupied;
    }
}

class Train {
    private final Wagon [] wagons;
    private final int numFirst;
    private final int numSecond;
    public final String departure;
    public String destination;
    private final int priceFirst;
    private final int priceSecond;

    public Train(int numFirst, int numSecond, String dep, String dest, int priceF, int priceS) {
        this.numFirst = numFirst;
        this.numSecond = numSecond;
        this.departure = dep;
        this.destination = dest;
        this.priceFirst = priceF;
        this.priceSecond = priceS;
        this.wagons = new Wagon[numFirst+numSecond];

        for (int i = 0; i < numFirst; i++) {
            wagons[i] = new Wagon(true);
        }
        for (int i = numFirst; i < numFirst + numSecond; i++) {
            wagons[i] = new Wagon(false);
        }
    }

    public Wagon getWagon(int i){
        return wagons[i];
    }

    public void fill() {
        for (Wagon wagon : this.wagons) wagon.occupy();
    }

    public int totalSales(){
        int totalF = 0, totalS = 0;

        totalF += numFirst * priceFirst;
        totalS += numSecond * priceSecond;

        return totalF + totalS;
    }
}

class ThirdMain {
    public static void main(String [] args) {
        /* subsection a */
        Wagon v = new Wagon(false);
        v.occupy();
        StringBuilder seatsInfo = new StringBuilder();
        seatsInfo.append(v.getFirstClass()?"First":"Second"). append(" class wagon: \n");
        for (int i = 0; i<40; i++) {
            if(i<39){
                seatsInfo.append(v.getSeat(i)).append(", ");
            }else {
                seatsInfo.append(v.getSeat(i));
            }
        }
        JOptionPane.showMessageDialog(null, seatsInfo.toString());

        /* subsection b */
        Train t = new Train(4, 7, "Aguascalientes", "Calvillo", 20, 10);
        t.fill();
        JOptionPane.showMessageDialog(null, "Departure: " + t.departure + "\n" + "Destination: "
                + t.destination + "\n" + "Total sales: " + t.totalSales(), "Train Info",
                JOptionPane.INFORMATION_MESSAGE);
    }
}