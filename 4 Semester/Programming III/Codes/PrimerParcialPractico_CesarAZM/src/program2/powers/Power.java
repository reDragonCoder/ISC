package program2.powers;

public abstract class Power {
    private final String name;

    public Power(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }

    public abstract String usePower();
}
