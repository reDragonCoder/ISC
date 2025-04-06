// String to Hexadecimal
// Author: reDragonCoder
// 24/02/2025   
// Ensamblador

#include <iostream>

using namespace std;
string hexa(int n) {
    string hexadecimal;
    int aux;
    while (aux>0) {
        aux = n%16;
        n = n/16;
        if (aux >=10) {
            hexadecimal += aux + '7';
        } else {
            hexadecimal += aux + '0';
        }

    }
    return hexadecimal;
}

string flipNUmbers(string number){
    string aux="";
    for(int i=number.length(); i>=0; i--){
        aux+=number[i];
    }
    return aux;
}

int main() {
    string phrase = "Hello World, this is my first assembly program";
    int aux;
    string hexadecimalNum, aux2;
    for(int i=0;i<phrase.length();i++) {
        if (isspace(phrase[i])) {
            cout << "020"<<"  ";
        } else {
            aux = phrase[i];
            hexadecimalNum = hexa(aux);
            aux2 = flipNUmbers(hexadecimalNum);
            cout << aux2<<" ";
        }
    }
}