#include "Manager.h"
using namespace std;
Manager::Manager()
{
	money = 100;
	turnCount = 1;
	maxAction = 3;
	actionCount = maxAction;
	toMenu = true;
}

void Manager::DrawGame()
{
	cout << "----------------------------------------------------------------------------------------------" << endl;
	cout << "Aktualna tura: " << turnCount << endl << "Gotowka: " << money << endl << "Pozostale akcje: " << actionCount << "/" << maxAction << endl;
	int op;
	if (toMenu) { 
		cout << "1. Kup" << endl << "2. Sprzedaj" << endl << "3. Stan farmy" << endl << "4. Koniec tury" << endl << "0. Wyjdz" << endl; 
		toMenu = false;
	}
	cin >> op;
	switch (op)
	{
	case 1:
		int opBuy;
		cout << "1. Pole" << endl << "2. Zwierzeta" << endl << "0. Powrot" << endl;
		cin >> opBuy;
		switch (opBuy)
		{
		case 1:
			int opGrain;
			cout << "1. Pszenica" << endl << "2. Kukurydza" << endl << "0. Powrot" << endl;
			cin >> opGrain;
			switch (opGrain)
			{
			case 1:
				Buy(WHEET);
				toMenu = true;
				break;
			case 2:
				Buy(CORN);
				toMenu = true;
			default:
				toMenu = true;
				break;
			}
			break;
		case 2:
			int opAnimal;
			cout << "1. Kury" << endl << "2. Krowy" << endl << "3. Owce" << endl << "0. Powrot" << endl;
			cin >> opAnimal;
			switch (opAnimal)
			{
			case 1:
				Buy(HEN);
				toMenu = true;
				break;
			case 2:
				Buy(COW);
				toMenu = true;
				break;
			case 3:
				Buy(SHEEP);
				toMenu = true;
				break;
			default:
				toMenu = true;
				break;
			}
			break;
		default:
			cout << "1. Pole" << endl << "2. Zagrode" << endl << "0. Powrot" << endl;
			break;
		}
		break;
	case 2:
		cout << "1. Zboze" << endl << "2. Produkty zwierzece" << /*endl << "3. Pole" << endl << "4. Zwierzeta" <<*/ endl << "0. Powrot" << endl;
		int opSell;
		cin >> opSell;
		switch (opSell)
		{
		case 1:
			int opGrain;
			cout << "1. Worki pszenicy" << endl << "2. Worki kukurydzy" << endl << "0. Powrot" << endl;
			cin >> opGrain;
			switch (opGrain) {
			case 1:
				Sell(WHEETGRAIN);
				toMenu = true;
				break;
			case 2:
				Sell(CORNGRAIN);
				toMenu = true;
				break;
			default:
				cout << "1. Worki pszenicy" << endl << "2. Worki kukurydzy" << endl << "0. Powrot" << endl;
				break;
			}
			break;
		case 2:
			int opAniProd;
			cout << "1. Jajka" << endl << "2. Mleko" << endl << "3. Welna" << endl << "0. Powrot" << endl;
			cin >> opAniProd;
			switch (opAniProd) {
			case 1:
				Sell(EGG);
				toMenu = true;
				break;
			case 2:
				Sell(MILK);
				toMenu = true;
				break;
			case 3:
				Sell(WOOL);
				toMenu = true;
				break;
			default:
				break;
			}
			break;
		/*case 3:
			cout << "1. Pszenica" << endl << "2. Kukurydza" << endl << "0. Powrot" << endl;
			break;
		case 4:
			cout << "1. Kury" << endl << "2. Krowy" << endl << "3.Owce" << endl << "0. Powrot" << endl;
			break;*/
		default:
			cout << "1. Zborze" << endl << "2. Produkty zwierzece" << endl << "0. Powrot" << endl;
			break;
		}
		break;
	case 3:
		cout << "Kury - " << Hen::GetAmount() << endl << "Krowy - " << Cow::GetAmount() << endl << "Owce - " << Sheep::GetAmount() << endl << "Kukurydza - " << Corn::GetAmount() << endl << "Pszenica - " << Wheet::GetAmount() << endl;
		cout << "Mleko - " << Producent::GetMilk() << endl << "Jajka - " << Producent::GetEgg() << endl << "Welna - " << Producent::GetWool() << endl << "Worki pszenicy - " << Producent::GetWheet() << endl << "Worki kukurydzy - " << Producent::GetCorn() << endl;
		toMenu = true;
		break;
	case 4:
		NextTurn();
		cout << "Nowa tura rozpoczeta!" << endl;
		break;
	default:
		cout << "1. Kup" << endl << "2. Sprzedaj" << endl << "0. Wyjdz" << endl;
		break;
	}
}

void Manager::Menu()
{
	cout << "Witam w symulatorze farmera! Wybierz opcje." << endl << "1. Nowa gra" << endl << "2. Wyjscie" << endl;
	int opcja;
	bool repeat;
	do{
		repeat = false;
		cin >> opcja;
		switch (opcja)
		{
		case 1:
			gameOn = true;
			break;
		case 2:
			gameOn = false;
			break;
		default:
			cout << "Wybierz jedna z podanych opcji." << endl;
			repeat = true;
			break;
		}
	} while (repeat);
}

