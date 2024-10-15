// Author: reDragonCoder
/*An owner can have multiple pets*/

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Owner{
    public: 
        class Pet{
            private: 
                string type, race;
            public:
                //constructor with parameters
                Pet(string type, string race){
                    this->type=type;
                    this->race=race;
                }

                //set methods
                void setType(string type){
                    this->type=type;
                }
                void setBreed(string race){
                    this->race=race;
                }

                //get methods
                string getType(){
                    return this->type; 
                }
                string getRace(){
                    return this->race; 
                }

        };//end of class

        //constructor with parameters
        Owner(string name, Pet **pets, int n){
            this->name=name;
            this->pets=pets;
            this->n=n;
        }
        
        //empty constructor
        Owner(){}

        //set methods
        void setN(int n){
            this->n=n;
        }
        void setPets(Pet **pets){
            this->pets=pets;
        }
        void setName(string name){
            this->name=name;
        }

        //get methods
        string getName(){
            return this->name;
        }
        Pet** getPets(){
            return this->pets;
        }
        int getN(){
            return this->n;
        }

    private: 
        string name;
        Pet **pets;//hyper dynamic array of the class Pet
        int n;//size of the array = total amount of pets
}; //end of class

//MAIN
int main(){
    //variables
    string name, type, race;
    int n, noOwners;

    cout<<endl<<"*********************************************************************"<<endl;
    cout<<"FILLING THE OWNER DATA..."<<endl<<endl;
 
    //asking for the owner's name
    cout<<endl<<"Enter the owner name: ";
    fflush(stdin);
    getline(cin,name);

    //asking for the total amount of pets 
    cout<<"Enter the number of pets that has the owner: ";
    cin>>n;

    //filling the hyper dynamic array of pets
    Owner::Pet **pets;
    pets=new Owner::Pet*[n]; 
    for(int i=0; i<n; i++){
        cout<<"Enter the type of pet: "<<i+1<<": ";
        fflush(stdin);
        getline(cin,type);
        cout<<"Enter the race of the pet: "<<i+1<<": ";
        fflush(stdin);
        getline(cin,race);
        pets[i]=new Owner::Pet(type,race);
    }

    cout<<endl<<"*********************************************************************"<<endl;
    cout<<"PRINTING THE OWNER DATA..."<<endl<<endl;

    //creating dynamic object
    Owner *owner;
    owner=new Owner(name, pets, n);
    cout<<endl<<"Owner's name: "<<owner->getName()<<endl;
    cout<<"Number of pets: "<<owner->getN()<<endl;
    cout<<"Pets info:"<<endl;
    for(int i=0; i<owner->getN(); i++){
        /*Explanation for me: "Owner::Pet* pet" is a pointer type variable that points to Pet, so here we assign to "pet" the 
        corresponding pointer in the i-th position, then, "owner->getsPets()[i]" access the i-th pet pointer, and the part
        "owner->getPets" returns a pointer pet array*/
        Owner::Pet* pet=owner->getPets()[i]; 
        cout<<"--- Pet "<<i+1<<"---"<<endl;
        cout<<"Type: "<<pet->getType()<<endl;
        cout<<"Race: "<<pet->getRace()<<endl;
        cout<<endl;
    }

    cout<<endl<<"*********************************************************************"<<endl;
    cout<<"FILLING THE PETLOVERS ARRAY..."<<endl<<endl;

    //owner class array
    Owner **petLovers;
    cout<<endl<<"Enter the number of pet lovers: ";
    cin>>noOwners;
    petLovers=new Owner*[noOwners];
    for(int i= 0; i<noOwners; i++){
        petLovers[i]=new Owner;
    }

    for(size_t i=0; i<noOwners; i++){
        cout<<endl<<"Enter the owner's name: ";
        fflush(stdin);
        getline(cin,name);
        petLovers[i]->setName(name);
        cout<<"Enter the number of pets: ";
        cin>>n;
        petLovers[i]->setN(n);
        Owner::Pet **petsA;
        petsA=new Owner::Pet*[n]; 
        for(int i=0; i<n; i++){
            cout<<"Enter the type of pet "<<i+1<<": ";
            fflush(stdin);
            getline(cin,type);
            cout<<"Enter the race of the pet "<<i+1<<": ";
            fflush(stdin);
            getline(cin,race);
            petsA[i]=new Owner::Pet(type,race);
        }
        petLovers[i]->setPets(petsA);
    }

    cout<<endl<<"*********************************************************************"<<endl;
    cout<<"PRINTING THE PETLOVERS ARRAY..."<<endl<<endl;

    for(int i=0; i<noOwners; i++){
        cout<<endl<<"Owner's name: "<<petLovers[i]->getName()<<endl;
        cout<<"Number of pets: "<<petLovers[i]->getN()<<endl;
        cout<<"---Pets info---"<<endl;
        for(int j=0; j<petLovers[i]->getN(); j++){
            Owner::Pet *pets=petLovers[i]->getPets()[j];
            cout<<pets->getType()<<"-"<<pets->getRace()<<" ";
        }
        cout<<endl;
    }

    return 0;
}