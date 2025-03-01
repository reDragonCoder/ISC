package Ex1;

public class Executive extends Employee {
    public Executive(String name) {
        super(name);
    }

    @Override
    public String toString() {
        return super.toString() + "-> Executive";
    }
}
