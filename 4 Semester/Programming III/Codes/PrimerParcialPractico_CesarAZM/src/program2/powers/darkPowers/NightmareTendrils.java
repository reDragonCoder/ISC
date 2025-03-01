package program2.powers.darkPowers;

public class NightmareTendrils extends DarkPower{
    public NightmareTendrils() {
        super("Nightmare Tendrils");
    }

    @Override
    public String usePower() {
        return getName() + " summon nightmare tentacles that ensnare enemies\n";
    }
}
