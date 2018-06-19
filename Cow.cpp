#include "Cow.h"

int Cow::Amount = 0;
ProductManager Cow::pmng;

Cow::Cow()
{

}

void Cow::Produce()
{
	pmng.AddMilk();
}

int Cow::GetBuyingPrice()
{
	return BuyingPrice;
}

int Cow::GetAmount()
{
	return Amount;
}

void Cow::IncrAmount()
{
	Amount++;
}
