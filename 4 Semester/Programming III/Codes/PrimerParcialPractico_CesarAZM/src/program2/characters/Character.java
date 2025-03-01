package program2.characters;

public abstract class Character {
    private final String name;
    private int energy;
    private final int initialEnergy;

    public Character(String name, int initialEnergy) {
        this.name = name;
        this.initialEnergy = initialEnergy;
        this.energy = initialEnergy;
    }

    int getEnergy(){
        return energy;
    }
    public void setEnergy(int energy){
        this.energy = energy;
    }

    public int getInitialEnergy(){
        return initialEnergy;
    }

    public String getName(){
        return name;
    }

    public void feed(int givenEnergy) {
        if(energy + givenEnergy > initialEnergy) {
            energy = initialEnergy;
        }else{
            energy += givenEnergy;
        }
    }

    @Override
    public String toString() {
        return "Character [name=" + name + ", energy=" + energy + "]";
    }

    public abstract void consumeEnergy(int wastedEnergy);
}

