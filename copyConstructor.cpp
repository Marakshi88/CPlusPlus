#include <iostream>

using namespace std;

//RAII: resource acquisition is initialization

class AYHAGA {
private:
    int *num;
    int *usersCount;    
public:
    AYHAGA() {

    }
    AYHAGA(int x) {
        num = (int*)malloc(sizeof(int));
        *num = x;
        usersCount= (int*)malloc(sizeof(int));
        *usersCount=1;
    }
    ~AYHAGA() {
        if(( num != nullptr)&&((*usersCount)==1)){
            free(num);
            cout<<"Freeeeeee"<<endl;
        }
        (*usersCount)--;
    }

    //AYHAGA(const AYHAGA &src) = delete ; //no copy policy where a compilation will be trigger when copying and object to another
    //AYHAGA &operator=(const AYHAGA &src) = delete;

    //Shared ownership policy
    AYHAGA(AYHAGA &src) {
        num = src.num;
        usersCount=src.usersCount;
        (*usersCount)++;
    }
    //Shared ownership policy
    AYHAGA &operator=(AYHAGA &src) {
        //cout << this << std::endl << &src;
        if(this != &src){
            num = src.num;
            usersCount=src.usersCount;
            (*usersCount)++;
        }

        return *this;
    }
    void printInfo() {
        if(num != nullptr) {
            std::cout << *num <<  "\tusers: " <<*usersCount  <<std::endl;
        }
    }
    void SetNum(int x)
    {
        *num=x;
    }
        //std::cout << &num << "\t" << num << std::endl;
    
};

int main() {

    AYHAGA z(30);
    AYHAGA x(10);
    //AYHAGA y(x);
    AYHAGA y;
    y = x;



    x.printInfo();
    y.printInfo();
    y.SetNum(20);
    x.printInfo();
    y.printInfo();
    z.printInfo();

    return 0;
}