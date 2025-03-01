package program2.characters;

import program2.weapons.Weapon;
import program2.weapons.bladedWeapons.BladedWeapon;
import program2.weapons.firearms.Firearm;

public class Warrior extends Character {
    private final String type;
    private final Weapon weapon;

    public Warrior(String name, int initialEnergy, String type, Weapon weapon) {
        super(name, initialEnergy);
        this.type = type;
        this.weapon = weapon;
    }

    public String getName(){
        return super.getName();
    }

    public int getInitialEnergy(){
        return super.getInitialEnergy();
    }

    public int getEnergy(){
        return super.getEnergy();
    }

    public String getType() {
        return type;
    }

    public Weapon getWeapon(){
        return weapon;
    }

    public String fight(int wastedEnergy){
        int availableEnergy = getEnergy();
        if(wastedEnergy > availableEnergy){
            wastedEnergy = availableEnergy;
        }

        consumeEnergy(wastedEnergy);

        String message;

        if(weapon instanceof Firearm firearm){
            if(firearm.getCartridge() > 0){
                firearm.shoot();
                message = "Weapon: " + firearm.getName() + "\n" +
                        "Remaining bullets: " + firearm.getCartridge() + "\n" +
                        "Attack energy: " + wastedEnergy + "\n" +
                        "Remaining energy: " + getEnergy() + "\n";
            }else{
                System.out.println("The cartridge is empty! You need to reload the gun");
                firearm.reload();
                message = "You have reloaded your " + firearm.getName() + "!" + "\n" +
                        "Available bullets: " + firearm.getCartridge() + "\n";
            }
        }else{
            BladedWeapon bladedWeapon = (BladedWeapon) weapon;
            bladedWeapon.useWeapon();

            message = "Weapon: " + weapon.getName() + "\n"
                    + "Remaining cutting edge: " + String.format("%.2f", bladedWeapon.getCuttingEdge()) + "%" + "\n"
                    + "Attack energy: " + wastedEnergy
                    + "\n" + "Remaining energy: " + getEnergy();
            if(bladedWeapon.lowCuttingEdge()){
                message += "\n Warning! Your weapon " + bladedWeapon.getName() + " cutting edge is below 30%";
            }
        }

        return message;
    }

    @Override
    public void consumeEnergy(int wastedEnergy) {
        int availableEnergy = getEnergy() - wastedEnergy;
        setEnergy(Math.max(availableEnergy, 0));
    }
}
