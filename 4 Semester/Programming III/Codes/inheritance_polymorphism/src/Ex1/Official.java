package Ex1;

public class Official extends Operator {
    public Official(String name) {
        super(name);
    }

    @Override
    public String toString() {
        return super.toString() + "-> Official";
    }
}
