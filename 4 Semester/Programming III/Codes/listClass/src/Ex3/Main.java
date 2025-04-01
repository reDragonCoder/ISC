package Ex3;

import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {
        ArrayList<Shape> shapes = new ArrayList<>();

        shapes.add(new Rectangle(4, 5));
        shapes.add(new Circle(3));
        shapes.add(new Triangle(3, 4));

        Shape greatestArea = shapes.getFirst();
        Shape greatestPerimeter = shapes.getFirst();

        for (Shape shape : shapes) {
            if(shape.getArea() > greatestArea.getArea()){
                greatestArea = shape;
            }
            if(shape.getPerimeter() > greatestPerimeter.getPerimeter()){
                greatestPerimeter = shape;
            }
        }

        System.out.println("Shape with the greatest area: ");
        greatestArea.show();

        System.out.println("Shape with the greatest perimeter: ");
        greatestPerimeter.show();
    }
}
