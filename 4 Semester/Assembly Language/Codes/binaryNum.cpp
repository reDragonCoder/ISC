// Contador de 1's en un número binario
// Celia Fernanda Vela Uribe y César Andrés Zuleta Malanco
// 12/02/2025
// Ensamblador

#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int main(){
    int num =0, cont = 0;
    string binaryNum = "";
    string aux="";
    cout<<"Please enter the decimal number you'd like to transform into a binary number: ";
    cin>>num;
    while (num>0){
        // Verify is the number is even, if so add a 1 to the binary container
        if (num%2!=0){
            cont++;
            binaryNum += "1";
            num/=2;
        } else{
        // Otherwise add a 0
            binaryNum += "0";
            num/=2;
        }
    }
    // Because the number is going to end up being backwards, it is necessary to invert it. 
    // Ex. 10 will end up being 0101 before it is inverted into 1010
    for(int i=binaryNum.length(); i>=0; i--){
        aux+=binaryNum[i];
    }
    cout<<"Binary number "<<aux<<endl;
    cout<<"The binary number presents "<<cont<<" ones";
    return 0;
}