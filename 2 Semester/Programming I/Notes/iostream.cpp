// Author: reDragonCoder
//Input/output instructions for data flow

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std; //std=standard 

//std::cout<< -> stored in namespace (standard)(::)
//std::cin>>  -> stored in namespace (standard)(::)
//you can name two functions with the same name but with different actions (OOP - Object-Oriented Programming)

//Input --> cin>>variable;     (direction of data flow >>)
/*EXAMPLES:*/
//scanf("%s", chain);  -->  cin>>chain
//scanf("%d", &integer);  -->  cin>>integer
//scanf("%f", &real);  -->  cin>>real
//scanf("%c", &character);  -->  cin>>character

//Output --> cout<<variable;
/*EXAMPLES:*/
//printf("Message");  -->  cout<<"Message";
//printf("%d", integer);  -->  cout<<integer;
//printf("Your age is: %d", age);  -->  cout<<"Your age is: "<<age;
//printf("Give me the [%d][%d] value: ", i, j); -->  cout<<"Give me the ["<<i<<"]["<<j<<"] value";
//printf("Your name %s has % characters: ", name, size); -->  cout<<"Your name "<<name<<" has "<<size<<" characters";
//printf("\n"); -->  cout<<endl; (end of line)
//              --> cout<<"\n";


//#include <ionmanip>
//To show only 2 decimals
//cout<<fixed<<setprecision(2)<<calif<<endl;