// Conversor de decimal a binario, octal y hexadecimal
// Author: reDragonCoder
// 19/02/2025
// Ensamblador

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string binaryConversion(int decimalNum){
    string binaryNum;
    int cont=0;

    while (decimalNum>0){
        if (decimalNum%2!=0){
            cont++;
            binaryNum += "1";
            decimalNum/=2;
        } else{
        binaryNum += "0";
            decimalNum/=2;
        }
    }

    return binaryNum;
}

string verifyLengthOctal(string binaryNum){
    if (binaryNum.length()%3 != 0){
        while (binaryNum.length()%3 != 0){
            binaryNum += "0";
        }
    }
    return binaryNum;

}

string octalConversion(string binaryNum){
    string auxation;
    int length=0;
    int aux = 0, num=0, len = binaryNum.length()/3;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (binaryNum[length] == '1')
            {
                aux = (pow(2,j));
                num+=aux;
            }
            length++;
        }
        auxation += num + '0';
        num=0;
    }
    return auxation;
}

string verifyLengthHexal(string binaryNum){
    if (binaryNum.length()%4 != 0){
        while (binaryNum.length()%4 != 0){
            binaryNum += "0";
        }
    }
    return binaryNum;

}

string hexaConversion(string binaryNum){
    string auxation = "";
    int length=0;
    int aux = 0, num=0, len = binaryNum.length()/4;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (binaryNum[length] == '1')
            {
                aux = (pow(2,j));
                num+=aux;
            }
            length++;
        }
        if (num >=10) {
            auxation += num + '7';
        } else {
            auxation += num + '0';
        }
        num=0;
    }
    return auxation;

}

string flipNUmbers(string number){
    string aux="";
    for(int i=number.length(); i>=0; i--){
        aux+=number[i];
    }
    return aux;
}

int main(){
    int num;
    string binaryNum = "", nonModBinary="", octalNum="", hexaNum="";


    cout<<"Please enter the decimal number you'd like to transform: ";
    cin>>num;

    if(num==0){
        cout<<"Binary number: 0"<<endl;
        cout<<"Octal number: 0"<<endl;
        cout<<"Hexal number: 0"<<endl;
    }else{
        // BINARY CONVERSION
        binaryNum=binaryConversion(num);
        nonModBinary = binaryNum;
        //OCTAL CONVERSION
        binaryNum= verifyLengthOctal(binaryNum);
        octalNum = octalConversion(binaryNum);

        //HEXADECIMAL CONVERSION
        binaryNum = verifyLengthHexal(nonModBinary);
        hexaNum = hexaConversion(binaryNum);

        cout<<"Given number: "<<num<<endl;

        cout<<"Binary number: "<<flipNUmbers(nonModBinary)<<endl;
        cout<<"Octal number: "<<flipNUmbers(octalNum)<<endl;
        cout<<"Hexal number: "<<flipNUmbers(hexaNum)<<endl;
    }


    return 0;
}
