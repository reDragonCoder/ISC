package Ex5;

public class Canary extends Animal  implements IFlying{
    public String color;
    public Canary() {}
    public Canary(String name, int age,String color) {
        super(name, age);
        this.color = color;
    }
    @Override
    public void makeSound() {
        System.out.println("Twee Twee Twee Twee");
    }
    public void moves() {
        System.out.println("The canary walks forward");
    }
    public void glides() {
        System.out.println("The canary glides gracefully");
    }
}