bool Manager::GameIsOn()
{
	return gameOn;
}

void Manager::Buy(Producents S)
{
	if (actionCount > 0)
	{
		switch (S)
		{
		case Manager::COW:
			if (money >= Cow::GetBuyingPrice()) {
				money -= Cow::GetBuyingPrice();
				Cow *C = new Cow();
				cowList.push_front(*C);
				actionCount--;
				Cow::IncrAmount();
			}
			else {
				cout << "Brak pieniedzy." << endl;
			}
			break;
		case Manager::HEN:
			if (money >= Hen::GetBuyingPrice()) {
				money -= Hen::GetBuyingPrice();
				Hen *H = new Hen();
				henList.push_front(*H);
				actionCount--;
				Hen::IncrAmount();
			}
			else {
				cout << "Brak pieniedzy." << endl;
			}
			break;
		case Manager::SHEEP:
			if (money >= Sheep::GetBuyingPrice()) {
				money -= Sheep::GetBuyingPrice();
				Sheep *S = new Sheep();
				sheepList.push_front(*S);
				actionCount--;
				Sheep::IncrAmount();
			}
			else {
				cout << "Brak pieniedzy." << endl;
			}
			break;
		case Manager::WHEET:
			if (money >= Wheet::GetBuyingPrice()) {
				money -= Wheet::GetBuyingPrice();
				Wheet *W = new Wheet();
				wheetList.push_front(*W);
				actionCount--;
				Wheet::IncrAmount();
			}
			else {
				cout << "Brak pieniedzy." << endl;
			}
			break;
		case Manager::CORN:
			if (money >= Corn::GetBuyingPrice()) {
				money -= Corn::GetBuyingPrice();
				Corn *C = new Corn();
				cornList.push_front(*C);
				actionCount--;
				Wheet::IncrAmount();
			}
			else {
				cout << "Brak pieniedzy." << endl;
			}
			break;
		default:
			break;
		}
	}
	else {
		cout << "Koniec punkow akcji." << endl;
	}
}

void Manager::Sell(Products P)
{
	if (actionCount > 0)
	{
		switch (P)
		{
		case Manager::MILK:
			if (Producent::GetMilk() > 0)
			{
				money += (Producent::GetMilk()*ProductManager::milkPrice);
				Producent::SellMilk(Producent::GetMilk());
				actionCount--;
			}
			else {
				cout << "Brak mleka." << endl;
			}
			break;
		case Manager::EGG:
			if (Producent::GetEgg() > 0)
			{
				money += (Producent::GetEgg()*ProductManager::eggPrice);
				Producent::SellEgg(Producent::GetEgg());
				actionCount--;
			}
			else {
				cout << "Brak jajek." << endl;
			}
			break;
		case Manager::WOOL:
			if (Producent::GetWool() > 0)
			{
				money += (Producent::GetWool()*ProductManager::woolPrice);
				Producent::SellWool(Producent::GetWool());
				actionCount--;
			}
			else {
				cout << "Brak welny." << endl;
			}
			break;
		case Manager::CORNGRAIN:
			if (Producent::GetCorn() > 0)
			{
				money += (Producent::GetCorn()*ProductManager::cornGrainPrice);
				Producent::SellCorn(Producent::GetCorn());
				actionCount--;
			}
			else {
				cout << "Brak workow kukurydzy." << endl;
			}
			break;
		case Manager::WHEETGRAIN:
			if (Producent::GetWheet() > 0)
			{
				money += (Producent::GetWheet()*ProductManager::wheetGrainPrice);
				Producent::SellWheet(Producent::GetWheet());
				actionCount--;
			}
			else {
				cout << "Brak workow pszenicy." << endl;
			}
			break;
		default:
			break;
		}
	}
	else {
		cout << "Koniec punkow akcji." << endl;
	}
}

void Manager::NextTurn()
{
	if (!cowList.empty()) {
		for (list<Cow>::iterator iter = cowList.begin(); iter != cowList.end(); iter++) {
			iter->Produce();
		}
	}
	if (!henList.empty())
	{
		for (list<Hen>::iterator iter = henList.begin(); iter != henList.end(); iter++) {
			iter->Produce();
		}
	}
	if (!sheepList.empty())
	{
		for (list<Sheep>::iterator iter = sheepList.begin(); iter != sheepList.end(); iter++) {
			iter->Produce();
		}
	}
	if (!cornList.empty())
	{
		for (list<Corn>::iterator iter = cornList.begin(); iter != cornList.end(); iter++) {
			iter->Produce();
		}
	}
	if (!wheetList.empty())
	{
		for (list<Wheet>::iterator iter = wheetList.begin(); iter != wheetList.end(); iter++) {
			iter->Produce();
		}
	}
	actionCount = maxAction;
	toMenu = true;
	turnCount++;
}
