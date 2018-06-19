#pragma once
#include "Producent.h"

class Corn :Producent {
	static const int BuyingPrice = 300;
	static int Amount;
public:
	Corn();
	void Produce();
	static int GetBuyingPrice();
	static int GetAmount();
	static void IncrAmount();
};