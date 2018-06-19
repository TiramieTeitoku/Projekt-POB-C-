#include "Wheet.h"

int Wheet::Amount = 0;
//ProductManager Wheet::pmng;

Wheet::Wheet()
{
}

void Wheet::Produce()
{
	pmng.AddWGrain();
}

int Wheet::GetBuyingPrice()
{
	return BuyingPrice;
}

int Wheet::GetAmount()
{
	return Amount;
}

void Wheet::IncrAmount()
{
	Amount++;
}
