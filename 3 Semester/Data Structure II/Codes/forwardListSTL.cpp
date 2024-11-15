// Author: reDragonCoder

//LIBRARIES
#include <iostream>
#include <forward_list>

//NAMESPACE
using namespace std;

//MAIN
int main(){
   forward_list<int> flist={10, 20, 30, 40, 50};
   
   flist.push_front(60);
   cout<<"recorrido de la lista ";
   for(int &c:flist)
      cout<<c<<" ";
   cout<<endl;
   
   // inserta valor al frente emplace_front()
   flist.emplace_front(70);
   flist.insert_after(flist.begin(), {1, 2, 3});

   forward_list<int>::iterator it;
   for(it=flist.begin(); it!=flist.end(); it++)
   if(*it==10)
      break;
   flist.emplace_after(it,2);
   
   for(int &c:flist)
      cout<<c<<" ";
   cout<<endl;
   
   // elimina al frente pop_front()
   //flist.pop_front();
   //flist.remove(40);
   //flist.remove_if([](int x){ return x>=50;});
   //flist.sort();
   flist.assign({100, 200, 300});

   for(int&c:flist)
      cout<<c<<" ";
   cout<<endl;
   
   return 0;
}
