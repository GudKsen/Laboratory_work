#include "dessert.h"


NutritValue::NutritValue() : Kkal(), Proteins(), Fats(), Carbohydrates() {
}

NutritValue::NutritValue(double input_kkal, double input_Proteins, double input_Fats, double input_Carbohydrates) : Kkal(input_kkal), Proteins(input_Proteins), Fats(input_Fats), Carbohydrates(input_Carbohydrates) {
}

NutritValue::NutritValue(const NutritValue& copy) : Kkal(copy.Kkal), Proteins(copy.Proteins), Fats(copy.Fats), Carbohydrates(copy.Carbohydrates) {
}

NutritValue::~NutritValue() = default;

double NutritValue::getkkal() const {
	return Kkal;
}
double NutritValue::getProteins() const {
	return Proteins;
}
double NutritValue::getFats() const {
	return Fats;
}
double NutritValue::getCarbohydrates() const {
	return Carbohydrates;
}


void NutritValue::Print() {
	cout << "Kkal:               " << Kkal << endl;
	cout << "Proteins:           " << Proteins << endl;
	cout << "Fats:               " << Fats << endl;
	cout << "Carbohydrates:      " << Carbohydrates;
}


Bake::Bake() {}

Bake::Bake(bool input_IsGlucose,
	string input_NameDessert,
	Taste input_taste,
	double input_Weight,
	NutritValue input_Nutrit,
	double input_Time,
	bool input_IsFlour) : IsGlucose(input_IsGlucose), NameDessert(input_NameDessert), taste(input_taste), Weight_Dessert(input_Weight), Nutrit(input_Nutrit), Time(input_Time), IsFlour(input_IsFlour) {};

Bake:: ~Bake() {}

bool Bake::getIsGlucose() const {
	return IsGlucose;
}
string Bake::getNameDessert() const {
	return NameDessert;
}
Taste Bake::gettaste() const {
	return taste;
}
double Bake::getWeight() const {
	return Weight_Dessert;
}
NutritValue Bake::getNutrit() const {
	return Nutrit;
}
double Bake::getTime() const {
	return Time;
}
bool Bake::getIsFlour() const {
	return IsFlour;
}

void NutritValue::setKkal(double kkal)
{
	Kkal = kkal;
}
void NutritValue::setProteins(double proteins)
{
	Proteins = proteins;
}
void NutritValue::setFats(double fats)
{
	Fats = fats;
}
void NutritValue::setCarbohydtares(double carb)
{
	Carbohydrates = carb;
}

void Bake::Print() {
	std::string print_taste;
	if (taste == Taste::coffee)
		print_taste = "coffee";
	else if (taste == Taste::sweet_and_sour)
		print_taste = "sweet_and_sour";
	else if (taste == Taste::chocolate)
		print_taste = "chocolate";
	else if (taste == Taste::sweet)
		print_taste = "sweet";
	else if (taste == Taste::bitter)
		print_taste = "bitter";
	else if (taste == Taste::creamy)
		print_taste = "creamy";

	cout << "Is glucose:         " << IsGlucose << endl;
	cout << "Time:               " << Time << endl;
	cout << "Does have flavour:  " << IsFlour << endl;
	cout << "Dessert's name:     " << NameDessert << endl;
	cout << "Dessert's weight:   " << Weight_Dessert << endl;
	Nutrit.Print();
	cout << endl;
	cout << "Dessert's taste:    " << print_taste << endl;
	cout << "\n-----------------------" << endl;
}


Dessert * Bake::clone() {
	return (Dessert*)new Bake(*this);
}

double Bake::Weight_of_Carbohydrates_in_NoGlucose_Desserts()
{
	if (getIsGlucose() == false)
	{
		return Nutrit.getCarbohydrates();
	}
	return 0;
}

double Bake::IsItSweetSour()
{
	if (gettaste() == Taste::sweet_and_sour)
	{
		return Nutrit.getkkal();
	}
	return 0;
}

double Bake::Bake_IsItFlour()
{
	if (getIsFlour() == false)
	{
		return Time;
	}
	return 0;
}

