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

	double getter_weight() {
		return Weight;
	}

	double getter_carbohydrates() {
		return Nutrit.Carbohydrates;
	}

	bool getter_isglucose() {
		return IsGlucose;
	}

	char* getter_taste() {
		return Taste;
	}

	Dessert(const Dessert& copy);

	bool operator != (const Dessert& right) {
		if (IsGlucose == right.IsGlucose &&
			NameDessert == right.NameDessert &&
			(Weight >= right.Weight && Weight <= right.Weight) &&
			(Nutrit.Kkal >= right.Nutrit.Kkal && Nutrit.Kkal <= Nutrit.Kkal) &&
			(Nutrit.Proteins >= right.Nutrit.Proteins && Nutrit.Proteins <= right.Nutrit.Proteins) &&
			(Nutrit.Fats >= right.Nutrit.Fats && Nutrit.Fats <= right.Nutrit.Fats) &&
			(Nutrit.Carbohydrates >= right.Nutrit.Carbohydrates && Nutrit.Carbohydrates <= right.Nutrit.Carbohydrates) &&
			Taste == right.Taste) {
			return true;
		}
		else {
			return false;
		}

	}

};