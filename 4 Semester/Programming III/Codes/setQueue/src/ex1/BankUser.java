package ex1;

public class BankUser {
    private final String name;
    private final int age;

    public BankUser(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }
    public int getAge() {
        return age;
    }

    @Override
    public String toString() {
        return "{" + "Name=" + name + ", age=" + age + "}";
    }
}
