package Ex3;

public abstract class Shape {
    protected double area;

    public Shape(){
        this.area = 0;
    }

    public abstract double getArea();

    public abstract double getPerimeter();

    public abstract void show();

    public boolean greaterArea(Shape s){
        return this.getArea() > s.getArea();
    }

    public boolean greaterPerimeter(Shape s){
        return this.getArea() > s.getPerimeter();
    }
}
