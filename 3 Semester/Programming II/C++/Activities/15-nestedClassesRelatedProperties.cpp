// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <string>

//NAMESPACE
using namespace std;

//CLASSES
class Person{
public:
    class Address{
    public:
        Address(const char* street, const char* city):street(street), city(city){}

        void print() {
            cout<<street<<", "<<city<<endl;
        }

    private:
        string street;
        string city;
    };

    Person(const char* name, const Address& address):name(name), address(address){}

    void print() {
        cout<<endl<<"Name: "<<name<<endl;
        cout<<"Address: ";
        address.print();
    }

private:
    string name;
    Address address;
};

//MAIN
int main() {
    Person::Address address("Nowhere here 321", "San Francisco");
    Person person("Jhon Doe", address);

    person.print();

    return 0;
}
