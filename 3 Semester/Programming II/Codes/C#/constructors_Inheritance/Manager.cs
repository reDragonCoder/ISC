// Class derived from Employee (Third level)
class Manager:Employee{
    //It is understood that we have the Department attribute
    public string Department{get; set;}

    //Manager constructor that calls Employee constructor
    public Manager(string name, string position, string department):base(name, position){
        Department=department;
        Console.WriteLine($"Manager Constructor: {department}");
    }

    ~Manager(){}
}