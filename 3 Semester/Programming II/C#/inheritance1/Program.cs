// Author: reDragonCoder

using System;

namespace Inheritance{
    class Program{
        static void Main(string[] args){
            Console.ForegroundColor=ConsoleColor.DarkMagenta;
            Console.WriteLine("Author: reDragonCoder");
            Console.ResetColor();
            Console.WriteLine();
            Person per1=new Person("Jhon", 32, 30500);
            Console.WriteLine(per1.getName());
            Console.WriteLine(per1.getAge());
            Console.WriteLine(per1.Saving);
            Console.WriteLine();
            Console.WriteLine("***************************");
            Console.WriteLine();

            Employee emp1=new Employee(300077, 120000); //id, salary

            //The next line marks an error, you cannot call a protected method
            //from the main
            /*Console.WriteLine(emp1.employeeProtectedMethod());*/

            //The next line marks an error, you cannot call a private method
            /*Console.WriteLine(emp1.employeePrivateMethod());*/

            Console.WriteLine("Calling the getSalary public method: "+emp1.getSalary());
            Console.WriteLine("With an Employee object: "+emp1.personPublicMethod());
            Console.WriteLine("With an EMployee object: "+emp1.employeePublicMethod());

            //The next line marks an error, you cannot call a protected method from the main
            /*Console.WriteLine("Calling a protected Person method "+emp1.personProtectedMethod());*/

            Console.WriteLine();
        }
    }
}

