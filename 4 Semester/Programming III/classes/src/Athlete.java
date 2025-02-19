// Exercise 6 - Cesar Andres Zuleta Malanco

import javax.swing.*;

public class Athlete {
    private final String name;
    private final int number;
    private final String nationality;
    private final float time;

    Athlete(String name, int number, String nationality, float time) {
        this.name = name;
        this.number = number;
        this.nationality = nationality;
        this.time = time;
    }

    public String getName() {
        return name;
    }

    public int getNumber() {
        return number;
    }

    public float getTime() {
        return time;
    }

    public void showData(){
        JOptionPane.showMessageDialog(null,
                "Name: " + name + "\n" +
                        "Number: " + number + "\n" +
                        "Nationality: " + nationality + "\n" +
                        "Time: " + time);
    }

}

class Race{
    private final float distance;
    private final int participants;
    private Athlete[] competitors;
    private int index;

    Race(float distance, int participants){
        this.distance = distance;
        this.participants = participants;
        this.index = 0;
        this.competitors = new Athlete[participants];
    }

    public int athletesNum(){
        return participants;
    }

    public float totalDistance() {
        return distance;
    }

    public void addAthlete(){
        if(index >= participants) {
            JOptionPane.showMessageDialog(null, "You can't add more athletes",
                    "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }

        Athlete athleteAux;
        String nameAux, nationalityAux;
        int numberAux = 0;
        float timeAux = 0.0f;

        nameAux = JOptionPane.showInputDialog(null, "Enter the athlete name: ");
        nationalityAux = JOptionPane.showInputDialog(null, "Enter the athlete nationality: ");

        // Get athlete number with validation
        boolean validInput = false;
        while (!validInput) {
            try {
                numberAux = Integer.parseInt(JOptionPane.showInputDialog(null, "Enter the athlete number: "));
                if (numberAux <= 0) throw new NumberFormatException();
                validInput = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Please enter a valid positive integer for the athlete number.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            }
        }

        // Get athlete time with validation
        validInput = false;
        while (!validInput) {
            try {
                timeAux = Float.parseFloat(JOptionPane.showInputDialog(null, "Enter the athlete time (minutes): "));
                if (timeAux <= 0) throw new NumberFormatException();
                validInput = true;
            } catch (NumberFormatException e) {
                JOptionPane.showMessageDialog(null, "Please enter a valid positive number for the athlete time.", "Invalid Input", JOptionPane.ERROR_MESSAGE);
            }
        }

        athleteAux = new Athlete(nameAux, numberAux, nationalityAux, timeAux);
        competitors[index] = athleteAux;
        JOptionPane.showMessageDialog(null, "Athlete " + nameAux + " has been added to the list!",
                "Athlete Added", JOptionPane.INFORMATION_MESSAGE);
        index++;
    }

    public void raceWinner(){
        if(index == 0) {
            JOptionPane.showMessageDialog(null, "There are no athletes in the race",
                    "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        float bestTime = Float.MAX_VALUE;
        int numWinner = -1;

        for(int i = 0; i < index; i++){
            Athlete athlete = competitors[i];
            if(athlete != null && athlete.getTime() < bestTime){
                bestTime = athlete.getTime();
                numWinner = i;
            }
        }

        if(numWinner != -1){
            JOptionPane.showMessageDialog(null, "The race winner is athlete #" + competitors[numWinner].getNumber() + "!\n");
            competitors[numWinner].showData();
        }else{
            JOptionPane.showMessageDialog(null, "There is no winner for the race.");
        }
    }
}

class Main{
    public static void main(String[] args) {
        Race race = new Race(10, 3);
        JOptionPane.showMessageDialog(null, "Race details\n" +
                "Participants: " + race.athletesNum() + "\n" +
                "Distance: " + race.totalDistance() + " km");
        for(int i = 0; i < race.athletesNum(); i++){
            race.addAthlete();
        }
        race.raceWinner();
    }
}
