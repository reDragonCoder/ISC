//Class derived from FullTimeEmployee (Third level)
class EmployeeManager:FullTimeEmployee{
    //We override the CalculateSalary method again
    public override double CalculateSalary(double baseSalary){
        double salary=baseSalary*1.2; //20% bonus for being a manager
        Console.WriteLine("Calculated manager salary.");
        return salary;
    }
}