void Bake::setIsGlucose(bool input_isglucose)
{
	IsGlucose = input_isglucose;
}
void Bake::setNameDessert(string input_name)
{
	NameDessert = input_name;
}

void Bake::setTaste(Taste tt)
{
	taste = tt;
}

void Bake::setWeightDessert(double input_weight_dessert)
{
	Weight_Dessert = input_weight_dessert;
}

void Bake::setTime(double time)
{

}
void Bake::setIsFlour(bool isflour)
{

}







JellyDessert::JellyDessert() {}

JellyDessert::JellyDessert(bool input_IsGlucose,
	string input_NameDessert,
	Taste input_taste,
	double input_Weight,
	NutritValue input_Nutrit,
	Jelly_Base input_jelly,
	double input_weight_jelly) : IsGlucose(input_IsGlucose), NameDessert(input_NameDessert), taste(input_taste), Weight_Dessert(input_Weight), Nutrit(input_Nutrit), jelly_base(input_jelly), weight_jelly(input_weight_jelly) {}


JellyDessert:: ~JellyDessert() {}

bool JellyDessert::getIsGlucose() const {
	return IsGlucose;
}
string JellyDessert::getNameDessert() const {
	return NameDessert;
}
Taste JellyDessert::gettaste() const {
	return taste;
}
double JellyDessert::getWeight() const {
	return Weight_Dessert;
}
NutritValue JellyDessert::getNutrit() const {
	return Nutrit;
}
Jelly_Base JellyDessert::getjelly() const {
	return jelly_base;
}
double JellyDessert::getweight_jelly() const {
	return weight_jelly;
}


void JellyDessert::Print() {
	std::string print_taste;
	std::string print_jelly_base;
	if (taste == Taste::coffee)
		print_taste = "coffee";
	else if (taste == Taste::sweet_and_sour)
		print_taste = "sweet_and_sour";
	else if (taste == Taste::chocolate)
		print_taste = "chocolate";
	else if (taste == Taste::sweet)
		print_taste = "sweet";
	else if (taste == Taste::bitter)
		print_taste = "bitter";
	else if (taste == Taste::creamy)
		print_taste = "creamy";

	if (jelly_base == agar_agar)
		print_jelly_base = "agar_agar";
	else if (jelly_base == jellatin)
		print_jelly_base = "jellatin";
	else if (jelly_base == pectin)
		print_jelly_base = "pectin";


	std::cout << "Jelly:              " << print_jelly_base << std::endl;
	std::cout << "Weight of jelly:    " << weight_jelly << std::endl;
	std::cout << "Dessert's name:     " << NameDessert << std::endl;
	std::cout << "Dessert's weight:   " << Weight_Dessert << std::endl;
	Nutrit.Print();
	cout << endl;
	std::cout << "Dessert's taste:    " << print_taste << std::endl;
	cout << "\n-----------------------" << endl;
}
Dessert * JellyDessert::clone() {
	return (Dessert*)new JellyDessert(*this);
}


void JellyDessert::setIsGlucose(bool input_isglucose)
{
	IsGlucose = input_isglucose;
}
void JellyDessert::setNameDessert(string input_name)
{
	NameDessert = input_name;
}

void JellyDessert::setTaste(Taste tt)
{
	taste = tt;
}

void JellyDessert::setWeightDessert(double input_weight_dessert)
{
	Weight_Dessert = input_weight_dessert;
}

void JellyDessert::setJellyBase(Jelly_Base jj)
{
	jelly_base = jj;
}

void JellyDessert::setWeightJelly(double input_weight_jelly)
{
	weight_jelly = input_weight_jelly;
}

double JellyDessert::Weight_of_Carbohydrates_in_NoGlucose_Desserts()
{
	if (getIsGlucose() == false)
	{
		return Nutrit.getCarbohydrates();
	}
	return 0;
}

double JellyDessert::IsItSweetSour()
{
	if (gettaste() == Taste::sweet_and_sour)
	{
		return Nutrit.getkkal();
	}
	return 0;
}

double JellyDessert::Bake_IsItFlour()
{
	return 0;
}
