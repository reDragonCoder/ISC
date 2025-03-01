package Ex5;

public class Main5 {
    public static void main(String[] args) {
        Animal [] zoo = new Animal[2];
        zoo[0] = new Dog("Apolo", 6, "Samoyed");
        zoo[1] = new Canary("Mimitos", 10, "Blue");
        for (Animal animal : zoo) {
            animal.makeSound();
            animal.moves();
            name(animal);
            flight(animal);
        }
    }

    static void name(Animal animal) {
        System.out.println(animal.getName());
    }

    static void flight(Animal animal) {
        if (animal instanceof IFlying) {
            ((IFlying) animal).glides();
        }
    }
}
