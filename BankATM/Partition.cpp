#include "Partition.h"

Bank* Partition::getAtmPtr()
{
    return atmp;
}

void Partition::setAtmPtr(Bank* atmptr)
{
    atmp = atmptr;
}

Partition* Partition::getNextPtr()
{
    return nextp;
}

void Partition::setNextPtr(Partition* nextptr)
{
    nextp = nextptr;
}
