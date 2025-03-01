package program2.characters;
import program2.powers.IHealingPower;
import program2.powers.Power;

public class Wizard extends Character implements IHealingPower {
    private final Power power;
    private int numofCastedSpells;

    public Wizard(String name, Power power) {
        super(name, 100);
        this.power = power;
        this.numofCastedSpells = 0;
    }

    public Power getPower() {
        return power;
    }

    public String getName(){
        return super.getName();
    }

    public int getEnergy(){
        return super.getEnergy();
    }

    public String castSpell() {
        if(getEnergy() < 2){
            return  getName() + " has no more energy to cast spells";
        }
        consumeEnergy(2);
        numofCastedSpells++;

        return getName() + " uses " + power.getName() +
                ": " + power.usePower() + "\nRemaining energy: " +
                getEnergy() + "\n";
    }

    public void heal(){
        if(numofCastedSpells >= 3) {
            int restoredEnergy = Math.min(3, getInitialEnergy() - getEnergy());
            if(getInitialEnergy() + restoredEnergy > 100.0){
                setEnergy(100);
            }else{
                setEnergy(getInitialEnergy() + restoredEnergy);
            }

            numofCastedSpells = 0;

            System.out.println(getName() + " healed " + getEnergy() + " in energy units");
            System.out.println("Remaining energy: " + getEnergy() + "\n");
        }else{
            System.out.println(getName() + " cannot yet use the healing power. " +
                    "Spells performed: " + numofCastedSpells + "/3\n");
        }
    }

    @Override
    public void consumeEnergy(int wastedEnergy) {
        int newEnergy = getEnergy() - wastedEnergy;
        setEnergy(Math.max(newEnergy, 0));
    }

}
