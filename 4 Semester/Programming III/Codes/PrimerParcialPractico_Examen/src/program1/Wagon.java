package program1;

public abstract class Wagon {
    protected final double length;

    Wagon(double length) {
        this.length = length;
    }

    public abstract double getVolume();
}