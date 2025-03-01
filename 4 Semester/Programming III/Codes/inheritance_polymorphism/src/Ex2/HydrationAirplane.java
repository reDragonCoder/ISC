package Ex2;

public class HydrationAirplane extends Airplane {
    private int water;
    public HydrationAirplane(String airplaneName, String destination, int amountOfWater ) {
        super(airplaneName, destination);
        this.water = amountOfWater;
    }
    public int getWater() {
        return water;
    }
    public void setWater(int water) {
        this.water = water;
    }
    @Override
    public void print() {
        super.print();
        System.out.println("Current amount of water: " + water);
    }
    public void unloadWater(int amount) {
        this.water -= amount;
    }
    public void unloadWater() {
        this.water = 0;
    }
}
