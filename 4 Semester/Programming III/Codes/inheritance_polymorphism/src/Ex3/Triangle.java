package Ex3;

public class Triangle extends Shape{
    public double height;
    public double base;
    public double sideA;
    public double sideB;
    public double sideC;
    public Triangle(double height, double base, double sideA, double sideB, double sideC) {
        this.height = height;
        this.base = base;
        this.sideA = sideA;
        this.sideB = sideB;
        this.sideC = sideC;
    }
    @Override
    public double getArea() {
        return this.base*this.height/2;
    }
    public double getPerimeter() {
        return this.sideA+this.sideB+this.sideC;
    }
    public void show(){
        System.out.println("Triangle \n Area: "+this.getArea()+" \nPerimeter: "+this.getPerimeter());
    }
}
