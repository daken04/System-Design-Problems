#include<iostream>
using namespace std;

class Singleton{
private:
    static Singleton* instance;

    // private constructor to prevent initialization *imp
    Singleton(){
        cout<<"Singleton Instance created"<<endl;
    }

    //**  The copy constructor and assignment operator are deleted to prevent copying or assigning the singleton instance
    // Private copy constructor to prevent copying
    Singleton(const Singleton&) = delete;

    // Private assignment operator to prevent assignment
    Singleton& operator=(const Singleton&) = delete;

public:
    // this code has thread safety also
    static Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
};

int main(){
    Singleton& obj1 = Singleton::getInstance();
    Singleton& obj2 = Singleton::getInstance();

    if(&obj1 == &obj2){
        cout<<"They are the same"<<endl;
    }
    else{
        cout<<"They are not the same"<<endl;
    }
}
