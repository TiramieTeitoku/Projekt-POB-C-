#include "Producent.h"

int Producent::totalAmount = 0;

int Producent::GetAmount()
{
	return totalAmount;
}

int Producent::GetMilk() {
	return pmng.GetMilkAmount();
}

int Producent::GetEgg()
{
	return pmng.GetEggAmount();
}

int Producent::GetWool()
{
	return pmng.GetWoolAmount();
}

int Producent::GetCorn()
{
	return pmng.GetCGrainAmount();
}

int Producent::GetWheet()
{
	return pmng.GetWGrainAmount();
}

void Producent::SellMilk(int x)
{
	pmng.SellMilk(x);
}

void Producent::SellWool(int x)
{
	pmng.SellWool(x);
}

void Producent::SellEgg(int x)
{
	pmng.SellEgg(x);
}

void Producent::SellCorn(int x)
{
	pmng.SellCGrain(x);
}

void Producent::SellWheet(int x)
{
	pmng.SellWGrain(x);
}
