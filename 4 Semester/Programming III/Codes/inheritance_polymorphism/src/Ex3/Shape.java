package Ex3;

public abstract class Shape {
    protected double area;
    protected double perimeter;
    public Shape() {
        this.area = 0;
    }
    // show the area and the perimeter of all the shapes
    public abstract double getArea();
    public abstract double getPerimeter();
    // show the shapes' data
    public abstract void show();
    public boolean  greaterArea(Shape other) {
        return this.area > other.getArea();
    }
    public boolean  greaterPerimeter(Shape other) {
        return this.perimeter > other.getPerimeter();
    }
}
