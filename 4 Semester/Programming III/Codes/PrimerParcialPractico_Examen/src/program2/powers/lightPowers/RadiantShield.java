package program2.powers.lightPowers;

public class RadiantShield extends LightPower {
    public RadiantShield() {
        super("Radiant Shield");
    }

    @Override
    public String usePower() {
        return getName() + " deploys a radiant shield that protects against attacks\n";
    }
}
