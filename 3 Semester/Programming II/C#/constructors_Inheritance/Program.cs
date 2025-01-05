using System;

namespace inheritanceConstructors{
    class Program{
        static void Main(string[] args){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("reDragonCoder");
            Console.ResetColor();
            Console.ForegroundColor=ConsoleColor.DarkBlue;
            Console.WriteLine("This program shows the derivate classes managment, specifically talking about its constructors");
            Console.WriteLine("and how they have a chain reaction with superior level classes");
            Console.ResetColor();
            Console.WriteLine();

            //Create an instance of the Manager class
            {
            Manager Manager=new Manager("Jhon Doe", "General Manager", "Sales");
            
            Console.WriteLine();
            Console.WriteLine(Manager.Name);
            Console.WriteLine(Manager.Position);
            Console.WriteLine(Manager.Department);
            }
        }
    }
}