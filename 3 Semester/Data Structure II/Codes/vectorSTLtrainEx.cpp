// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <vector>
#include <list>
#include <time.h>

//NAMESPACE
using namespace std;

//CLASSES
class Wagon{
	private:
		bool seating[40];
		bool first;
	public:
		Wagon(){
			for(int i=0; i<40; i++){
				this->seating[i]=false;
			}
		};

		Wagon(bool first){
			for(int i=0; i<40; i++){
				this->seating[i]=false;
			}
			this->first=first;
		}

		bool getSeating(int index){
			return seating[index];
		}

		bool getFirst(){
			return first;
		}

		void setFirst(bool first){
			this->first=first;
		}

		void occupy(){
			double probability=first?0.1:0.4;
			for(int i=0; i<40; i++) 
				seating[i]=double(rand())/RAND_MAX<probability;
		}
};


class Train{
	private:
		vector<Wagon> wagons;
		int numberFirst, numberSecond;
		string origin, destination;
		int priceFirst, priceSecond;
	public:
		Train(int nF, int nS, const char *origin, const char *dest, int pF, int pS){
			this->numberFirst=nF;
			this->numberSecond=nS;
			this->origin=origin;
			this->destination=dest;
			this->priceFirst=pF;
			this->priceSecond=pS;
			int total=nF+nS;
			vector<Wagon> first(nF, Wagon(true));
            vector<Wagon> second (nS, Wagon(false));
            first.insert(first.end(),second.begin(), second.end());
            wagons=first;
		}

		~Train(){}

		int getWagon(int i){
			Wagon tempW=wagons[i];
			int occuppied=0;

			for(int i=0; i<40; i++){
				if(tempW.getSeating(i)==true){
					occuppied++;
				}
			}

			return occuppied;
		}

		void fill(){
			for(int i=0; i<numberFirst+numberSecond; i++)
				wagons[i].occupy();
		}

		int totalSales(){
			int totalSales=0, tempCount=0;

			for(int i=0; i<wagons.size(); i++){
				if(wagons[i].getFirst()==true){
					tempCount=priceFirst*getWagon(i);
					totalSales+=tempCount;
				}else if(wagons[i].getFirst()==false){
					tempCount=priceSecond*getWagon(i);
					totalSales+=tempCount;
				}
			}

			return totalSales;
		}
};

//MAIN
int main(){
	srand(time(0));
    Train t(4, 7, "Aguascalientes", "Calvillo", 20, 10);
    t.fill();
    cout<<endl<<endl<<t.totalSales()<<endl;
}

