class SalariedEmployee:Employee{
    //attributes
    private double weeklySalary;

    //default constructor
    public SalariedEmployee(){
        this.weeklySalary=0.0;
    }

    //constructor with parameters (only class)
    public SalariedEmployee(double weeklySalary){
        this.weeklySalary=weeklySalary;
    }

    //constructor with parameters (with base class)
    public SalariedEmployee(string employeeName, string paternalLastName, double weeklySalary):base(employeeName, paternalLastName){
        this.weeklySalary=weeklySalary;
    }

    //get & set methods
    public double WeeklySalary{
        get{return weeklySalary;}
        set{weeklySalary=value;}
    }

    //virtual method override
    public override void Print(){
        base.Print();
        Console.WriteLine($"Weekly Salary: ${weeklySalary}");
    }

    //abstract method override
    public override double Income(){
        Console.WriteLine("I'm the income method of the SalariedEmployee class");
        return weeklySalary;
    }
}