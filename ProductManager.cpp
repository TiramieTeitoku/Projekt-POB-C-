#include "ProductManager.h"

ProductManager::ProductManager()
{
	milkAmount = 0;
	eggAmount = 0;
	woolAmount = 0;
	cGrainAmount = 0;
	wGrainAmount = 0;
}

void ProductManager::AddMilk()
{
	milkAmount++;
}

void ProductManager::AddEgg()
{
	eggAmount++;
}

void ProductManager::AddWool()
{
	woolAmount++;
}

void ProductManager::AddCGrain()
{
	cGrainAmount++;
}

void ProductManager::AddWGrain()
{
	wGrainAmount++;
}

int ProductManager::GetMilkAmount()
{
	return milkAmount;
}

int ProductManager::GetEggAmount()
{
	return eggAmount;
}

int ProductManager::GetWoolAmount()
{
	return woolAmount;
}

int ProductManager::GetCGrainAmount()
{
	return cGrainAmount;
}

int ProductManager::GetWGrainAmount()
{
	return wGrainAmount;
}

void ProductManager::SellMilk(int x)
{
	milkAmount -= x;
}

void ProductManager::SellEgg(int x)
{
	eggAmount -= x;
}

void ProductManager::SellWool(int x)
{
	woolAmount -= x;
}

void ProductManager::SellCGrain(int x)
{
	cGrainAmount -= x;
}

void ProductManager::SellWGrain(int x)
{
	wGrainAmount -= x;
}
