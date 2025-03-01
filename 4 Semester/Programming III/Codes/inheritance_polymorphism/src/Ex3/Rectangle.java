package Ex3;

public class Rectangle extends Shape {
    public int width;
    public int height;
    public Rectangle(int width, int height) {
        this.width = width;
    }
    @Override
    public double getArea() {
        return width * height;
    }
    public double getPerimeter() {
        return 2 * width * height;
    }
    public void show() {
        System.out.println("Rectangle \n Area:"+ this.getArea()+"\n Perimeter:"+ this.getPerimeter());
    }
}
