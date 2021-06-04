#include "class_data.h"

Dessert::Dessert() {
	IsGlucose = false;
	strcpy(NameDessert, "?????");
	Weight = 0;
	Nutrit.Kkal = 0;
	Nutrit.Proteins = 0;
	Nutrit.Fats = 0;
	Nutrit.Carbohydrates = 0;
	strcpy(Taste, "?????");
}

void Dessert::setter(bool glucose, char name[], double weight, double nkkal, double nproteins, double nfats, double ncarb, char taste[]) {
	IsGlucose = glucose;
	strcpy(NameDessert, name);
	Weight = weight;
	Nutrit.Kkal = nkkal;
	Nutrit.Proteins = nproteins;
	Nutrit.Fats = nfats;
	Nutrit.Carbohydrates = ncarb;
	strcpy(Taste, taste);
}

void Dessert::show() {
	std::cout << IsGlucose << ' ' << NameDessert << ' ' << Weight << ' ' << Nutrit.Kkal << ' ' << Nutrit.Proteins << ' ' << Nutrit.Fats << ' ' << Nutrit.Carbohydrates << ' ' << Taste << std::endl;
}

Dessert::~Dessert() {

}

Dessert::Dessert(const Dessert& copy) :IsGlucose(copy.IsGlucose), Weight(copy.Weight) {
	
}