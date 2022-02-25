#include<stdio.h>
#include <string.h>
#include<stdlib.h>
#include"Header.h"

struct material
{
	int number;
	char nameOfMaterial[40];
	char type[40];
	int amount;
	int money;
};
static material* inf;
static material* temp;
int sizeOfStruct;
extern void vvod()
{
	register int counter;
	int k;
	printf("Как много видов сырья вы хотите ввести?");
	scanf_s("%d", &sizeOfStruct);
	inf = (struct material*)malloc(sizeOfStruct * sizeof(struct material));
	temp = (struct material*)malloc(sizeOfStruct * sizeof(struct material));
	for (counter = 0; counter < sizeOfStruct; counter++)
	{
		do
		{
			rewind(stdin);
			printf("\nВведите номер материала: ");
			k = scanf_s("%d", &inf[counter].number);
		} while (!k);

		printf("\nВведите наименование материала: ");
		rewind(stdin);
		gets_s((inf + counter)->nameOfMaterial);
		printf("\nВведите тип материала: ");
		rewind(stdin);
		gets_s((inf + counter)->type);
		do
		{
			rewind(stdin);
			printf("\nВведите количество материала: ");
			k = scanf_s("%d", &(inf + counter)->amount);
		} while (!k);
		do
		{
			rewind(stdin);
			printf("\nВведите стоимость материала: ");
			k = scanf_s("%d", &(inf + counter)->money);
		} while (!k);
	}
}
extern void read()
{
	register int counter;
	printf("\n\n\n\n\n");
	printf("Number   Name of material      Type     Amount     Money\n");
	printf("========================================================\n");
	for (counter = 0; counter < sizeOfStruct; counter++)
	{
		printf("|%5d|%18s|%11s|%8d|%8d|", (inf + counter)->number, (inf + counter)->nameOfMaterial, (inf + counter)->type, (inf + counter)->amount, (inf + counter)->money);
		printf("\n");
	}
	printf("========================================================\n");
	printf("\n");
}
extern void sort_nomer()
{
	register int counter1, counter2;
	for (counter1 = 1; counter1 < sizeOfStruct; counter1++) for (counter2 = sizeOfStruct - 1; counter2 >= counter1; counter2--)
	{
		if ((inf + counter2 - 1)->number > (inf + counter2)->number)
		{
			temp[counter2] = inf[counter2 - 1];
			inf[counter2 - 1] = inf[counter2];
			inf[counter2] = temp[counter2];
		}
	}
	printf("Список отсортирован\n");
}
extern void sort_name()
{
	register int counter1, counter2;
	for (counter1 = 1; counter1 < sizeOfStruct; counter1++) for (counter2 = sizeOfStruct - 1; counter2 >= counter1; counter2--)
	{
		if (strcmp((inf + counter2 - 1)->nameOfMaterial, (inf + counter2)->nameOfMaterial) > 0)
		{
			temp[counter2] = inf[counter2 - 1];
			inf[counter2 - 1] = inf[counter2];
			inf[counter2] = temp[counter2];
		}
	}
	printf("Список отсортирован\n");
}
extern void sort_amount()
{
	register int counter1, counter2;
	for (counter1 = 1; counter1 < sizeOfStruct; counter1++) for (counter2 = sizeOfStruct - 1; counter2 >= counter1; counter2--)
	{
		if ((inf + counter2 - 1)->amount > (inf + counter2)->amount)
		{
			temp[counter2] = inf[counter2 - 1];
			inf[counter2 - 1] = inf[counter2];
			inf[counter2] = temp[counter2];
		}
	}
	printf("Список отсортирован\n");
}
extern void sort_money()
{
	register int counter1, counter2;
	for (counter1 = 1; counter1 < sizeOfStruct; counter1++) for (counter2 = sizeOfStruct - 1; counter2 >= counter1; counter2--)
	{
		if ((inf + counter2 - 1)->money > (inf + counter2)->money)
		{
			temp[counter2] = inf[counter2 - 1];
			inf[counter2 - 1] = inf[counter2];
			inf[counter2] = temp[counter2];
		}
	}
	printf("Список отсортирован\n");
}
extern void sort_type()
{
	register int counter1, counter2;
	for (counter1 = 1; counter1 < sizeOfStruct; counter1++) for (counter2 = sizeOfStruct - 1; counter2 >= counter1; counter2--)
	{
		if (strcmp((inf + counter2 - 1)->type, (inf + counter2)->type) > 0)
		{
			temp[counter2] = inf[counter2 - 1];
			inf[counter2 - 1] = inf[counter2];
			inf[counter2] = temp[counter2];
		}
	}
	printf("Список отсортирован\n");
}
int menu()
{
	int choise;
	printf("1. Сортировка по номеру. \n");
	printf("2. Сортировка по названию.\n");
	printf("3. Сортировка по типу.\n");
	printf("4. Сортировка по количеству\n");
	printf("5. Сортировка по стоимости.\n");
	printf("Ваш выбор:");
	scanf_s("%d", &choise);
	return choise;
}
extern void sort()
{
	do
	{
		switch (menu())
		{
		case 1: sort_nomer();
			break;
		case 2: sort_name();
			break;
		case 3: sort_type();
			break;
		case 4: sort_amount();
			break;
		case 5: sort_money();
			break;
		}
	} while (0);
}
extern void dopolnenie()
{
	int google;
	register int counter = sizeOfStruct;
	printf("Сколько вы хотите дополнить");
	scanf_s("%d", &google);
	sizeOfStruct += google;
	inf = (struct material*)realloc(inf, sizeOfStruct * sizeof(struct material));
	temp = (struct material*)realloc(temp, sizeOfStruct * sizeof(struct material));
	int k;
	for (counter; counter < sizeOfStruct; counter++)
	{
		do
		{
			rewind(stdin);
			printf("\nВведите номер материала: ");
			k = scanf_s("%d", &inf[counter].number);
		} while (!k);

		printf("\nВведите наименование материала: ");
		rewind(stdin);
		gets_s((inf + counter)->nameOfMaterial);
		printf("\nВведите тип материала: ");
		rewind(stdin);
		gets_s((inf + counter)->type);
		do
		{
			rewind(stdin);
			printf("\nВведите количество материала: ");
			k = scanf_s("%d", &(inf + counter)->amount);
		} while (!k);
		do
		{
			rewind(stdin);
			printf("\nВведите стоимость материала: ");
			k = scanf_s("%d", &(inf + counter)->money);
		} while (!k);
	}
}

