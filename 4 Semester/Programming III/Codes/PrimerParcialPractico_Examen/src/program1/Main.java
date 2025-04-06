package program1;

public class Main{
    public static void main(String[] args) {
        Wagon wagon1 = new BoxWagon(10,3,7);
        Wagon wagon2 = new BoxWagon(11,2, 6);
        Wagon wagon3 = new TankWagon(10,20);
        Wagon wagon4 = new TankWagon(5,9);
        Wagon wagon5 = new TankWagon(6,8); /* for error testcase*/

        Train t1 = new Train(4);
        if(t1.addWagon(wagon1)){
            System.out.println("Wagon 1 added successfully");
        }else{
            System.out.println("Wagon 1 not added - Error: max. capacity exceeded");
        }
        if(t1.addWagon(wagon2)){
            System.out.println("Wagon 2 added successfully");
        }else{
            System.out.println("Wagon 3 not added - Error: max. capacity exceeded");
        }
        if(t1.addWagon(wagon3)){
            System.out.println("Wagon 3 added successfully");
        }else{
            System.out.println("Wagon 3 not added - Error: max. capacity exceeded");
        }
        if(t1.addWagon(wagon4)){
            System.out.println("Wagon 4 added successfully");
        }else{
            System.out.println("Wagon 4 not added - Error: max. capacity exceeded");
        }

        /* Error testcase */
        if(t1.addWagon(wagon5)){
            System.out.println("Wagon 5 added successfully");
        }else{
            System.out.println("Wagon 5 not added - Error: max. capacity exceeded");
        }

        /* Train total volume */
        System.out.println(t1.totalVolume());
    }
}