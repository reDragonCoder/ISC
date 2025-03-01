package Ex1;

public class Technician extends Operator {
    public Technician(String name) {
        super(name);
    }

    @Override
    public String toString() {
        return super.toString() + "-> Technician";
    }
}
