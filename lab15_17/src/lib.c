#include <lib.h>


int Write_To_Binary_File(struct Dessert desserts[], int number_of_desserts) {
	FILE* myfile;
	char* c;

	// число записываемых байтов
	int size = number_of_desserts * (int)sizeof(struct Dessert);

	if ((myfile = fopen("/home/ksen/new_reposit/lab15, 17/Desserts.bin", "wb")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	// записываем количество структур
	c = (char*)& number_of_desserts;
	for (int i = 0; i < (int)sizeof(int); i++)
	{
		putc(*c++, myfile);
	}

	// посимвольно записываем в файл все структуры
	c = (char*)desserts;
	for (int i = 0; i < size; i++)
	{
		putc(*c, myfile);
		c++;
	}
	fclose(myfile);
	return 0;
}

int Read_From_Binary_File() {
	FILE* myfile;
	char* c;
	int m = sizeof(int);
	int number_of_elements, i;

	// выделяем память для количества данных
	int* pti = (int*)malloc((unsigned long)m);

	if ((myfile = fopen("/home/ksen/new_reposit/lab15, 17/Desserts.bin", "r")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	// считываем количество структур
	c = (char*)pti;
	while (m > 0)
	{
		i = getc(myfile);
		if (i == EOF) break;
		*c = (char)i;
		c++;
		m--;
	}
	//получаем число элементов
	number_of_elements = *pti;

	
	struct Dessert* ptr = (struct Dessert*) malloc((unsigned long)number_of_elements * sizeof(struct Dessert));
	c = (char*)ptr;
	// после записи считываем посимвольно из файла
	while ((i = getc(myfile)) != EOF)
	{
		*c = (char)i;
		c++;
	}
	
	printf("\n%d desserts in the file stored\n\n", number_of_elements);

	for (int k = 0; k < number_of_elements; k++)
	{
		printf("%-5d %-20s %5f %f %f %f %f %-20s\n", k + 1, (ptr + k)->name_dessert, (ptr + k)->weight, (ptr + k)->nutrit.kKal, (ptr+k)->nutrit.bilky, (ptr+k)->nutrit.zhyry, (ptr+k)->nutrit.carbohydrates, (ptr+k)->taste);
	}

	free(pti);
	free(ptr);
	fclose(myfile);
	return 0;
}

struct Dessert* copy_Search_by_Index_in_Binary_File(struct Dessert desserts[], int number_of_desserts, int index_search) {
	FILE* myfile = fopen("/home/ksen/new_reposit/lab15, 17/Desserts.bin", "rb");
    struct Dessert* tmp = (struct Dessert*)malloc(sizeof(struct Dessert));
	if (myfile != NULL) {
		printf("Binary file opened success for reading!!!\n");
		for (int i = 0; i < number_of_desserts; i++) {
			if (i == index_search) {
				fread(&desserts[i].is_glucose, sizeof(bool), 1, myfile);
				
				fread(desserts[i].name_dessert, sizeof(char), strlen(desserts[i].name_dessert) + 1, myfile);
				
				fread(&(desserts[i].weight), sizeof(float), 10, myfile);
				
				fread(&desserts[i].nutrit.kKal, sizeof(float), 10, myfile);
				
				fread(&desserts[i].nutrit.bilky, sizeof(float), 10, myfile);
				
				fread(&desserts[i].nutrit.zhyry, sizeof(float), 10, myfile);
				
				fread(&desserts[i].nutrit.carbohydrates, sizeof(float), 10, myfile);
				
				fread(desserts[i].taste, sizeof(char), strlen(desserts[i].taste) + 1, myfile);
				
				printf("\nReading from binary search file: %s %.2f %.2f %.2f %.2f %.2f %s\n", desserts[i].name_dessert, desserts[i].weight, desserts[i].nutrit.kKal, desserts[i].nutrit.bilky, desserts[i].nutrit.zhyry, desserts[i].nutrit.carbohydrates, desserts[i].taste);
				
				
				tmp->is_glucose = desserts[i].is_glucose;
				strcpy(tmp->name_dessert, desserts[i].name_dessert);
				tmp->weight = desserts[i].weight;
				tmp->nutrit.kKal = desserts[i].nutrit.kKal;
				tmp->nutrit.bilky = desserts[i].nutrit.bilky;
				tmp->nutrit.zhyry = desserts[i].nutrit.zhyry;
				tmp->nutrit.carbohydrates = desserts[i].nutrit.carbohydrates;
				strcpy(tmp->taste, desserts[i].taste);
				
				
			}
		}
	}
	else {
		printf("Binary cannot be opened for reading\n");
	}
	fclose(myfile);
    return tmp;
}

int Search_by_Index_in_Binary_File(int index_search) {
	FILE* myfile;
	char* c;
	int m = sizeof(int);
	int number_of_elements, i;

	// выделяем память для количества данных
	int* pti = (int*)malloc((unsigned long)m);

	if ((myfile = fopen("/home/ksen/new_reposit/lab15, 17/Desserts.bin", "r")) == NULL)
	{
		perror("Error occured while opening file");
		return 1;
	}
	// считываем количество структур
	c = (char*)pti;
	while (m > 0)
	{
		i = getc(myfile);
		if (i == EOF) break;
		*c = (char)i;
		c++;
		m--;
	}
	//получаем число элементов
	number_of_elements = *pti;

	struct Dessert* ptr = (struct Dessert*) malloc((unsigned long)number_of_elements * sizeof(struct Dessert));
	c = (char*)ptr;
	// после записи считываем посимвольно из файла
	while ((i = getc(myfile)) != EOF)
	{
		*c = (char)i;
		c++;
	}

	printf("\n%d desserts in the file stored\n\n", number_of_elements);

	for (int k = 0; k < number_of_elements; k++)
	{
		if(k==index_search)
		printf("%-5d %-20s %5f %f %f %f %f %-20s\n", k + 1, (ptr + k)->name_dessert, (ptr + k)->weight, (ptr + k)->nutrit.kKal, (ptr + k)->nutrit.bilky, (ptr + k)->nutrit.zhyry, (ptr + k)->nutrit.carbohydrates, (ptr + k)->taste);
	}

	free(pti);
	free(ptr);
	fclose(myfile);
	return 0;
}

struct Dessert* Copy_Search_by_Index_in_Binary_File(struct Dessert desserts[], int index_search) {
	FILE* myfile;
	char* c;
	int m = (int)sizeof(int);
	int number_of_elements, i;

	// выделяем память для количества данных
	int* pti = (int*)malloc((unsigned long)m);

	if ((myfile = fopen("/home/ksen/new_reposit/lab15, 17/Desserts.bin", "r")) == NULL)
	{
		perror("Error occured while opening file");
	}
	// считываем количество структур
	c = (char*)pti;
	while (m > 0)
	{
		i = getc(myfile);
		if (i == EOF) break;
		*c = (char)i;
		c++;
		m--;
	}
	//получаем число элементов
	number_of_elements = *pti;
	struct Dessert* ptr = (struct Dessert*) malloc((unsigned long)number_of_elements * sizeof(struct Dessert));
	c = (char*)ptr;
	// после записи считываем посимвольно из файла
	while ((i = getc(myfile)) != EOF)
	{
		*c = (char)i;
		c++;
	}

	struct Dessert* tmp = (struct Dessert*)malloc(sizeof(struct Dessert));
	for (int k = 0; k < number_of_elements; k++)
	{
		if (k == index_search) {
			
			tmp->is_glucose = desserts[k].is_glucose;
			strcpy(tmp->name_dessert, desserts[k].name_dessert);
			tmp->weight = desserts[k].weight;
			tmp->nutrit.kKal = desserts[k].nutrit.kKal;
			tmp->nutrit.bilky = desserts[k].nutrit.bilky;
			tmp->nutrit.zhyry = desserts[k].nutrit.zhyry;
			tmp->nutrit.carbohydrates = desserts[k].nutrit.carbohydrates;
			strcpy(tmp->taste, desserts[k].taste);
		}		
	}
	return tmp;
	free(pti);
	free(ptr);
	fclose(myfile);
}

void Sort_Name_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = 0; i < number_of_desserts; i++) {
		for (int j = 0; j < number_of_desserts; j++) {
			if (strcmp(desserts[j].name_dessert, desserts[j + 1].name_dessert) > 0) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}

struct Dessert* copy_Sort_Name_Dessert(struct Dessert desserts[], int number_of_desserts) {
	/*for (int i = 0; i < number_of_desserts; i++) {
		for (int j = 0; j < number_of_desserts; j++) {*/
    for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(desserts[j].name_dessert, desserts[j + 1].name_dessert) > 0) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
	return desserts;
}

void Sort_Taste_Dessert(struct Dessert desserts[], int number_of_desserts) {
    for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (strcmp(desserts[j].taste, desserts[j + 1].taste) > 0) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}

void Print_NutritVal(struct NutritVal desserts) {
	printf("kKal: %f\nBilky: %f\nZhyry: %f\nCarbohydrates: %f\n", desserts.kKal, desserts.bilky, desserts.zhyry, desserts.carbohydrates);
}

void Print_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = 0; i < number_of_desserts; i++) {
		if (desserts[i].is_glucose) {
			printf("Glucose: yes\n");
		}
		else {
			printf("Glucose: no\n");
		}
		printf("Name: %s\nWeight: %f\nTaste: %s\n", desserts[i].name_dessert, desserts[i].weight, desserts[i].taste);
		Print_NutritVal(desserts[i].nutrit);
		printf("\n--------------------------------\n");
	}
}

void Write_To_File(char* name_file, struct Dessert desserts[], int number_of_desserts) {
	FILE* myfile = fopen(name_file, "w");
	if (myfile != NULL) {
		printf("File is opened success for writing!!!");
		for (int i = 0; i < number_of_desserts; i++) {
			fprintf(myfile, "%d %s %f %f %f %f %f %s\n", desserts[i].is_glucose, desserts[i].name_dessert, desserts[i].weight, desserts[i].nutrit.kKal, desserts[i].nutrit.bilky, desserts[i].nutrit.zhyry, desserts[i].nutrit.carbohydrates, desserts[i].taste);
		}
	}
	else {
		printf("File cannot be opened");
	}
	fclose(myfile);
}

struct Dessert* Read_From_File(char* name_file, struct Dessert desserts[], int number_of_desserts) {
	FILE* myfile = fopen(name_file, "r");
	if (myfile != NULL) {
		printf("\nFile opened for reading!!!");
		for (int i = 0; i < number_of_desserts; i++) {
			fscanf(myfile, "%d", &desserts[i].is_glucose);
			fscanf(myfile, "%s", desserts[i].name_dessert);
			fscanf(myfile, "%f", &(desserts[i].weight));
			fscanf(myfile, "%f" , &desserts[i].nutrit.kKal);
			fscanf(myfile, "%f", &desserts[i].nutrit.bilky);
			fscanf(myfile, "%f", &desserts[i].nutrit.zhyry);
			fscanf(myfile, "%f" , &desserts[i].nutrit.carbohydrates);
			fscanf(myfile, "%s", desserts[i].taste);
			printf("\nReading from func file: %d %s %.2f %.2f %.2f %.2f %.2f %s\n", desserts[i].is_glucose, desserts[i].name_dessert, desserts[i].weight, desserts[i].nutrit.kKal, desserts[i].nutrit.bilky, desserts[i].nutrit.zhyry, desserts[i].nutrit.carbohydrates, desserts[i].taste);
			
		}
	}
	else {
		printf("File cannot be reading");
	}
	return desserts;
}

void Sort_Weight2_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (desserts[j].weight > desserts[j + 1].weight) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}

void Sort_Kkal_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (desserts[j].nutrit.kKal > desserts[j + 1].nutrit.kKal) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}

void Sort_Bilky_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (desserts[j].nutrit.bilky > desserts[j + 1].nutrit.bilky) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
	
}

void Sort_Zhyry_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (desserts[j].nutrit.zhyry > desserts[j + 1].nutrit.zhyry) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}

void Sort_Carbohydrates_Dessert(struct Dessert desserts[], int number_of_desserts) {
	for (int i = number_of_desserts - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (desserts[j].nutrit.carbohydrates > desserts[j + 1].nutrit.carbohydrates) {
				struct Dessert tmp = desserts[j];
				desserts[j] = desserts[j + 1];
				desserts[j + 1] = tmp;
			}
		}
	}
}


