package program1;

import java.util.ArrayList;

class Train{
    private final ArrayList<Wagon> wagons;
    private final int maxWagons;

    Train(int maxWagons) {
        this.wagons = new ArrayList<>();
        this.maxWagons = maxWagons;
    }

    boolean addWagon(Wagon w){
        if(wagons.size() < maxWagons){
            wagons.add(w);
            return true;
        }
        return false;
    }

    public double totalVolume(){
        double totalVolume = 0;

        for(Wagon w : wagons){
            totalVolume += w.getVolume();
        }

        return totalVolume;
    }
}
