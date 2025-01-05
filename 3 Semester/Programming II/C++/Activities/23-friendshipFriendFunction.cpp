// Author: reDragonCoder
//A class declares its friendship to another class

//LIBRARIES
#include <iostream>

//NAMESPACE
using namespace std;

//CLASSES
class Friendly{
    private:
        int secret;
        friend void friendFunction(Friendly &obj);
        friend class Friend;
};

class Friend{
    public:
        void see(Friendly &obj){
            obj.secret=120;
            cout<<obj.secret<<endl;
        }
};

void friendFunction(Friendly &obj){
    obj.secret=121;
    cout<<obj.secret<<endl;
}

//MAIN
int main(){
    //variables
    Friend friend1;
    Friendly friendly;

    friend1.see(friendly);
    friendFunction(friendly);
    system("pause");
    system("cls");

    return 0;
}