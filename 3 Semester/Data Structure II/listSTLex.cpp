// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <list>

//NAMESPACE
using namespace std;

//CLASSES
class Athlete{
    private:
        string name;
        int number;
        string nationality;
        float time;
    public:
        Athlete(string name, int number, string nationality, float time){
            this->name=name;
            this->number=number;
            this->nationality=nationality;
            this->time=time;
        }

        void showData(){
            cout<<"Name: "<<this->name<<endl;
            cout<<"Number: "<<this->number<<endl;
            cout<<"Nationality: "<<this->nationality<<endl;
            cout<<"Time: "<<this->time<<endl;
            cout<<endl;
        }

        string getName(){return name;}

        float getTime(){return time;}
};

class Race{
    private:
        list<Athlete> athletes;
        float distance;
    public:
        Race(float distance){
            this->distance=distance;
        }

        void addAthlete(Athlete &ath){
            athletes.push_back(ath);
            cout<<"Athlete added successfully"<<endl;
        }

        void show(){
            list<Athlete>::iterator it;
            for(it=athletes.begin(); it!=athletes.end(); it++){
                it->showData();
            }
            cout<<endl;
        }

        Athlete winner(){
            Athlete winner=*athletes.begin();

            list<Athlete>::iterator it;
            for(it=athletes.begin(); it!=athletes.end(); it++){
                if(it->getTime()<winner.getTime()){
                    winner=*it;
                }
            }
            return winner;
        }

        float getDistance(){return distance;}
};

//MAIN
int main(){
    Race x(1000);

    Athlete a1("Pancho", 1, "Mex", 9.1);
    Athlete a2("Chacho", 3, "Col", 3.6);
    Athlete a3("Robert", 2, "Chi", 6.9);

    x.addAthlete(a1);
    x.addAthlete(a2);
    x.addAthlete(a3);

    x.show();

    cout<<"The winner is: "<<x.winner().getName()<<" in the "<<x.getDistance()<<"m race"<<endl;
    return 0;
}