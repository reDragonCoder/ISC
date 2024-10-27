using System;

class Program{
    static void Main(string[] args){
        /* DATA */
        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("Cesar Andres Zuleta Malanco\n");
        Console.ResetColor();

        //variables
        double tempIncome;

        //instances
        SalariedEmployee salariedEmployee=new SalariedEmployee("Rhaenyra", "Targaryen", 1500.5);
        CommissionedEmployee commissionedEmployee=new CommissionedEmployee("Daemon", "Targaryen", 23200, 12.5);
        HourlyEmployee hourlyEmployee=new HourlyEmployee("Criston", "Cole", 25, 40);
        BaseEmployeePlusCommision baseEmployeePlusCommision=new BaseEmployeePlusCommision("Aegon", "Targaryen", 20, 12.5,  3500.20);

        //calling Income() method
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- INCOME METHOD ---");
        Console.ResetColor();
        tempIncome=salariedEmployee.Income();
        Console.WriteLine($"Salaried Employee Income: ${tempIncome}\n");

        tempIncome=commissionedEmployee.Income();
        Console.WriteLine($"Commissioned Employee Income: ${tempIncome}\n");
        
        tempIncome=hourlyEmployee.Income();
        Console.WriteLine($"Hourly Employee Income: ${tempIncome}\n");

        tempIncome=baseEmployeePlusCommision.Income();
        Console.WriteLine($"Base Employee + Commision Income: ${tempIncome}\n");

        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("********************************************\n");
        Console.ResetColor();

        //calling Print() method
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- PRINT METHOD ---");
        Console.ResetColor();
        salariedEmployee.Print();
        Console.WriteLine();
        commissionedEmployee.Print();
        Console.WriteLine();
        hourlyEmployee.Print();
        Console.WriteLine();
        baseEmployeePlusCommision.Print();
        Console.WriteLine();

        Console.ForegroundColor=ConsoleColor.DarkMagenta;
        Console.WriteLine("********************************************\n");
        Console.ResetColor();

        //calling get & set methods
        Console.ForegroundColor=ConsoleColor.DarkBlue;
        Console.WriteLine("--- GET & SET METHODS ---");
        Console.ResetColor();
        salariedEmployee.WeeklySalary=1300.5;
        Console.WriteLine("Salaried Employee");
        Console.WriteLine($"Weekly salary: ${salariedEmployee.WeeklySalary}\n");

        commissionedEmployee.TotalSales=50;
        commissionedEmployee.CommissionRate=7.3;
        Console.WriteLine("Commissioned Employee");
        Console.WriteLine($"Total sales: ${commissionedEmployee.TotalSales}");
        Console.WriteLine($"Commission rate: {commissionedEmployee.CommissionRate}%\n");

        hourlyEmployee.HourlyPay=50;
        hourlyEmployee.WorkedHours=65;
        Console.WriteLine("Hourly Employee");
        Console.WriteLine($"Hourly pay: ${hourlyEmployee.HourlyPay}");
        Console.WriteLine($"Worked hours: {hourlyEmployee.WorkedHours}\n");

        baseEmployeePlusCommision.BaseSalary=20000;
        Console.WriteLine("Base Employee + Commision");
        Console.WriteLine($"Base salary: ${baseEmployeePlusCommision.BaseSalary}\n");
    }
}