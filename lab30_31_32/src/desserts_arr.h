#include "dessert.h"
#include <algorithm>
#include <typeinfo>
using std::sort;


template <class T>
class Array_Desserts {
	vector<T*> Desserts;
	int index = 6;
	size_t SIZE;
	typedef typename vector<T*>::iterator iter;
public:
	iter begin()
	{
		return Desserts.begin();
	}

	iter end()
	{
		return Desserts.end();
	}

	Array_Desserts()
	{

	}

	Array_Desserts(size_t size)
	{
		SIZE = size;
		Desserts.resize(size);
	}

	void Add_(T* smth)
	{
		Desserts.push_back(smth);
	}

	~Array_Desserts()
	{

	}

	Array_Desserts & operator=(const Array_Desserts& copy) 
	{
		if (this == &copy)
			return *this;
		while (index >= 0) {
			delete Desserts[index];
			index--;
		}
		for (int i = 0; i <= copy.index; i++) {
			Desserts[i] = copy.Desserts[i]->clone();
		}
		index = copy.index;
		return *this;
	}

	Dessert* GetDessert(int index) const
	{
		return Desserts.at(index);
	}

	void Iter()
	{
		vector<Dessert>::iterator iter;
		for (Dessert* &iter : Desserts)
		{
			cout << "Cool!!!" << endl;
		}
	}

	void Show_Array()
	{
		int i = 0;
		int e = Desserts.size();
		while (i < e)
		{
			if (i == 0) 
			{ 
				cout << "\33[1:34mBake\33[0m\n"; 
			}
			if (i == 3) 
			{ 
				cout << "\33[1:34mJelly dessert\33[0m\n"; 
			}
			cout << "\33[1:33mDessert " << i + 1 << ":\33[0m\n";
			Desserts.at(i)->Print();
			cout << endl;
			i++;
		}
	}

	void Not_Glucose_Max_Carbohydrates()
	{
			double max = 0;
			size_t index_of_max_element;
			for (size_t i = 0; i < ARRAY_SIZE; i++)
			{
				if (Desserts.at(i)->Weight_of_Carbohydrates_in_NoGlucose_Desserts() != 0)
				{
					double tmp = Desserts.at(i)->Weight_of_Carbohydrates_in_NoGlucose_Desserts();
					size_t index_tmp = i;
					if (max < tmp)
					{
						max = tmp;
						index_of_max_element = index_tmp;
					}
				}
			}
			cout << "Non-glucose dessert with max carbohydrates:" << endl;
			Desserts.at(index_of_max_element)->Print();
	}

	void Sweet_Sour_Taste_And_Max_Kkal()
	{
			double max = 0;
			size_t index_of_max_element;
			for (size_t i = 0; i < ARRAY_SIZE; i++)
			{
				if (Desserts.at(i)->IsItSweetSour())
				{
					double tmp = Desserts[i]->IsItSweetSour();
					size_t index_tmp = i;
					if (max < tmp)
					{
						max = tmp;
						index_of_max_element = index_tmp;
					}
				}
			}
			cout << "Dessert with sweet and sour taste and max kkal:" << endl;
			Desserts.at(index_of_max_element)->Print();
	}

	void No_Flavour_And_Min_Time_Of_Baking()
	{
			double min_time = 1000;
			size_t index_of_dessert_with_min_time_of_baking;
			for (size_t i = 0; i < ARRAY_SIZE; i++)
			{
				if (Desserts[i]->Bake_IsItFlour())
				{
					double tmp = Desserts[i]->Bake_IsItFlour();
					size_t index_tmp = i;
					if (min_time > tmp)
					{
						min_time = tmp;
						index_of_dessert_with_min_time_of_baking = index_tmp;
					}
				}
			}
			cout << "Non-flavour dessert with min time of baking:" << endl;
			Desserts[index_of_dessert_with_min_time_of_baking]->Print();
	}

	
	Array_Desserts combine_arrays(Array_Desserts v1, Array_Desserts v2)
	{
		Array_Desserts res;
		for (size_t i = 0; i < 6; i++)
		{
			Dessert* tmp = v1.GetDessert(i);
			res.Add_(tmp);
		}
		res.Add_(v2.GetDessert(0));
		return res;
	}

	struct compare 
	{
		bool operator()(Dessert* i, Dessert* j)
		{
			return (i->getWeight_() < j->getWeight_());
		}
	}cc;

	void sort_arr()
	{
		sort(Desserts.begin(), Desserts.end(), cc);
	}

};

