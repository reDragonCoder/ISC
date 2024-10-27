class CommissionedEmployee:Employee{
    //attributes
    private double totalSales;
    private double commissionRate;

    //default constructor
    public CommissionedEmployee(){
        this.totalSales=0.0;
        this.commissionRate=0.0;
    }

    //constructor with parameters (only class)
    public CommissionedEmployee(double totalSales, double commisionRate){
        this.totalSales=totalSales;
        this.commissionRate=commisionRate;
    }

    //constructor with parameters (with base class)
    public CommissionedEmployee(string employeeName, string paternalLastName, double totalSales, double commisionRate):base(employeeName, paternalLastName){
        this.totalSales=totalSales;
        this.commissionRate=commisionRate;
    }

    //get & set methods
    public double TotalSales{
        get{return totalSales;}
        set{totalSales=value;}
    }

    public double CommissionRate{
        get{return commissionRate;}
        set{commissionRate=value;}
    }

    //virtual method override
    public override void Print(){
        base.Print();
        Console.WriteLine($"Total sales: ${totalSales}");
        Console.WriteLine($"Commission rate: {commissionRate}%");
    }

    //abstract method override
    public override double Income(){
        Console.WriteLine("I'm the income method of the CommissionedEmployee class");
        return totalSales*(commissionRate/100);
    }
}