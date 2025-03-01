package Ex5;

public abstract class Animal {
    String name;
    int age;
    public Animal() {}
    public Animal(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void setName(String name) {
        this.name = name;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public String getName(){
        return name;
    }
    public int getAge(){
        return age;
    }
    public abstract void makeSound();
    public abstract void moves();
}
