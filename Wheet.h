#pragma once
#include "Producent.h"

class Wheet :Producent {
	static const int BuyingPrice = 400;
	static int Amount;
public:
	Wheet();
	void Produce();
	static int GetBuyingPrice();
	static int GetAmount();
	static void IncrAmount();
};