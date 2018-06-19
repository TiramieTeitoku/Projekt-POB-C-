#include "Corn.h"

int Corn::Amount = 0;
//ProductManager Corn::pmng;

Corn::Corn()
{
}

void Corn::Produce()
{
	pmng.AddCGrain();
}

int Corn::GetBuyingPrice()
{
	return BuyingPrice;
}

int Corn::GetAmount()
{
	return Amount;
}

void Corn::IncrAmount()
{
	Amount++;
}
