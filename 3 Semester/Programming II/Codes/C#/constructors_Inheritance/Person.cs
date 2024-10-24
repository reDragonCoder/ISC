//Base class (First level)
class Person{
    public string Name{get; set;}

    //Base class constructor
    public Person(string name){
        Name=name; //check what you assign the name to the Name property
        Console.WriteLine($"Person Constructor: {name}");
    }

    ~Person(){}
}