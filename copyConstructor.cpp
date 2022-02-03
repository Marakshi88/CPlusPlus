#include <iostream>

using namespace std;

//RAII: resource acquisition is initialization

class AYHAGA {
private:
    int *num;

public:
    AYHAGA() {

    }
    AYHAGA(int x) {
        num = (int*)malloc(sizeof(int));
       // num = new int(1);
        *num = x;
    }
    ~AYHAGA() {
        if(num != nullptr) {
            free(num);
        }
        
        //delete num;
    }

    //AYHAGA(const AYHAGA &src) = delete ; //no copy policy where a compilation will be trigger when copying and object to another
    //AYHAGA &operator=(const AYHAGA &src) = delete;

    //exclusive ownership policy copy constructor
    AYHAGA(AYHAGA &src) {
        num = src.num;
        src.num = nullptr;
    }

    AYHAGA &operator=(AYHAGA &src) {
        //cout << this << std::endl << &src;
        if(this != &src){
            num = src.num;
            src.num = nullptr;
        }

        return *this;
    }
    void printInfo() {
        if(num != nullptr) {
            std::cout << *num << std::endl;
        }
        std::cout << &num << "\t" << num << std::endl;
    }
};

int main() {

    AYHAGA x(10);
    //AYHAGA y(x);
    AYHAGA y;
    y = x;



    //x.printInfo();
    y.printInfo();

    return 0;
}