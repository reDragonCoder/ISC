// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <iomanip>
#include <string>
#include <ctime> 
#include <cstdlib>

//NAMESPACE
using namespace std;

//PROTOTYPES
string *captureNames(int n);
void printNames(string *names, int n);
int *captureWorkedDays(string *names, int n);
void printData(string *names, int n, int *workedDays);
int **production(int n, int *workedDays);
void printAll(int **prod, string *names, int n, int *workedDays);
int *printPerWorker(int **prod, string *names, int n, int *workedDays);
void maxPieces(string *names, int n, int *dailySum); 
int *printDailyProd(int **prod, int n, int *workedDays);

//MAIN
int main(){
    //RANDOM SEED
    srand(time(NULL));

    //VARIABLES
    int n, *workedDays, **prod, *dailySum, *piecesPerDay;
    string *names;

    //capture the number of workers
    cout<<"Enter the number of workers: ";
    cin>>n;

    cout<<endl<<"*********************************"<<endl;

    //function calls
    names=captureNames(n);
    printNames(names, n);

    cout<<endl<<"*********************************"<<endl;

    workedDays=captureWorkedDays(names, n);
    printData(names, n, workedDays);

    cout<<endl<<"*********************************"<<endl;

    prod=production(n, workedDays);
    printAll(prod, names, n, workedDays);

    cout<<endl<<"*********************************"<<endl;

    dailySum=printPerWorker(prod, names, n, workedDays);

    cout<<endl<<"*********************************"<<endl;

    maxPieces(names, n, dailySum);

    cout<<endl<<"*********************************"<<endl;

    piecesPerDay=printDailyProd(prod, n, workedDays);

    //release memory
    delete[] names;
    delete[] workedDays;
    for(int i=0; i<n; i++){
        delete[] prod[i];
    }
    delete[] prod;
    delete[] dailySum;
    delete[] piecesPerDay;

    return 0;
}

//IMPLEMENTATIONS
string *captureNames(int n){
    string *names=new string[n];
    string name;

    for(int i=0; i<n; i++){
        cout<<"Enter the name of the worker #"<<i+1<<": ";
        fflush(stdin);
        getline(cin,name);
        names[i]=name;
    }

    return names;
}

void printNames(string *names, int n){
    cout<<endl<<"\tWorkers: "<<endl;

    for(int i=0; i<n; i++){
        cout<<i+1<<"\t"<<names[i]<<endl;
    }
}

int *captureWorkedDays(string *names, int n){
    int numOfworkedDays;
    int *workedDays=new int[n];

    cout<<endl;

    for(int i=0; i<n; i++){
        cout<<"Worked days by "<<names[i]<<": ";
        numOfworkedDays=0;
        while(numOfworkedDays<1 || numOfworkedDays>6){
            cin>>numOfworkedDays;
            if(numOfworkedDays<1 || numOfworkedDays>6){
                cout<<"Enter a valid number!: ";
            }
        }
        workedDays[i]=numOfworkedDays;
        cout<<endl;
    }

    return workedDays;
}

void printData(string *names, int n, int *workedDays){
    cout<<setw(10)<<"Workers"<<setw(25)<<"Worked days"<<endl;

    for(int i=0; i<n; i++){
        cout<<i+1<<setw(20)<<names[i]<<setw(10)<<workedDays[i]<<endl;
    }
}

int **production(int n, int *workedDays){
    int **prod=new int *[n];

    //row creation
    for(int i=0; i<n; i++){
        prod[i]=new int[workedDays[i]];  
    }

    //fill staggered matrix with random numbers
    for(int i=0; i<n; i++){
        for(int j=0; j<workedDays[i]; j++){
            prod[i][j]=10+rand()%(25-10+1);
        }
    }

    return prod;
}

void printAll(int **prod, string *names, int n, int *workedDays){
    cout<<endl<<setw(55)<<"Production"<<endl;
    cout<<setw(10)<<"Workers"<<setw(25)<<"Worked days"<<setw(25)<<"1   2   3   4   5   6"<<endl;

    for(int i=0; i<n; i++){
        cout<<i+1<<setw(20)<<names[i]<<setw(10)<<workedDays[i]<<setw(6);
        cout<<"   ";
        for(int j=0; j<workedDays[i]; j++){
            cout<<setw(4)<<prod[i][j];
        }
        cout<<endl;
    }
}

int *printPerWorker(int **prod, string *names, int n, int *workedDays){
    int *sumatory=new int[n];
    int add;

    cout<<endl<<setw(55)<<"Production"<<endl;
    cout<<setw(10)<<"Workers"<<setw(25)<<"Worked days"<<setw(25)<<"1   2   3   4   5   6"<<setw(14)<<"Sumatory"<<endl;

    for(int i=0; i<n; i++){
        add=0;
        for (int j=0; j<workedDays[i]; j++){
            add+=prod[i][j];
        }
        sumatory[i]=add;
    }

    for(int i=0; i<n; i++){
        cout<<i+1<<setw(20)<<names[i]<<setw(10)<<workedDays[i]<<setw(6);
        cout<<"   ";
        for(int j=0; j<workedDays[i]; j++){
            cout<<setw(4)<<prod[i][j];
        }
        cout<<"\t";
        cout<<setw(7)<<sumatory[i]<<endl;
    }

    return sumatory;
}

void maxPieces(string *names, int n, int *dailySum){
    int maxPieces=0;

    for(int i=0; i<n; i++){
        if(i==0){
            maxPieces=dailySum[i];
        }
        if(dailySum[i]>maxPieces){
            maxPieces=dailySum[i];
        }
    }

    cout<<"The greatest production was: "<<maxPieces<<endl;
    cout<<"Workers who carry out this production: "<<endl;

    for(int i=0; i<n; i++){
        if(dailySum[i]==maxPieces){
                cout<<names[i]<<endl;
        }
    }
}

int *printDailyProd(int **prod, int n, int *workedDays){
    int *piecesPerDay=new int[6];

    for(int j=0; j<6; ++j){
        piecesPerDay[j]=0;
        for (int i=0; i<n; i++){
            if(workedDays[i]>j){
                piecesPerDay[j]+=prod[i][j];
            }
        }
    }

    cout<<endl<<setw(16)<<"Production"<<endl;
    cout<<setw(4)<<"  1   2   3   4   5   6"<<setw(2)<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<workedDays[i]; j++){
            cout<<setw(4)<<prod[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"  ";
    for(int i=0; i<6; i++){
        cout<<setw(2)<<piecesPerDay[i]<<"  ";
    }
    cout<<"\t"<<"<--- Sumatory per day"<<endl;

    return piecesPerDay;
}


