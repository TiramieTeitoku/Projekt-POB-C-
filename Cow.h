#pragma once
#include "Producent.h"

class Cow :Producent {
	static const int BuyingPrice = 100;
	static int Amount;
public:
	Cow();
	void Produce();
	static int GetBuyingPrice();
	static int GetAmount();
	static void IncrAmount();
};