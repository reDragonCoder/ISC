package Ex2;

import Ex1.Employee;

public class PassengerAirplane extends Airplane {
    private int weight;
    private double timeEstimated;
    public PassengerAirplane(String airplaneName, String destination, int weight, double timeEstimated) {
        super(airplaneName, destination);
        this.weight = weight;
        this.timeEstimated = timeEstimated;
    }
    public int getWeight() {
        return weight;
    }
    public double getTimeEstimated() {
        return timeEstimated;
    }
    public void setWeight(int weight) {
        this.weight = weight;
    }
    public void setTimeEstimated(float timeEstimated) {
        this.timeEstimated = timeEstimated;
    }
    @Override
    public void print() {
        super.print();
        System.out.println("Current weight: " + weight);
        System.out.println("Current estimated time: " + timeEstimated);
    }
}
