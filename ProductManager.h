#pragma once

class ProductManager {
	int milkAmount, eggAmount, woolAmount, cGrainAmount, wGrainAmount;
public:
	ProductManager();

	static const int milkPrice = 20;
	static const int eggPrice = 5;
	static const int woolPrice = 15;
	static const int cornGrainPrice = 50;
	static const int wheetGrainPrice = 100;

	void AddMilk();
	void AddEgg();
	void AddWool();
	void AddCGrain();
	void AddWGrain();

	int GetMilkAmount();
	int GetEggAmount();
	int GetWoolAmount();
	int GetCGrainAmount();
	int GetWGrainAmount();

	void SellMilk(int);
	void SellEgg(int);
	void SellWool(int);
	void SellCGrain(int);
	void SellWGrain(int);
};