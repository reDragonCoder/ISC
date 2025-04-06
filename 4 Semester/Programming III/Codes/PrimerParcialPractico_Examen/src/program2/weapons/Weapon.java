package program2.weapons;

public abstract class Weapon {
    protected String name;

    public Weapon(String name) {
        this.name = name;
    }

    public String getName() {
        return name;
    }
}
