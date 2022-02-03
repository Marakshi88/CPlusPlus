#include <iostream>
#include <string>

using std::string;

//classes are user defined data types which provides encapculation and abstraction

// encapculation means that we bundle related properties together in a single class and sometimes we
// protect those properties from unauthorized or accidental modifications.

// Abstraction means that user of the class is only concerned about the public interfaces and not concerned about the implementation details or how we store data

class Human {
public:
    Human(string gen, string name, int age) : gen(gen) , name(name) , age(age){}
    Human(string gen) : gen(gen){}
    void setGen(string gen) {
        this->gen = gen;
    }
    void setName(string name);
    void setAge(int age);

    string getName() {return name;};
    string getGen() {return gen;};
    int getAge() {return age;};
private:
    string gen;
    string name;
    int age;
};

void Human::setName(string name) {
    this->name = name;
}

void Human::setAge(int age) {
    this->age = age;
}


int main(){
    Human marakshi("Male");
    //Human muaz;

    //marakshi.setAge(25);
    //marakshi.setName("Mostafa");
    //marakshi.setGen("Male");

    std::cout << marakshi.getGen() << std::endl << marakshi.getGen() << std::endl << marakshi.getGen();


    return 0;
}