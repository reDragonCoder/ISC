//First class
public class Animal{
    private string name;
    private int age;

    //Base class constructor
    public Animal(string name, int age){
        this.name=name;
        this.age=age;
        Console.WriteLine($"Animal constructor: Name = {name}, Age = {age}");
    }

    //Methods to display attributes
    public virtual void ShowData(){
        Console.WriteLine($"Animal: Name = {name}, Age = {age}");
    }
}