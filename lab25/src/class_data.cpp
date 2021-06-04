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

std::istream& operator>>(std::istream& in, Dessert*& dessert)
{
	in >> dessert->IsGlucose;
	in >> dessert->NameDessert;
	in >> dessert->Weight;
	in >> dessert->Nutrit.Kkal;
	in >> dessert->Nutrit.Proteins;
	in >> dessert->Nutrit.Fats;
	in >> dessert->Nutrit.Carbohydrates;
	in >> dessert->Taste;
	return in;
}

bool operator==(const Dessert& d1, const Dessert& d2)
{

	return (d1.IsGlucose == d2.IsGlucose &&
		d1.NameDessert == d2.NameDessert &&
		(d1.Weight >= d2.Weight && d1.Weight <= d2.Weight) &&
		d1.Nutrit.Kkal == d2.Nutrit.Kkal &&
		d1.Nutrit.Proteins == d2.Nutrit.Proteins &&
		d1.Nutrit.Fats == d2.Nutrit.Fats &&
		d1.Nutrit.Carbohydrates == d2.Nutrit.Carbohydrates &&
		d1.Taste == d2.Taste);
}

