package program1;

class BoxWagon extends Wagon{
    private final double height;
    private final double width;

    BoxWagon(double length, double height, double width) {
        super(length);
        this.height = height;
        this.width = width;
    }

    @Override public double getVolume() {
        return width * height * length;
    }
}
