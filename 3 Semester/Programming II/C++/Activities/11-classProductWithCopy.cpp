// Author: reDragonCoder
//ACTIVITY: USING CLASSES FOR A NUMBER OF PRODUCTS (NOT INLINE) - COPY CONSTRUCTOR

//LIBRARIES
#include <iostream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Product{
    private:
        string prodName; //product name
        double price; //product price
        int stock; //total of products
    public:
        //empty constructor
        Product(); 

        //constructor with parameters
        Product(string prodName, double price, int stock);
        Product(const Product &obj);

        //destructor
        ~Product();

        //set methods for each attribute
        void setProdName(string prodName);
        void setPrice(double price);
        void setStock(int stock);

        //get methods for each attribute
        string getProdName();
        double getPrice();
        int getStock();

        //another methods
        void print(); 
        float stockValue();
};

//METHODS
//empty constructor
Product::Product(){
    cout<<endl<<"I'm the empty constructor"<<endl;
}

//constructor with parameters
Product::Product(string prodName, double price, int stock){
    cout<<endl<<"I'm the constructor with parameters"<<endl;
    this->prodName=prodName;
    this->price=price;
    this->stock=stock;
}

Product::Product(const Product &obj){
    cout<<endl<<"Copy constructor\n";
    this->prodName=obj.prodName;
    this->price=obj.price;
    this->stock=obj.stock;
}

//destructor
Product::~Product(){
    cout<<endl<<"I'm the destructor"<<endl;
}

//set methods
void Product::setProdName(string prodName){
    this->prodName=prodName;
}
void Product::setPrice(double price){
    this->price=price;
}
void Product::setStock(int stock){
    this->stock=stock;
}

//get methods
string Product::getProdName(){
    return this->prodName;
}
double Product::getPrice(){
    return this->price;
}
int Product::getStock(){
    return this->stock;
}

//another methods
void Product::print(){
    cout<<endl<<"Printing product data..."<<endl;
    cout<<endl<<"Product name: "<<this->prodName;
    cout<<endl<<"Product price: $"<<this->price;
    cout<<endl<<"Product stock: "<<this->stock;
}

float Product::stockValue(){
    float stockValue=stockValue=this->stock*this->price;
    return stockValue;
}

//MAIN
int main(int argc, char** argv){
    //variables
    string prodName;
    double price=0, stockValue=0;
    int stock=0;

    //first static object 
    Product hackingDevice;
    cout<<endl<<"I'm the first static object (hacking device)";
    cout<<endl<<"Enter the product's name: ";
    getline(cin, prodName);
    hackingDevice.setProdName(prodName);
    cout<<"Enter the product's price: ";
    cin>>price;
    hackingDevice.setPrice(price);
    cout<<"Enter the product's total stock: ";
    cin>>stock;
    hackingDevice.setStock(stock);
    hackingDevice.print();
    stockValue=hackingDevice.stockValue();
    cout<<endl<<"The total stock value is: $"<<stockValue<<endl;

    cout<<endl<<"************************************************************************************"<<endl;
    prodName=" ";
    price=0;
    stock=0;
    stockValue=0;

    /*//second static object
    Product ioDevice;
    cout<<endl<<"I'm the second static object (I/O device)";
    ioDevice.setProdName("Keyboard");
    ioDevice.setPrice(35);
    ioDevice.setStock(120);
    cout<<endl<<"Printing product information..."<<endl;
    cout<<"The product's name is: "<<ioDevice.getProdName()<<endl;
    cout<<"The product's price is: $"<<ioDevice.getPrice()<<endl;
    cout<<"The product's stock is: "<<ioDevice.getStock()<<endl;
    stockValue=ioDevice.stockValue();
    cout<<endl<<"The total stock value is: $"<<stockValue<<endl;

    cout<<endl<<"************************************************************************************"<<endl;
    prodName=" ";
    price=0;
    stock=0;
    stockValue=0;

    //first dynamic object
    cout<<endl<<"I'm the first dynamic object (cellphone)";
    cout<<endl<<"Enter the product's name: ";
    fflush(stdin);
    getline(cin, prodName);
    cout<<"Enter the product's price: ";
    cin>>price;
    cout<<"Enter the product's total stock: ";
    cin>>stock;
    Product *cellphone;
    cellphone=new Product(prodName, price, stock);
    cellphone->print();
    stockValue=cellphone->stockValue();
    cout<<endl<<"The total stock value is: $"<<stockValue<<endl;
    delete cellphone;

    cout<<endl<<"************************************************************************************"<<endl;
    prodName=" ";
    price=0;
    stock=0;
    stockValue=0;

    //second dynamic object
    cout<<endl<<"I'm the second dynamic object (game console)";
    Product *gameConsole;
    gameConsole=new Product("Xbox", 135.42, 100);
    cout<<endl<<"Printing product information..."<<endl;
    cout<<"The product's name is: "<<gameConsole->getProdName()<<endl;
    cout<<"The product's price is: $"<<gameConsole->getPrice()<<endl;
    cout<<"The product's stock is: "<<gameConsole->getStock()<<endl;
    stockValue=gameConsole->stockValue();
    cout<<endl<<"The total stock value is: $"<<stockValue<<endl;
    delete gameConsole;

    cout<<endl<<"************************************************************************************"<<endl;
    stockValue=0;*/

    //static object copy
    cout<<endl<<"I'm the static object copy (hacking device)";
    Product hackingDeviceCopy(hackingDevice);
    cout<<"The product's name is: "<<hackingDeviceCopy.getProdName()<<endl;
    cout<<"The product's price is: $"<<hackingDeviceCopy.getPrice()<<endl;
    cout<<"The product's stock is: "<<hackingDeviceCopy.getStock()<<endl;
    stockValue=hackingDeviceCopy.stockValue();
    cout<<endl<<"The total stock value is: $"<<stockValue<<endl;

    return 0;
}