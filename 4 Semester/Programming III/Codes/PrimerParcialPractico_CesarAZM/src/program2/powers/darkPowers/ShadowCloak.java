package program2.powers.darkPowers;

public class ShadowCloak extends DarkPower{
    public ShadowCloak() {
        super("Shadow Cloak");
    }

    @Override
    public String usePower() {
        return getName() + " cloak himself/herself in shadows, becoming invisible\n";
    }
}
