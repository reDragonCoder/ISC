using System;
using System.Data.Common;

namespace AbstractClassAndMethod{
    class Program{
        static void Main(string[] args){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("reDragonCoder");
            Console.ResetColor();
            Console.ForegroundColor=ConsoleColor.DarkBlue;
            Console.WriteLine("This program shows how you can make a general abstract class that has the only purpose of inherit");
            Console.WriteLine("its methods to other classes for them to use it as the case may be");
            Console.ResetColor();
            Console.WriteLine();

            Dog dog=new Dog();
            dog.MakeSound(); //Output: Woof Woof!

            Cat cat=new Cat();
            cat.MakeSound(); //Output Miau miau!
        }
    }
}