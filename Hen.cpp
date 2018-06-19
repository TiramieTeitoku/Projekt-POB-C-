#include "Hen.h"

int Hen::Amount = 0;
//ProductManager Hen::pmng;

Hen::Hen()
{
}

void Hen::Produce()
{
	pmng.AddEgg();
}

int Hen::GetBuyingPrice()
{
	return BuyingPrice;
}

int Hen::GetAmount()
{
	return Amount;
}

void Hen::IncrAmount()
{
	Amount++;
}
