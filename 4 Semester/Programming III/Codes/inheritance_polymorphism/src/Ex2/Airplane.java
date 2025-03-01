package Ex2;

public class Airplane {
    private String name;
    private String destination;
    Airplane() {}
    Airplane(String name, String destination) {
        this.name = name;
        this.destination = destination;
    }
    public String getName() {
        return name;
    }
    public String getDestination() {
        return destination;
    }
    public void setDestination(String destination) {
        this.destination = destination;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void print() {
        System.out.println("Flight name: " + name);
        System.out.println("Flight destination: " + destination);
    }
}
