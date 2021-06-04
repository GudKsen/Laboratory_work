#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
struct NutritValue {
	double Kkal;
	double Proteins;
	double Fats;
	double Carbohydrates;
};

class Dessert {
private:
	bool IsGlucose;
	std::string NameDessert;
	double Weight;
	NutritValue Nutrit;
	std::string Taste;
public:
	Dessert();

	void setter(bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, std::string taste);

	void show();

	~Dessert();

	double getter_weight() {
		return Weight;
	}

	std::string& getter_taste() {
		std::string taste = Taste;
		return Taste;
	}

	Dessert(const Dessert& copy);

	std::string to_string() {
		std::ostringstream ostr;
		ostr << IsGlucose << ' ' << NameDessert << ' ' << Weight << ' ' << Nutrit.Kkal << ' ' << Nutrit.Proteins << ' ' << Nutrit.Fats << ' ' << Nutrit.Carbohydrates << ' ' << Taste;
		std::string string_obj = ostr.str();
		std::cout << string_obj << std::endl;
		return string_obj;
	}

	void from_string(std::string smth) {
		std::istringstream istr(smth);
		bool glucose;
		char name[20];
		double weight, kkal, prot, fat, carb;
		char taste[20];
		istr >> glucose >> name >> weight >> kkal >> prot >> fat >> carb >> taste;
		setter(glucose, name, weight, kkal, prot, fat, carb, taste);
	}

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

