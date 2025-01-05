// Author: reDragonCoder

using System;

class Program{
    static void Main(string[] args){
        // creating objects
        Hero ironman=new Ironman("Iron Man", 100, "Mark L Suit");
        Hero batman=new Batman("Batman", 90, "Gotham");
        Hero spiderman=new Spiderman("Spider Man", 85, "Synthetic Webbing");

        //creating a polymorphic Heroe array
        Hero[] heroes=new Hero[] {ironman, batman, spiderman};

        // printing heroes using foreach
        Console.WriteLine("\nUsing foreach to display heroes: ");
        PrintingForEach(heroes);

        // printing heroes using traditional for
        Console.WriteLine("\nUsing for loop to display heroes: ");
        PrintingFor(heroes);

        // polymorphism and downcasting
        Console.WriteLine("\nDemostrating polymorphism and downcasting: ");
    }

    // printing method
    static void PrintingForEach(Hero[] heroes){
        foreach(var hero in heroes){
            hero.DisplayHeroInfo();
            Console.WriteLine("----------------------");
        }
    }

    static void PrintingFor(Hero[] heroes){
        for(int i=0; i<heroes.Length; i++){
            heroes[i].DisplayHeroInfo();
            Console.WriteLine("----------------------");
        }
    }

    // polymorphism and downcasting
    static void PolymprphismExample(Hero hero){
        hero.UsePower();
        if(hero is Ironman){
            Ironman ironmanHero=(Ironman)hero;
            ironmanHero.SaveTheWorld();
        }else if(hero is Batman){
            Batman batmanHero=(Batman)hero;
            batmanHero.GatherIntel();
        }else if(hero is Spiderman){
            Spiderman spidermanHero=(Spiderman)hero;
            spidermanHero.ProtectNewYork();
        }
    }
} 
