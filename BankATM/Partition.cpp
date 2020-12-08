#include "Partition.h"
#include <iostream>

using namespace std;

Partition::Partition(ATM* _atm)
{
    atm = _atm;
    nextp = nullptr;
}

Partition::~Partition()
{
    //TODO
}

/*Partition::Partition(const Partition& copy)
{
    atm = new ATM(*copy.atm);
    if (copy.nextp == nullptr) {
        nextp = nullptr;
    }
    else {
        nextp = new Partition(*copy.nextp);
    }
}

Partition& Partition::operator=(const Partition& p)
{
    atm = new ATM(*p.atm);
    if (p.nextp == nullptr) {
        nextp = nullptr;
    }
    else {
        nextp = new Partition(*p.nextp);
    }
    return *this;
}*/

Partition* Partition::getNext()
{
    return nextp;
}

void Partition::setNext(Partition* nextptr)
{
    nextp = nextptr;
}

ATM* Partition::getATM()
{
    return atm;
}

ostream& operator<<(ostream& out, Partition& p)
{
    if (p.atm != nullptr) {
        cout <<"Partition with ATM# "<< p.atm->getNum()<< "->";
    }
    if (p.nextp != nullptr) {
        cout << *(p.nextp);
    }
    return out;
}
