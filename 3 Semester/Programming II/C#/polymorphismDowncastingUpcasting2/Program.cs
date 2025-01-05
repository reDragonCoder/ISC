using System;
//Polymorphysim, downcasting & upcsting example
 
public class Program{
    public static void Main(){
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("reDragonCoder");
        Console.ResetColor();
        Console.WriteLine();
        
        //********************* LAND VEHICLE DESCENDENT *********************
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- LandVehicle descendent ---");
        Console.ResetColor();

        //motorcycle
        //polymorphism 
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("Motorcycle Polymorphism");
        Console.ResetColor();
        LandVehicle landVehicle1=new Motorcycle("Harley Davidson", "Black", 2);
        Console.WriteLine("The Motorcycle brand is: "+landVehicle1.Brand); //base class attribute
        Console.WriteLine($"The Motorcycle number of wheels is: {landVehicle1.Wheels}"); //derivate class attribute
        landVehicle1.Drive(); //overriden method in Motorcycle
        landVehicle1.CheckFuelLevel(); //overriden method in Motorcycle
        //landVehicle1.DoWheelieTrick(); //the landVehicle1 object cannot access to the Motorcycle concrete method
        Console.WriteLine();

        //downcasting
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("Motorcycle Downcasting");
        Console.ResetColor();
        if(landVehicle1 is Motorcycle motorcycle1){
            motorcycle1.DoWheelieTrick();
        }else if(landVehicle1 is Truck truck1){
            truck1.Load();
        }else if(landVehicle1 is Automobile automobile1){
            automobile1.openTrunk();
        }
        //Motorcycle motorcycle1=(Motorcycle)motorcycle1
        //motorcycle1.DoWheelieTrick();               // is the same as the process shown above
        Console.WriteLine();

        //upcasting
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("Motorcycle Upcasting");
        Console.ResetColor();
        Motorcycle m=new Motorcycle("Harley Davidson", "Black", 2);
        LandVehicle landV;
        landV=m; //this line is an upcasting
        Console.WriteLine("This is a "+landV.Color+" "+landV.Brand+" Motorcycle"); //base class attributes
        m.DoWheelieTrick();
        landV.Drive();
        landV.CheckFuelLevel();
        Console.WriteLine();

        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("********************************************\n");
        Console.ResetColor();

        //********************* AQUATIC VEHICLE DESCENDENT *********************
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- AquaticVehicle descendent ---");
        Console.ResetColor();

        //jetski
        //polymorphism 
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("JetSki Polymorphism");
        Console.ResetColor();
        AquaticVehicle aquaticVehicle1=new JetSki("Yamaha", "Red", "Motor");
        Console.WriteLine("The JetSki brand is: "+aquaticVehicle1.Brand); //base class attribute
        Console.WriteLine($"The JetSki navegation type is: {aquaticVehicle1.NavigationType}"); //derivate class attribute
        aquaticVehicle1.Drive(); //overriden method in JetSki
        aquaticVehicle1.Sail(); //overriden method in JetSki
        //aquaticVehicle1.DoJumpTrick(); //the aquaticVehicle1 object cannot access to the JetSki concrete method
        Console.WriteLine();

        //downcasting
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("JetSki Downcasting");
        Console.ResetColor();
        if(aquaticVehicle1 is JetSki jetski1){
            jetski1.DoJumpTrick();
        }else if(aquaticVehicle1 is Boat boat1){
            boat1.Beeping();
        }else if(aquaticVehicle1 is SailBoat sailboat1){
            sailboat1.RaiseAnchor();
        }
        //JetSki jetski1=(JetSki)aquaticVehicle1
        //jetski1.DoJUmpTrick();                // is the same as the process shown above
        Console.WriteLine();

        //upcasting
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("JetSki Upcasting");
        Console.ResetColor();
        JetSki j=new JetSki("Yamaha", "red", "motor");
        AquaticVehicle aquaticV;
        aquaticV=j; //this line is an upcasting
        Console.WriteLine("This is a "+aquaticV.Color+" "+aquaticV.Brand+" Jetski"); //base class attributes
        j.DoJumpTrick();
        aquaticV.Drive();
        aquaticV.Sail();
        Console.WriteLine();

        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("********************************************\n");
        Console.ResetColor();

        //********************* POLYMORPHIC ARRAY *********************
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- Polymorphic Array ---");
        Console.ResetColor();

        Vehicle[] vehicles=new Vehicle[12];
        int opt, cycles=0;
        while(cycles<12){
            Console.WriteLine();
            Console.WriteLine("------- VEHICLES MENU -------");
            Console.WriteLine("1. Automobile");
            Console.WriteLine("2. Truck");
            Console.WriteLine("3. Motorcycle");
            Console.WriteLine("4. Boat");
            Console.WriteLine("5. Jetski");
            Console.WriteLine("6. Sailboat");
            Console.WriteLine("Please enter your option");
            opt=Convert.ToInt32(Console.ReadLine());
            switch(opt){
                case 1:
                    vehicles[cycles]=new Automobile("Lamborghini", "Purple", 4);
                    vehicles[cycles].Drive();
                    break;
                case 2:
                    vehicles[cycles]=new Truck("Chayanne", "White", 4,200);
                    vehicles[cycles].Drive();
                    break;
                case 3:
                    vehicles[cycles]=new Motorcycle("Harly Davidson", "Brown", 2);
                    vehicles[cycles].Drive();
                    break;
                case 4:
                    vehicles[cycles]=new Boat("FisherBoats", "Blue", "Oars");
                    vehicles[cycles].Drive();
                    break;
                case 5:
                    vehicles[cycles]=new JetSki("Yamaha", "Red", "Motor");
                    vehicles[cycles].Drive();
                    break;
                case 6:
                    vehicles[cycles]=new SailBoat("RoyalFields", "Gold", "Sail");
                    vehicles[cycles].Drive();
                    break;
                default:
                    break;
            }
            cycles++;
        }
    }
}