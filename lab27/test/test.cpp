#include "desserts_arr.h"

void test1()
{
    /*glucose, name, taste, weight, nutrit, time, isflavour*/
	Bake bake(false, "Sharlotka", Taste::sweet, 350, NutritValue{ 100, 50, 15, 20 }, 2, true);
	Bake bake2(true, "Kruasan", Taste::chocolate, 350, NutritValue{ 100, 50, 15, 20 }, 2, false);
	Bake bake3(false, "Napaleon", Taste::creamy, 350, NutritValue{ 100, 50, 15, 20 }, 2, true);

	/*glucose, name, taste, weight dessert, nutrit, jelly base, weight jelly base*/
	JellyDessert jellyDessert(true, "Klubnichnoe", Taste::sweet, 350, NutritValue{ 100, 50, 15, 20 }, Jelly_Base::agar_agar, 15);
	JellyDessert jellyDessert2(false, "Banana", Taste::sweet, 350, NutritValue{ 100, 50, 15, 20 }, Jelly_Base::pectin, 10);
	JellyDessert jellyDessert3(false, "Malinovoe", Taste::sweet_and_sour, 350, NutritValue{ 100, 55, 15, 20 }, Jelly_Base::jellatin, 5);

	Array_Desserts list;
	list.Add_Dessert(&bake);
	list.Add_Dessert(&bake2);
	list.Add_Dessert(&bake3);
	list.Add_Dessert(&jellyDessert);
	list.Add_Dessert(&jellyDessert2);
	list.Add_Dessert(&jellyDessert3);

    if(list[1] == list.No_Flavour_And_Min_Time_Of_Baking_copy())
    {
        cout<<"result == expectation"<<endl;
    }
    else
    {
        cout<<"result != expectation"<<endl;
    }
	
	
	
}

int main()
{
    test1();
    return 0;
}