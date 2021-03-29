/*!
	\brief Лабораторна робота 15, 17
	\author Гуджуманюк Ксенія
	\version 1.0
	\date 29/03/2021
	\warning Тема 15 лабораторної роботи - структури, 17 - модульні тести

	Обычный дочерний класс, который отнаследован от ранее созданного класса Parent
*/


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

struct NutritVal {
	float kKal;
	float bilky;
	float zhyry;
	float carbohydrates;
};

struct Dessert {
	bool is_glucose;
	char name_dessert[20];
	float weight;
	struct NutritVal nutrit;
	char taste[20];
};

/*!
Записує структуру у бінарний файл
\param[out] - Функція повертає 0
\param[in] desserts[] Структура для запису у файл
\param[in] number_of_desserts Кількість елементів масиву структур
*/
int Write_To_Binary_File(struct Dessert desserts[], int number_of_desserts);

/*!
Читає структуру з бінарного файлу
\param[out] - Функція повертає 0
\param[in] - Функція не приймає жодних значень
*/
int Read_From_Binary_File();


/*!
Функція пошуку елемента масиву структур в бінарному файлі
\param[out] - Функція повертає 0
\param[in] index_search Індекс для пошуку структури
*/
int Search_by_Index_in_Binary_File(int index_search);

/*!
Копія функції для пошуку елемента масиву структур в бінарному файлі
\param[out] desserts[] Функція повертає дану структуру
\param[in] index_search Індекс для пошуку структури
*/
struct Dessert* Copy_Search_by_Index_in_Binary_File(struct Dessert desserts[], int index_search);

/*!
Сортування масиву структур за назві десерту
\param[out] - Функція не повертає жодного значення
\param[in] desserts[] Масив структур для сортування
\param[in] number_of_desserts Кількість елементів масиву структур
*/
void Sort_Name_Dessert(struct Dessert desserts[], int number_of_desserts);

/*!
Копія функції сортування масиву структур за назвою
\param[out] desserts[] Функція повертає відсортований масив структур
\param[in] desserts[] Масив структур
\param[in] number_of_desserts Кількість структур у масиві структур
*/
struct Dessert* copy_Sort_Name_Dessert(struct Dessert desserts[], int number_of_desserts);

/*!
Сортування масиву структур за смаком (у алфавітному порядку)
\param[out] - функція не повертає жодного значення
\param[in] desserts[] Масив структур для сортування
\param[in] number_of_desserts Кількість елементів масиву структур
*/
void Sort_Taste_Dessert(struct Dessert desserts[], int number_of_desserts);

/*!
Виведення на екран піструктури
\param[out] - Функція не повертає жодного значення
\param[in] desserts Підструктура 
*/
void Print_NutritVal(struct NutritVal desserts);

/*!
Виведення на екран структури
\param[out] - функція не повертає жодного значення
\param[in] src Исходная область памяти
\param[in] number_of_desserts Кількість структур у масиві структур
*/
void Print_Dessert(struct Dessert desserts[], int number_of_desserts);

/*!
Запис структури у текстовий файл
\param[out] - Функція не повертає жодного значення
\param[in] name_file Шлях та назва файлу
\param[in] number_of_desserts Кількість структур у масиві структур
*/
void Write_To_File(char* name_file, struct Dessert desserts[], int number_of_desserts);

/*!
Читання структури з текстового файлу
\param[out] desserts[] Функція повертає масив структур
\param[in] name_file Шлях та назва файлу
\param[in] desserts[] Структура для запису результату читання з файлу
\param[in] number_of_desserts Кількість структур у масиві структур
*/
struct Dessert* Read_From_File(char* name_file, struct Dessert desserts[], int number_of_desserts);

void Sort_Carbohydrates_Dessert(struct Dessert desserts[], int number_of_desserts);
void Sort_Zhyry_Dessert(struct Dessert desserts[], int number_of_desserts);
void Sort_Bilky_Dessert(struct Dessert desserts[], int number_of_desserts);
void Sort_Kkal_Dessert(struct Dessert desserts[], int number_of_desserts);
void Sort_Weight_Dessert(struct Dessert desserts[], int number_of_desserts);
void Sort_Weight2_Dessert(struct Dessert desserts[], int number_of_desserts);