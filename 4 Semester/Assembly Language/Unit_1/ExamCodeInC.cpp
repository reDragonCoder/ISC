/* Exam code
 Author: reDragonCoder
 10/03/2025
 Assembly Language
*/

# include <iostream>

using namespace std;

string flipNUmbers(string number){
    string aux="";
    for(int i=number.length(); i>=0; i--){
        aux+=number[i];
    }
    return aux;
}

string binaryConversion(int decimalNum){
    string binaryNum, aux;
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
    aux = flipNUmbers(binaryNum);
    return aux;
}

string baseConversion(int base, int decimal){
    // The converted number will be handled as a string to make things easier when adding numbers and flipping it. 
    string num, finalNum;
    int cont=0;

    while (decimal>0){
        // If the number is evenly divisible by the base we automatically add a 0
        if (decimal%base==0){
            num +="0";
            decimal/=base;
        // Otherwise we first check that it is bigger than the base and thus divisible without causing a zero
        } else if(decimal>=base){
            cont = decimal % base;
            num += cont + '0';
            decimal/=base;
        // If the number is indeed lesser than the base we automatically add it to the string
        }else if(decimal<base){
            num += decimal + '0';
            decimal = 0;
        }
    }
    // The answer must be flipped before returning it as the converted number. 
    finalNum = flipNUmbers(num);
    return finalNum;
}

int main(){
    int n=0, t=0, decimal=0;
    // The user is first asked how many times he would like to convert a number or basically try the program
    string conversedNum;
    cout<<"How many times would you like to convert a number?: ";
    cin>>t;
    while(t--){
        // As a safety percaution we clear the variablse that will be used through the cycle in order to better guarantee the smooth sailing of the program
        n=0;
        decimal = 0;
        conversedNum = " ";
        cout<<"Please enter the base to which you would like to convert the decimal number?: ";
        cin>>n;
        cout<<"Please enter the number that you would like to convert!: ";
        cin>>decimal;
        if (n == 2){
            conversedNum = binaryConversion(decimal);
        } else {
            conversedNum = baseConversion(n,decimal);
        }
        // The number is printed
        cout<<"The number: "<<decimal<<" when converted to base "<<n<<" is: "<<conversedNum<<endl;
        cout<<endl;
    }

    //
    return 0;
}