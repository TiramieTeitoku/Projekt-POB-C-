#pragma once
#include "ProductManager.h"

class Producent{
	static int totalAmount;
	int cooldownTime;
protected:
	static ProductManager pmng;
public:
	virtual void Produce() = 0;
	static int GetAmount();

	static int GetMilk();
	static int GetEgg();
	static int GetWool();
	static int GetCorn();
	static int GetWheet();

	static void SellMilk(int);
	static void SellWool(int);
	static void SellEgg(int);
	static void SellCorn(int);
	static void SellWheet(int);
};
