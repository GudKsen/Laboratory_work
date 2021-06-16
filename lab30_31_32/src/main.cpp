#include "desserts_arr.h"
#include <map>
using std::map;
using std::unique_ptr;
using std::auto_ptr;
using std::shared_ptr;
using std::weak_ptr;

void DopTask()
{
	map<vector<string>, string> m1;
	map<vector<string>, string> m2;
	m1[{"Kharkiv", "Kyiv"}] = "Ukraine";
	m1[{"Moscow", "Belgrad"}] = "Russia";
	m1[{"Minsk", "Bobruisk"}] = "Belarus";
	cout << m1[{"Kharkiv", "Kyiv"}] << endl;


}

int main() {
	/*glucose, name, taste, weight, nutrit, time, isflavour*/
	Bake bake(false, "Sharlotka", Taste::sweet, 35, NutritValue{ 100, 50, 15, 20 }, 2, true);
	Bake bake2(true, "Kruasan", Taste::chocolate, 350, NutritValue{ 100, 50, 15, 20 }, 2, false);
	Bake bake3(false, "Napoleon", Taste::creamy, 50, NutritValue{ 100, 50, 15, 20 }, 2, true);
	Bake bake4(true, "Cookie", Taste::chocolate, 100, NutritValue{ 20, 30, 10, 5 }, 4, true);


	

	/*glucose, name, taste, weight dessert, nutrit, jelly base, weight jelly base*/
	JellyDessert jellyDessert(true, "Klubnichnoe", Taste::sweet, 55, NutritValue{ 100, 50, 15, 20 }, Jelly_Base::agar_agar, 15);
	JellyDessert jellyDessert2(false, "Banana", Taste::sweet, 250, NutritValue{ 100, 50, 15, 20 }, Jelly_Base::pectin, 10);
	JellyDessert jellyDessert3(false, "Malinovoe", Taste::sweet_and_sour, 350, NutritValue{ 100, 55, 15, 50 }, Jelly_Base::jellatin, 5);

	Array_Desserts<Dessert> d;
	d.Add_(&bake);
	d.Add_(&bake2);
	d.Add_(&bake3);

	d.Add_(&jellyDessert);
	d.Add_(&jellyDessert2);
	d.Add_(&jellyDessert3);
	d.sort_arr();
	d.Not_Glucose_Max_Carbohydrates();
	d.No_Flavour_And_Min_Time_Of_Baking();
	d.Sweet_Sour_Taste_And_Max_Kkal();
	
	Array_Desserts<unique_ptr<Dessert>> list_dessert1;
	unique_ptr<Dessert> UniqPtrDessert1(new Bake(bake));
	unique_ptr<Dessert> UniqPtrDessert2(new Bake(bake2));
	unique_ptr<Dessert> UniqPtrDessert3(new Bake(bake3));
	unique_ptr<Dessert> UniqPtrDessert4(new Bake(bake4));

	unique_ptr<Dessert> UniqPtrDessert5(new JellyDessert(jellyDessert));
	unique_ptr<Dessert> UniqPtrDessert6(new JellyDessert(jellyDessert2));
	unique_ptr<Dessert> UniqPtrDessert7(new JellyDessert(jellyDessert3));

	list_dessert1.Add_(&UniqPtrDessert1);
	list_dessert1.Add_(&UniqPtrDessert2);
	
	cout << "unique_ptr" << endl;
	unique_ptr<Dessert> bb;
	bb = std::move(UniqPtrDessert1);
	bb.get()->Print();
	cout << "UniqPtrDessert1 is " << (static_cast<bool>(UniqPtrDessert1) ? "not null\n" : "null\n");
	cout << "bb is " << (static_cast<bool>(bb) ? "not null\n" : "null\n");

	auto_ptr<Dessert> AutoPtrDessert1(new Bake(bake));
	auto_ptr<Dessert> AutoPtrDessert2(new JellyDessert(jellyDessert));
	
	cout << "auto_ptr" << endl;
	Array_Desserts<auto_ptr<Dessert>> list_dessert2;
	list_dessert2.Add_(&AutoPtrDessert1);
	list_dessert2.Add_(&AutoPtrDessert2);
	for (auto &dess : list_dessert2)
	{
		dess->get()->Print();
	}
	 
	
	cout << endl << endl;

	cout << "shared_ptr" << endl;
	shared_ptr<Dessert> SharedPtrDessert1(new Bake(bake));
	shared_ptr<Dessert> SharedPtrDessert2(new JellyDessert(jellyDessert));
	Array_Desserts<shared_ptr<Dessert>> list_dessert3;
	list_dessert3.Add_(&SharedPtrDessert1);
	list_dessert3.Add_(&SharedPtrDessert2);


	cout << "weak_ptr" << endl;
	Array_Desserts<weak_ptr<Dessert>> list_dessert4;
	weak_ptr<Dessert> WeakPtrDessert1 = SharedPtrDessert1;
	weak_ptr<Dessert> WeakPtrDessert2 = SharedPtrDessert2;
	list_dessert4.Add_(&WeakPtrDessert1);
	list_dessert4.Add_(&WeakPtrDessert2);

	cout << endl << endl;
	

	
	cout << "Desserts:" << endl;
	for (Dessert*& dessert : d) 
	{
		dessert->Print();
	}
	
	return 0;
}
