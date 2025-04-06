package program2.weapons.bladedWeapons;

import program2.weapons.Weapon;

public abstract class BladedWeapon extends Weapon {
    private double cuttingEdge;
    private final double usePercentage;

    public BladedWeapon(String name, double usePercentage) {
        super(name);
        this.usePercentage = usePercentage;
        this.cuttingEdge = 100.0;
    }

    public double getCuttingEdge() {
        return cuttingEdge;
    }

    public void useWeapon() {
        cuttingEdge -= cuttingEdge * (usePercentage / 100.0);

        if (cuttingEdge < 0) {
            cuttingEdge = 0;
        }
    }

    public boolean lowCuttingEdge(){
        return cuttingEdge < 30.0;
    }

    public void sharpen(){
        cuttingEdge = 100.0;
    }
}
