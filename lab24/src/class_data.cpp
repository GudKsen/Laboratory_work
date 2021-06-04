#include "class_data.h"

Dessert::Dessert() {
	IsGlucose = false;
	NameDessert = "?????";
	Weight = 0;
	Nutrit.Kkal = 0;
	Nutrit.Proteins = 0;
	Nutrit.Fats = 0;
	Nutrit.Carbohydrates = 0;
	Taste = "?????";
}

void Dessert::setter(bool glucose, std::string name, double weight, double nkkal, double nproteins, double nfats, double ncarb, std::string taste) {
	IsGlucose = glucose;
	NameDessert = name;
	Weight = weight;
	Nutrit.Kkal = nkkal;
	Nutrit.Proteins = nproteins;
	Nutrit.Fats = nfats;
	Nutrit.Carbohydrates = ncarb;
	Taste = taste;
}

void Dessert::show() {
	std::cout << IsGlucose << ' ' << NameDessert << ' ' << Weight << ' ' << Nutrit.Kkal << ' ' << Nutrit.Proteins << ' ' << Nutrit.Fats << ' ' << Nutrit.Carbohydrates << ' ' << Taste << std::endl;
}

Dessert::~Dessert() {
	
}

Dessert::Dessert(const Dessert& copy) :IsGlucose(copy.IsGlucose), Weight(copy.Weight) {

}
