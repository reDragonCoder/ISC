//Derived class (Second level)
class FullTimeEmployee:Employee{
    //We override the CalculateSalary method
    public override double CalculateSalary(double baseSalary){
        double salary=baseSalary*1.1; //10% bonus for being full time
        Console.WriteLine("Calculated full-time employee salary.");
        return salary;
    }
}