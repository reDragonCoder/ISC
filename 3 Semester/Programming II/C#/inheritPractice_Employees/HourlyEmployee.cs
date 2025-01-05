class HourlyEmployee:Employee{
    //attributes
    private double hourlyPay;
    private double workedHours;

    //default constructor
    public HourlyEmployee(){
        this.hourlyPay=0.0;
        this.workedHours=0.0;
    }

    //constructor with parameters (only class)
    public HourlyEmployee(double hourlyPay, double workedHours){
        this.hourlyPay=hourlyPay;
        this.workedHours=workedHours;
    }

    //constructor with parameters (with base class)
    public HourlyEmployee(string employeeName, string paternalLastName, double hourlyPay, double workedHours):base(employeeName, paternalLastName){
        this.hourlyPay=hourlyPay;
        this.workedHours=workedHours;
    }

    //get & set methods
    public double HourlyPay{
        get{return hourlyPay;}
        set{hourlyPay=value;}
    }

    public double WorkedHours{
        get{return workedHours;}
        set{workedHours=value;}
    }

    //virtual method override
    public override void Print(){
        base.Print();
        Console.WriteLine($"Hourly pay: ${hourlyPay}");
        Console.WriteLine($"Worked hours: {workedHours}");
    }

    //abstract method override
    public override double Income(){
        Console.WriteLine("I'm the income method of the HourlyEmployee class");
        if(workedHours<=40){
            return hourlyPay*workedHours;
        }else{
            double temp=WorkedHours, sum=0;
            sum+=temp*workedHours;
            temp-=40;
            sum+=hourlyPay*(temp*1.5);
            return sum;
        }
    }
}