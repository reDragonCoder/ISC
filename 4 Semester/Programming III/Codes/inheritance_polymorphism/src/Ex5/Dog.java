package Ex5;

public class Dog extends Animal{
    public String breed;
    public Dog() {}
    public Dog(String name, int age,String breed){
        super(name, age);
        this.breed = breed;
    }
    @Override
    public void makeSound() {
        System.out.println("Woof woof");
    }
    public void moves(){
        System.out.println("The dog is moving");
    }
}
