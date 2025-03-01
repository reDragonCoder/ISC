package program2.powers.lightPowers;

public class BlindingFlash extends LightPower {
    public BlindingFlash() {
        super("Blinding Flash");
    }
    @Override
    public String usePower(){
        return getName() + " emit a blinding flash that disorients enemies\n";
    }
}
