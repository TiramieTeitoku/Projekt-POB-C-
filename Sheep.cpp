#include "Sheep.h"

int Sheep::Amount = 0;
//ProductManager Sheep::pmng;

Sheep::Sheep()
{
}

void Sheep::Produce()
{
	pmng.AddWool();
}

int Sheep::GetBuyingPrice()
{
	return BuyingPrice;
}

int Sheep::GetAmount()
{
	return Amount;
}

void Sheep::IncrAmount()
{
	Amount++;
}
