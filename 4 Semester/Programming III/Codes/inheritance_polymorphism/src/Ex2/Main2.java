package Ex2;

public class Main2 {
    public static void main(String[] args) {
        PassengerAirplane pa = new PassengerAirplane("AZ19B2", "LONDON", 2400, 270.5);
        HydrationAirplane ha = new HydrationAirplane("BT3533P8", "AMSTERDAM", 500);
        pa.print();
        ha.print();
        ha.unloadWater(300);
        ha.print();
        ha.unloadWater();
        ha.print();
        Airplane[] airplane = new Airplane[2];
        airplane[0] = pa;
        airplane[1] = ha;
        for(Airplane a : airplane) {
            if(a instanceof HydrationAirplane) {
                System.out.println("The flight "+a.getName()+"is a HydrationAirplane");
            }
        }
    }
}
