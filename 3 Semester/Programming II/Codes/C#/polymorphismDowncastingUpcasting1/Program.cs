// Author: reDragonCoder

using System;

public abstract class Character{
    public string Name{get; set;}

    public Character(string name){
        Name=name;
        Console.WriteLine("\nCharacter constructor");
    }

    public abstract void actions();
}

public class Wizard:Character{
    public Wizard():base("Wizard"){Console.WriteLine("Wizard construtor");}

    public override void actions(){
        Console.WriteLine("Wizards can make objects appear or disappear, cause levitations, divine thoughts, cast powerful spells.");
    }

    public void CastSpell(string spell){
        Console.WriteLine($"The Wizard casts the spell: {spell}.");
    }
}

public class Warrior:Character{
    public Warrior():base("Warrior"){Console.WriteLine("Warrior constructor");}

    public override void actions(){
        Console.WriteLine("Warriors combine strength, leadership and extensive knowledge of weapons and armor");
    }

    public void UseShield(){
        Console.WriteLine("The Warrior uses his shield to block the attack.");
    }
}

public class Program{
    public static void Main(){
        Console.WriteLine("-----------------------------");
        Character Character1=new Wizard();  //Polymorphism
        Console.WriteLine("In me lives a: "+Character1.Name); //Father attribute
        Character1.actions(); //overridden method in Wizard
        //Character1.CastSpell(); //Wizard method

        //downcasting
        Wizard Wizard=(Wizard)Character1; //This line is a downcasting
        Wizard.CastSpell("Alohomora");
        

        Console.WriteLine("-----------------------------");
        
        Character Character2=new Warrior(); //Polymorphism
        Console.WriteLine("In me lives a: "+Character2.Name); //Father attribute
        Character2.actions(); //overridden method in Warrior
        //Character2.UseShield();  //Warrior method

        //downcasting
        Warrior Warrior=(Warrior)Character2; //This line is a downcasting
        Warrior.UseShield();

        Console.WriteLine("-----------------------------");

        //upCasting
        Warrior g=new Warrior();
        Character Character3;
        Character3=g; //This line is an upcasting
        Character3.actions(); //overridden method in Warrior
        Console.WriteLine("In me lives a: "+Character3.Name); //Father attribute

         Console.WriteLine("-----------------------------");    
         Console.WriteLine("-- POLYMORPHIC ARRAY --");    
            
        // Creating a Character Array
        Character[] team=new Character[5];
        team[0]=new Wizard();
        team[1]=new Warrior();
        team[2]=new Wizard();
        team[3]=new Wizard();
        team[4]=new Warrior();
         
        for(int i=0; i<team.Length; i++){
            Console.WriteLine("\n Character #"+(i+1));
            Console.WriteLine("In me lives a: "+team[i].Name);//Father attribute

            // Downcasting to access specific subclass methods
            if(team[i] is Wizard wizard){   //option #1 the variable to use (wizard) within the parentheses of the if
                wizard.CastSpell("lightning storm");
            }
            else if(team[i] is Warrior ){   //option #2 the declaration of the variable to use (warrior)
                Warrior warrior=(Warrior)team[i]; 
                warrior.UseShield();
            }
            Console.WriteLine("-----------------------------");    
        }
    }
}
