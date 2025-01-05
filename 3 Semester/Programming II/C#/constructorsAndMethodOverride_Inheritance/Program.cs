using System;

namespace InheritanceAnimals{
    class Program{
        static void Main(){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("reDragonCoder");
            Console.ResetColor();
            Console.ForegroundColor=ConsoleColor.DarkBlue;
            Console.WriteLine("This program shows how the derivate classes reuse the constructor and methods of the");
            Console.WriteLine("base class and its superior derivative, depending on the case");
            Console.WriteLine("This is a sample of inheritance in C#");
            Console.ResetColor();
            Console.WriteLine();

            //Creating an object of the Dog class
            Dog myDog=new Dog("Lukitas", 3, true, "O+", "Husky", 7.6);
            myDog.ShowData(); //Showing attributes
        }
    }
}




