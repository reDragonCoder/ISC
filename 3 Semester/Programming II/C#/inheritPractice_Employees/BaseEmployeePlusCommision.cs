class BaseEmployeePlusCommision:CommissionedEmployee{
    //attributes
    private double baseSalary;

    //default constructor
    public BaseEmployeePlusCommision(){
        this.baseSalary=0.0;
    }

    //constructor with parameters (only class)
    public BaseEmployeePlusCommision(double baseSalary){
        this.baseSalary=baseSalary;
    }

    //constructor with parameters (with base class)
    public BaseEmployeePlusCommision(string employeeName, string paternalLastName, double totalSales, double commisionRate, double baseSalary):base(employeeName, paternalLastName, totalSales, commisionRate){
        this.baseSalary=baseSalary;
    }

    //get & set methods
    public double BaseSalary{
        get{return baseSalary;}
        set{baseSalary=value;}
    }

    //virtual method override
    public override void Print(){
        base.Print();
        Console.WriteLine($"Base salary: ${baseSalary}");
    }

    //abstract method override
    public override double Income(){
        Console.WriteLine("I'm the income method of the BaseEmployeePlusCommision class");
        return (baseSalary*1.1)+(TotalSales*CommissionRate);
    }
}