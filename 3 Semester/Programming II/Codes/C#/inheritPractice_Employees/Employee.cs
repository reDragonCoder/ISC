abstract class Employee{
    //attributes
    protected string employeeName;
    protected string paternalLastName;

    //default constructor
    public Employee(){
        this.employeeName="";
        this.paternalLastName="";
    }

    //constructor with parameters
    public Employee(string employeeName, string paternalLastName){
        this.employeeName=employeeName;
        this.paternalLastName=paternalLastName;
    }

    //virtual method
    public virtual void Print(){
        Console.WriteLine($"Employee Name: {employeeName}");
        Console.WriteLine($"Employee paternal last name: {paternalLastName}");
    }

    //abstract method
    public abstract double Income();
}