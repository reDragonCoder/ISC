// Author: reDragonCoder

using System;

// Interface with properties and methods
public interface IEmployee{
    int Id{get; set;}
    string Name{get; set;}
    decimal Salary{get; set;}

    void ShowInfo();
    decimal CalculateBonus();
}

// Base class that implements the interface and defines virtual methods
public class BaseEmployee:IEmployee{
    public int Id{get; set;}
    public string Name{get; set;}
    public decimal Salary{get; set;}

    public BaseEmployee(int id, string name, decimal salary){
        Id=id;
        Name=name;
        Salary=salary;
    }

    // Virtual method that allows overriding in subclasses
    public virtual void ShowInfo(){
        Console.WriteLine($"Employee: {Name} (ID: {Id}) - Salary: ${Salary}");
    }

    public virtual decimal CalculateBonus(){
        return Salary*0.1m; // Bonus of 10% of salary
    }
}

// Subclass that overrides methods of the base class
public class Manager:BaseEmployee{
    public decimal Budget{get; set;}

    public Manager(int id, string name, decimal salary, decimal budget):base(id, name, salary){
        Budget=budget;
    }

    public override void ShowInfo(){
        Console.WriteLine($"Manager: {Name} (ID: {Id}) - Salary: ${Salary} - Budget: ${Budget}");
    }

    public override decimal CalculateBonus(){
        return Salary*0.2m; // Bonus of 20% of salary for managers
    }
}

// Additional subclass that also overrides methods
public class Engineer:BaseEmployee{
    public string Specialty{get; set;}

    public Engineer(int id, string name, decimal salary, string specialty):base(id, name, salary){
        Specialty=specialty;
    }

    public override void ShowInfo(){
        Console.WriteLine($"Engineer: {Name} (ID: {Id}) - Salary: ${Salary} - Specialty: {Specialty}");
    }

    public override decimal CalculateBonus(){
        return Salary*0.15m; // 15% salary bonus for engineers
    }
}

public class Program{
    public static void Main(){
        // Polymorphism with interfaces and upcasting
        IEmployee Manager=new Manager(1, "Alice", 80000, 500000);
        IEmployee Engineer=new Engineer(2, "Bob", 60000, "Software");

        Manager.ShowInfo();
        Engineer.ShowInfo();

        Console.WriteLine($"{Manager.Name} bonus: ${Manager.CalculateBonus()}");
        Console.WriteLine($"{Engineer.Name} bonus: ${Engineer.CalculateBonus()}");

        // Downcasting to access specific properties
        if(Manager is Manager SpecificManager){
            // automatic downcasting within the condition
            Console.WriteLine($"The manager's budget is: ${SpecificManager.Budget}");
        }

        if(Engineer is Engineer){
            //dowcasting  manual
            Engineer EngineerEspecifico=(Engineer)Engineer;
            Console.WriteLine($"The Engineer's specialty is: {EngineerEspecifico.Specialty}");
        }
        
         //upCasting using a variable of the interface type.
        Engineer miIng=new Engineer(2, "Kike", 75000, "Hardware");
        IEmployee emp=miIng;
        emp.ShowInfo();
        emp.CalculateBonus();
        //Console.WriteLine(emp.Specialty);

        //Polymorphic arrangement with interface
        IEmployee []array=new IEmployee[5];
        array[0]=new Engineer(13, "Mayra", 75600, "Development"); 
        array[1]=new Engineer(14, "Gaby", 55500, "Testing"); 
        array[2]=new Manager(11, "Jorge", 90500, 500500);
        array[3]=new Engineer(17, "Sandra", 25500, "Analyst"); 
        array[4]=new BaseEmployee(34, "Memo", 15000);
        print(array); //a static method can call another static method
    }
       static void print(IEmployee[] array){
          Console.WriteLine("Printing polymorphic array of interfaces");
          Console.WriteLine("**********************");
          foreach (var item in array){
            item.ShowInfo();
            item.CalculateBonus();
            Console.WriteLine("**********************");
          }
    }
}

