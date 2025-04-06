package program2.weapons.firearms;

import program2.weapons.Weapon;

public abstract class Firearm extends Weapon {
    private final int capacity;
    private int cartridge;

    public Firearm(String name, int capacity) {
        super(name);
        this.capacity = capacity;
        this.cartridge = capacity;
    }

    public int getCartridge() {
        return cartridge;
    }

    public void shoot(){
        if(cartridge > 0){
            cartridge--;
            System.out.println("Shot fired. Remaining bullets: " + cartridge);
        }else{
            System.out.println("No bullets left in the cartridge");
        }
    }

    public void reload(){
        cartridge = capacity;
        System.out.println("Reloaded weapon. Remaining bullets: " + cartridge);
    }
}
