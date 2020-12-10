#include "ATM.h"

bool ATM::addCust(Customer cust)
{
    bool ifFirst = false;
    if (custs.size() == 0) {
        ifFirst = true;
    }
    custs.push(cust); 
    return ifFirst;
}

Customer* ATM::getFirst()
{
    if(custs.size()!=0){
        return &(custs.front()); 
    }
    return nullptr;
}
