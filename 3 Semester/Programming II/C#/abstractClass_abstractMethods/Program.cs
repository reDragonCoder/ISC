using System;
using System.Drawing;

namespace AbstractClassAndMethods{
    class Program{
        static void Main(string[] args){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("reDragonCoder");
            Console.ResetColor();
            Console.ForegroundColor=ConsoleColor.DarkBlue;
            Console.WriteLine("This program shows how you can make a general abstract class that has the only purpose of inherit");
            Console.WriteLine("its methods to other classes for them to use it as the case may be, and that class can also have");
            Console.WriteLine("its own concrete methods");
            Console.ResetColor();
            Console.WriteLine();

            //Figure fig=new Figure(); //Error: you cannot make instances of abstract classes

            Square square=new Square(7, "square");
            square.ShowArea(); //Shows the square area

            Triangle triangle=new Triangle(2, 6, "triangle");
            triangle.ShowArea(); //Shows the triangle area
        }
    }
}
