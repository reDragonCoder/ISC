 //Derived class (Second level)
 class Employee:Person{
    public string Position{get; set;}

    // Constructor de Employee que llama al constructor de Person
    public Employee(string name, string position):base(name){
        Position=position;
        Console.WriteLine($"Employee Constructor: {position}");
    }

    ~Employee(){}
}