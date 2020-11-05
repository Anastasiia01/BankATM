#include "Transaction.h"

Transaction::Transaction(string transid, int transType)
{
	transactionType = type(transType);
	id = transid;
}
