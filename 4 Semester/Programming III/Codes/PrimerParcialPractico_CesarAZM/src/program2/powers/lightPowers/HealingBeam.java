package program2.powers.lightPowers;

public class HealingBeam extends LightPower {
    public HealingBeam() {
        super("Healing Beam");
    }

    @Override
    public String usePower() {
        return getName() + " channel a healing ray that restores vitality\n";
    }
}
