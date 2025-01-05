using System;

namespace InheritanceEmployees{
    class Program{
        static void Main(string[] args){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("reDragonCoder");
            Console.ResetColor();
            Console.ForegroundColor=ConsoleColor.DarkBlue;
            Console.WriteLine("This program shows how the derivate classes can modify the base class methods function using -method override-.");
            Console.WriteLine("This is a clear example of inheritance & polymorphism");
            Console.ResetColor();
            Console.WriteLine();

            //Instance of the Employee class
            Employee employee=new Employee();
            Console.WriteLine($"Employee salary: {employee.CalculateSalary(1000)}");
            Console.WriteLine();

            //Instance of the FullTimeEmployee class
            FullTimeEmployee ftEmployee=new FullTimeEmployee();
            Console.WriteLine($"Full time employee salary: {ftEmployee.CalculateSalary(1000)}");
            Console.WriteLine();

            //Instance of the EmployeeManager class
            EmployeeManager manager=new EmployeeManager();
            Console.WriteLine($"Manager salary: {manager.CalculateSalary(1000)}");
            Console.WriteLine();
        }
    }
}