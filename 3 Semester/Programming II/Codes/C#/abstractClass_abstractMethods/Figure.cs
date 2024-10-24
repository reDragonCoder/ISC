abstract class Figure{
    private string type;

    //Abstract method, it doesnt have an implementation in the base class
    public Figure(string type){this.type=type;}

    public abstract double CalculateArea();

    //Concrete method, it has an implementation in the base class
    public void ShowArea(){
        Console.WriteLine($"The {type} area is: {CalculateArea()}");
    }
}