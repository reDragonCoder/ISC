package Ex1;

public class Operator extends Employee{
    public Operator(String name) {
        super(name);
    }

    @Override
    public String toString() {
        return super.toString() + "-> Operator";
    }
}
