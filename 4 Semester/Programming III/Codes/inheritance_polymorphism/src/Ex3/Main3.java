package Ex3;

public class Main3 {
    public static void main(String[] args) {
        int i = 1, g=0, p=0;
        Shape[] shapes = new Shape[6];
        shapes[0] = new Circle(5);
        shapes[1] = new Rectangle(4, 5);
        shapes[2] = new Triangle(13.4,11,15,14,11);
        shapes [3] = new Triangle(7.8,5.5,8,7,5.5);
        shapes[4] = new Rectangle(9,13);
        shapes[5] = new Circle(4.5);
        for(Shape shape : shapes){
            if(shape.greaterArea(shapes[i])){
                g=i-1;
            } else if (shape.greaterPerimeter(shapes[i])) {
                p=i-1;
            }
            if(i==5){
                i=0;
            } else{
                i++;
            }
        }
        System.out.println("The shape with the greatest area is: ");
        shapes[g].show();
        System.out.println("The shape with the greatest perimeter is: ");
        shapes[p].show();
    }
}
