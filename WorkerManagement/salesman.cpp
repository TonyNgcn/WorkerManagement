#include "salesman.h"

double salesman::getSaleAmount()
{
	return saleAmount;
}

void salesman::calSalary()
{
	basicInfo::salary = saleAmount*0.04;
}
