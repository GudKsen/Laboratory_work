#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <fstream>
using std::string;
using std::cin;
using std::cout;
using std::endl;

#define ARRAY_SIZE 6

enum class Taste
{
	sweet,
	chocolate,
	sweet_and_sour,
	creamy,
	coffee,
	bitter
};

class NutritValue {
	double Kkal;
	double Proteins;
	double Fats;
	double Carbohydrates;
public:
	NutritValue();
	NutritValue(double input_kkal, double input_Proteins, double input_Fats, double input_Carbohydrates);
	NutritValue(const NutritValue& copy);
	virtual ~NutritValue();
	double getkkal() const;
	double getProteins() const;
	double getFats() const;
	double getCarbohydrates() const;
	void setKkal(double kkal);
	void setProteins(double proteins);
	void setFats(double fats);
	void setCarbohydtares(double carb);
	void Print();
};

class Dessert {
public:
	virtual void Print() = 0;
	virtual Dessert* clone() = 0;
	virtual ~Dessert() {}
	virtual double IsItGlucose() = 0;
	virtual double IsItSweetSour() = 0;
	virtual double Bake_IsItFlour() = 0;
};



//Naslednik 1

class Bake : public Dessert {
	bool IsGlucose;
	string NameDessert;
	Taste taste;
	double Weight_Dessert;
	NutritValue Nutrit;
	double Time;
	bool IsFlour;
public:
	Bake();
	Bake(bool input_IsGlucose,
		string input_NameDessert,
		Taste input_taste,
		double input_Weight,
		NutritValue input_Nutrit,
		double input_Time,
		bool input_IsFlour);

	virtual ~Bake();

	bool getIsGlucose() const;
	string getNameDessert() const;
	Taste gettaste() const;
	double getWeight() const;
	NutritValue getNutrit() const;
	double getTime() const;
	bool getIsFlour() const;

	void setIsGlucose(bool input_isglucose);
	void setNameDessert(string input_name);
	void setTaste(Taste tt);
	void setWeightDessert(double input_weight_dessert);
	void setTime(double time);
	void setIsFlour(bool isflour);

	void Print() override;
	Dessert* clone() override;
	double IsItGlucose() override;
	double IsItSweetSour() override;
	double Bake_IsItFlour() override final;
};


//Naslednik 2

enum Jelly_Base {
	jellatin,
	pectin,
	agar_agar,
};

class JellyDessert : public Dessert {
	bool IsGlucose;
	string NameDessert;
	Taste taste;
	double Weight_Dessert;
	NutritValue Nutrit;
	Jelly_Base jelly_base;
	double weight_jelly;

public:
	JellyDessert();
	JellyDessert(bool input_IsGlucose,
		string input_NameDessert,
		Taste input_taste,
		double input_Weight,
		NutritValue input_Nutrit,
		Jelly_Base input_jelly,
		double input_weight_jelly);

	void setIsGlucose(bool input_isglucose);
	void setNameDessert(string input_name);
	void setTaste(Taste tt);
	void setWeightDessert(double input_weight_dessert);
	void setWeightJelly(double input_weight_jelly);
	void setJellyBase(Jelly_Base jj);

	bool getIsGlucose() const;
	string getNameDessert() const;
	Taste gettaste() const;
	double getWeight() const;
	NutritValue getNutrit() const;
	Jelly_Base getjelly() const;
	double getweight_jelly() const;
	virtual ~JellyDessert();
	void Print() override;
	Dessert* clone() override;
	double IsItGlucose() override;
	double IsItSweetSour() override;
	double Bake_IsItFlour() override final;
};