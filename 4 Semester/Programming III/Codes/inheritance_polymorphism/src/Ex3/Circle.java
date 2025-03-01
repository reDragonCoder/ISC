package Ex3;

public class Circle extends Shape {
    public double radius;
    public Circle(double radius) {
        this.radius = radius;
    }
    @Override
    public double getArea() {
        return Math.PI * radius * radius;
    }
    public double getPerimeter() {
        return 2 * Math.PI * radius;
    }
    public void show() {
        System.out.println("Circle \n Area: "+ this.getArea() + "\n Perimeter: "+ this.getPerimeter());
    }
}
