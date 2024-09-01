#include<iostream>
using namespace std;

// abstract product
class Chair{
public:
    virtual void sitOn() = 0;
    virtual ~Chair() {}
};

class Sofa{
public:
    virtual void lieOn() = 0;
    virtual ~Sofa() {}
};

// concrete product
class ModernChair: public Chair{
public:
    void sitOn() override{
        cout<<"Sitting on Modern Chair"<<endl;
    }
};

class VicChair: public Chair{
public:
    void sitOn() override{
        cout<<"Sitting on Vic Chair"<<endl;
    }
};

class ModernSofa: public Sofa{
public:
    void lieOn() override{
        cout<<"Sitting on Modern Sofa"<<endl;
    }
};

class VicSofa: public Sofa{
public:
    void lieOn() override{
        cout<<"Sitting on Vic Sofa"<<endl;
    }
};

// interface for factory
class Factory{
public:
    virtual Chair* createChair() = 0;
    virtual Sofa* createSofa() = 0;
};

// Concrete for Factory
class ModernFactory: public Factory{
public:
    Chair* createChair() override{
        return new ModernChair();
    }

    Sofa* createSofa() override{
        return new ModernSofa();
    }
};

class VicFactory: public Factory{
public:
    Chair* createChair() override{
        return new VicChair();
    }

    Sofa* createSofa() override{
        return new VicSofa();
    }
};

int main(){
    // modern furniture, make chair
    Factory* modernfactory = new ModernFactory();
    Chair* modernchair = modernfactory->createChair();
    modernchair->sitOn();

    //victorian furniture factory, make sofa
    Factory* Vicfactory = new VicFactory();
    Sofa* vicsofa = Vicfactory->createSofa();
    vicsofa->lieOn();
}