#pragma once
#include "Producent.h"

class Sheep :Producent {
	static const int BuyingPrice = 70;
	static int Amount;
public:
	Sheep();
	void Produce();
	static int GetBuyingPrice();
	static int GetAmount();
	static void IncrAmount();
};