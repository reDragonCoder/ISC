//Base class (First level)
class Employee{
    //Virtual method that can be overridden
    public virtual double CalculateSalary(double baseSalary){
        Console.WriteLine("Calculating the employee's salary...");
        return baseSalary;
    }
}