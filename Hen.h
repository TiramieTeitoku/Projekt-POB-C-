#pragma once
#include "Producent.h"

class Hen :Producent {
	static const int BuyingPrice = 20;
	static int Amount;
public:
	Hen();
	void Produce();
	static int GetBuyingPrice();
	static int GetAmount();
	static void IncrAmount();
};