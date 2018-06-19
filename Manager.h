#pragma once
#include <iostream>
#include <list>
#include "Cow.h"
#include "Corn.h"
#include "Hen.h"
#include "Sheep.h"
#include "Wheet.h"
#include "ProductManager.h"
using namespace std;
class Manager {
	int money, turnCount, maxAction, actionCount;
	bool gameOn, toMenu;
	list<Cow> cowList;
	list<Hen> henList;
	list<Sheep> sheepList;
	list<Wheet> wheetList;
	list<Corn> cornList;
	enum Producents {
		COW,
		HEN,
		SHEEP,
		WHEET,
		CORN
	};
	enum Products {
		MILK,
		EGG,
		WOOL,
		CORNGRAIN,
		WHEETGRAIN
	};
public:
	Manager();
	void DrawGame();
	void Menu();
	bool GameIsOn();
	void Buy(Producents P);
	void Sell(Products P);
	void NextTurn();
};