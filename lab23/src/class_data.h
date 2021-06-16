#pragma once
#include <iostream>
#include <cstring>

struct NutritValue {
	double Kkal;
	double Proteins;
	double Fats;
	double Carbohydrates;
};

class Dessert{
private:
	bool IsGlucose;
	char NameDessert[20];
	double Weight;
	NutritValue Nutrit;
	char Taste[20];
public:
	Dessert();
	void setter(bool glucose, char name[], double weight, double nkkal, double nproteins, double nfats, double ncarb, char taste[]);
	void show();
	~Dessert();
	double getter_weight();
	double getter_carbohydrates();
	bool getter_isglucose();
	char* getter_taste();
	Dessert(const Dessert& copy);
	bool operator != (const Dessert& right);
};