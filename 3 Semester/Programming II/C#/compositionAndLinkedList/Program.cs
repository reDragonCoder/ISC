#nullable disable

// Author: reDragonCoder

/* This program simulates an electronics store inventory system. The main goal is to demonstrate the concept of 
 composition in object-oriented programming, where complex objects are created by combining simpler objects.
 The program includes classes for Manufacturer, Product, Location, Item, Store, and LinkedList, each representing 
 different aspects of an item in the store. The Item class, for example, is composed of a Manufacturer, a Product, 
 and a Location. Users can add products to the inventory, which are stored both in a list and a linked list. */


using System;
using System.Collections.Generic;

public class Manufacturer{
    public string Name{get; set;}  // Manufacturer's name
    public string Company{get; set;}  // Manufacturer's company

    public Manufacturer(string name, string company){
        Name=name;
        Company=company;
    }
}

public class Product{
    public string Name{get; set;}  // Product's name
    public string Type{get; set;}  // Product type (e.g., phone, computer)

    public Product(string name, string type){
        Name=name;
        Type=type;
    }
}

public class Location{
    public string Section{get; set;}  // Store section
    public int Id{get; set;}  // Product ID in the store

    public Location(string section, int id){
        Section=section;
        Id=id;
    }
}

public class Item{
    public Manufacturer Manufacturer{get; set;}  // Composition: Manufacturer object
    public Product Product{get; set;}  // Composition: Product object
    public Location Location{get; set;}  // Composition: Location object

    public Item(Manufacturer manufacturer, Product product, Location location){
        Manufacturer=manufacturer;
        Product=product;
        Location=location;
    }

    public void ShowInfo(){
        Console.WriteLine($"Product: {Product.Name} -> {Product.Type} - Manufacturer: {Manufacturer.Name} ({Manufacturer.Company})");
        Console.WriteLine($"Located at: {Location.Section} with ID {Location.Id}");
    }
}

public class Store{
    private List<Item> items;

    public Store(){
        items=new List<Item>();
    }

    public void AddToInventory(Item item){
        items.Add(item);
        Console.WriteLine($"Product added to inventory: {item.Product.Name}");
    }

    public void ShowInventory(){
        Console.WriteLine("\nInventory:");
        foreach (var item in items){
            item.ShowInfo();
        }
    }
}

// Singly Linked List Node Class
public class Node{
    public Item Item{get; set;}
    public Node Next{get; set;}

    public Node(Item item){
        Item=item;
        Next=null;
    }
}

public class LinkedList{
    private Node head;

    public LinkedList(){
        head=null;
    }

    // Add item to the linked list
    public void AddItem(Item item){
        Node newNode=new Node(item);
        if(head==null){
            head=newNode;
        }
        else{
            Node current=head;
            while (current.Next!=null){
                current=current.Next;
            }
            current.Next=newNode;
        }
        Console.WriteLine($"Item {item.Product.Name} added to linked list.");
    }

    // Print all items in the linked list
    public void PrintLinkedList(){
        Console.WriteLine("\nLinked List Inventory:");
        Node current=head;
        while (current!=null){
            current.Item.ShowInfo();
            current=current.Next;
        }
    }
}

public class Program{
    public static void Main(){
        Console.WriteLine();
        Console.ForegroundColor=ConsoleColor.DarkCyan;
        Console.WriteLine("Electronics Store Inventory\n");
        Console.ResetColor();

        // Create a sample product
        Manufacturer man1=new Manufacturer("Apple", "Apple Inc.");
        Product prod1=new Product("iPhone 15", "Smartphone");
        Location loc1=new Location("Smartphones", 101);
        Item item1=new Item(man1, prod1, loc1);

        // Show sample product info
        item1.ShowInfo();

        // Ask the user how many products they want to add to the inventory
        Console.WriteLine("How many products would you like to add to the inventory?: ");
        int t=0;
        while (true){
            try{
                t=Convert.ToInt32(Console.ReadLine());
                if(t<=0){
                    Console.WriteLine("Please enter a valid number greater than 0.");
                }
                else{
                    break;
                }
            }
            catch (FormatException){
                Console.WriteLine("Please enter a valid number.");
            }
        }

        Store store=new Store();
        LinkedList linkedList=new LinkedList();  // Create a linked list to store items

        for(int i=0; i<t; i++){
            // Ask for manufacturer details
            Console.WriteLine("Enter the manufacturer's name and company: ");
            string manufacturerName=Console.ReadLine();
            string company=Console.ReadLine();
            Manufacturer manufacturerTemp=new Manufacturer(manufacturerName, company);

            // Ask for product details
            Console.WriteLine("Please specify the product name and type (e.g., phone, computer): ");
            string productName=Console.ReadLine();
            string productType=Console.ReadLine();
            Product productTemp=new Product(productName, productType);

            // Ask for location details
            Console.WriteLine("Please enter the store section and product ID: ");
            string section=Console.ReadLine();
            int id=0;
            while (true){
                try{
                    id=Convert.ToInt32(Console.ReadLine());
                    break;
                }
                catch (FormatException){
                    Console.WriteLine("Please enter a valid number for the ID.");
                }
            }

            Location locationTemp=new Location(section, id);
            Item itemTemp=new Item(manufacturerTemp, productTemp, locationTemp);

            // Add item to both store inventory and linked list
            store.AddToInventory(itemTemp);
            linkedList.AddItem(itemTemp);
        }

        // Show store inventory
        store.ShowInventory();

        // Show linked list inventory
        linkedList.PrintLinkedList();
    }
}
