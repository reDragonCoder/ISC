// Author: reDragonCoder

using System;

public interface IProduct{
    int Id{get; set;}
    string Name{get; set;}
    decimal Price{get; set;}

    void ShowDetails();
}

public class ElectronicProduct:IProduct{
    public int Id{get; set;}
    public string Name{get; set;}
    public decimal Price{get; set;}
    public string Brand{get; set;}

    public ElectronicProduct(int id, string name, decimal price, string brand){
        Id=id;
        Name=name;
        Price=price;
        Brand=brand;
    }

    public void ShowDetails(){
        Console.WriteLine($"Electronic Product: {Name} ({Brand}) - Price: ${Price}");
    }
}

public class AlimentaryProduct:IProduct{
    public int Id{get; set;}
    public string Name{get; set;}
    public decimal Price{get; set;}
    public DateTime ExpirationDate{get; set;}

    public AlimentaryProduct(int id, string name, decimal price, DateTime expirationDate){
        Id=id;
        Name=name;
        Price=price;
        ExpirationDate=expirationDate;
    }

    public void ShowDetails(){
        Console.WriteLine($"Alimentary Product: {Name} - Price: ${Price} - Expires: {ExpirationDate.ToShortDateString()}");
    }
}

public class Program{
    public static void Main(){
        IProduct phone=new ElectronicProduct(1, "phone", 299.99m, "TechBrand");
        IProduct apple=new AlimentaryProduct(2, "apple", 0.99m, DateTime.Now.AddMonths(1));

        phone.ShowDetails();
        apple.ShowDetails();
        apple.Price=33;
        apple.ShowDetails();

    }
}

