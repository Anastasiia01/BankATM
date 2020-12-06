#include "Partition.h"

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
    nextp = nullptr;
}

Partition*& Partition::getNextPtr()
{
    return nextp;
}

void Partition::setNextPtr(Partition* nextptr)
{
    nextp = nextptr;
}

ATM*& Partition::getATM()
{
    return atm;
}

