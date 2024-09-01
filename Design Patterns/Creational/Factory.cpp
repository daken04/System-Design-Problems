#include<iostream>
using namespace std;

class Toy{
public:
    virtual void package() const = 0;
};

class Car : public Toy{
public:
    void package() const override{
        cout<<"The Car is Packaged"<<endl;
    }
};

class Doll : public Toy{
public:
    void package() const override{
        cout<<"The Doll is Packaged"<<endl;
    }
};

class ToyFactory{
public:
    Toy* createToy(string type){ // return either the reference or pointer if returning datatype is the interface
        if(type=="Car"){
            return new Car();
        }
        else{
            return new Doll();
        }
    }
};

int main(){
    ToyFactory f;
    Toy* toy1 = f.createToy("Car");
    toy1->package();

    Toy* toy2 = f.createToy("Doll");
    toy2->package();
}