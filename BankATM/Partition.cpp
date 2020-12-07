#include "Partition.h"
#include <iostream>

using namespace std;

/*Customer& Partition::getCustomerPtr()
{
    return PartCostumer;
}

void Partition::setCustomerPtr(Customer* customerptr) {
    PartCostumer = customerptr;
}

Bank& Partition::getAtmPtr()
{
    return atmp;
}

void Partition::setAtmPtr(Bank* atmptr)
{
    atmp = atmptr;
}*/

Partition::Partition(ATM* _atm)
{
    atm = _atm;
    //atm = new ATM;
    nextp = nullptr;
}

Partition* Partition::getNext()
{
    return nextp;
}

void Partition::setNext(Partition*& nextptr)
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
    cout << endl; 

    return out;
}
