package program2.powers.darkPowers;

public class VoidRift extends DarkPower {
    public VoidRift() {
        super("Void Rift");
    }

    @Override
    public String usePower() {
        return getName() + " open a rift into the void, wreaking havoc around him/her\n";
    }
}
