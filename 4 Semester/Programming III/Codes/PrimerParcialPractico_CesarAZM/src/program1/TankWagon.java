package program1;

class TankWagon extends Wagon{
    private static final double PI = 3.14159;
    private final double radio;

    TankWagon(double length, double radio) {
        super(length);
        this.radio = radio;
    }

    @Override public double getVolume() {
        return PI * Math.pow(radio, 2) * length;
    }
}
