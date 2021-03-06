/*

Кравцов Владислав Дмитриевич
Лабораторная работа №4.
Вариант №8
Задание. Написать программу, которая записывает с клавиатуры в файл структуру
согласно выданному варианту задания. В качестве разделителя полей структуры
использовать символ табуляции. В программе реализовать:
а) дополнение существующего массива структур новыми структурами;
б) поиск структуры с заданным значением выбранного элемента;
в) вывод на экран содержимого массива структур;
г) упорядочение массива структур по заданному полю (элементу), например
государство по численности.

8. «Фильм»: название, режиссер (фамилия, имя, отчество), страна, год выпуска,
стоимость (расходы на выпуск), кассовые сборы (доход).

*/

#include "stdafx.h"
#include<string>

struct Date
{
	int day;
	int month;
	int year;
};

struct Dir
{
	char name[100];
	char surname[100];
	char dadname[100];
};

struct Mov
{
	char name[100];
	char country[100];
	int price;
	int proffit;
	Date dt;
	Dir director;
};

int findFilmName(Mov*, int);
int findDirectorSurname(Mov*, int);
int findDirectorName(Mov*, int);
int findDirectorDadname(Mov*, int);
int findFilmDate(Mov*, int);
int findFilmPrice(Mov*, int);
int findFilmProffit(Mov*, int);
int findFilmCountry(Mov*, int);
int commandFind(Mov*, int, int);
int findDirector(Mov*, int, int);
void commandExecution(Mov*, int, int);
void commandSort(Mov*, int, int);
void sortPrice(Mov*, int);
void sortProffit(Mov*, int);
void sortDate(Mov*, int);
void getFilms(Mov*, int);
void printFilms(Mov*, int);



int main(){
	struct Mov Movie[100];
	int n, command = 0;

	printf_s("Enter count of films: ");
	scanf_s("%d", &n);
	getFilms(Movie, n);
	printFilms(Movie, n);
	while (command != 4) {
		printf_s("\nChoose command:\n1. To find a film type '1'\n2. To sort films type '2'\n3. To print all films type '3'\n4. To exit type '4'\nCommand: ");
		scanf_s("%d", &command);
		commandExecution(Movie, command, n);
		}
	return 0;
}

int findFilmName(Mov *Movie, int n)
{
	char object_of_finding[100], s[100];
	int len, k = 0;
	bool find = false;
	printf_s("\nType a film name: ");
	fgets(s, 100, stdin);
	fgets(object_of_finding, 100, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].name[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findDirectorSurname(Mov *Movie, int n)
{
	char object_of_finding[100], s[100];
	int len, k = 0;
	bool find = false;
	printf_s("\nType a directors surname: ");
	fgets(s, 100, stdin);
	fgets(object_of_finding, 100, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.surname[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findDirectorName(Mov *Movie, int n)
{
	char object_of_finding[100], s[100];
	int len, k = 0;
	bool find = false;
	printf_s("\nType a directors name: ");
	fgets(s, 100, stdin);
	fgets(object_of_finding, 100, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.name[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findDirectorDadname(Mov *Movie, int n)
{
	char object_of_finding[100], s[100];
	int len, k = 0;
	bool find = false;
	printf_s("\nType a directors dadname: ");
	fgets(s, 100, stdin);
	fgets(object_of_finding, 100, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].director.dadname[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findFilmDate(Mov *Movie, int n)
{
	int day, month, year;
	bool find = false;
	printf_s("\nType date: ");
	scanf_s("%d %d %d", &day, &month, &year);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].dt.day == day && Movie[i].dt.month == month && Movie[i].dt.year)
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findFilmPrice(Mov *Movie, int n) 
{
	int price;
	bool find = false;
	printf_s("\nType price: ");
	scanf_s("%d", &price);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].price == price)
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findFilmProffit(Mov * Movie, int n)
{
	int proffit;
	bool find = false;
	printf_s("\nType proffit: ");
	scanf_s("%d", &proffit);
	for (int i = 0; i < n; i++)
	{
		if (Movie[i].proffit == proffit)
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int findFilmCountry(Mov *Movie, int n)
{
	char object_of_finding[100], s[100];
	int len, k = 0;
	bool find = false;
	printf_s("\nType a country: ");
	fgets(s, 100, stdin);
	fgets(object_of_finding, 100, stdin);
	len = strlen(object_of_finding);
	object_of_finding[len - 1] = '\0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < strlen(object_of_finding); j++)
		{
			if (Movie[i].country[j] == object_of_finding[j])
			{
				k++;
			}
		}
		if (k == strlen(object_of_finding))
		{
			printf_s("\n====================================");
			printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
			printf_s("\n====================================\n");
			find = true;
		}
	}
	return find;
}
int commandFind(Mov *Movie, int command_to_find, int n)
{
	int command_to_find2 = 0;
	bool find = false;

	switch (command_to_find) {
	case 1: { find = findFilmName(Movie, n); break; }
	case 2: {
		printf_s("\nCommand accepted.\nTo find in directors surname type '1'\nTo find in directors name type '2'\nTo find in directors dadsname type '3'\nCommand: ");
		scanf_s("%d", &command_to_find2);
		find = findDirector(Movie, command_to_find2, n);
		break;
	}
	case 3: { find = findFilmDate(Movie, n); break; }
	case 4: { find = findFilmPrice(Movie, n); break; }
	case 5: { find = findFilmProffit(Movie, n); break; }
	case 6: { find = findFilmCountry(Movie, n); break; }
	default: { printf("\nWrong command!"); }
	}
	return !find;
}
int findDirector(Mov *Movie, int command_to_find2, int n)
{
	bool find = false;

	switch (command_to_find2) {
	case 1: { find = findDirectorSurname(Movie, n);  break; }
	case 2: { find = findDirectorName(Movie, n); break; }
	case 3: { find = findDirectorDadname(Movie, n); break; }
	default: {printf_s("\nWrong command!\n"); }
	}
	return find;
}
void commandExecution(Mov *Movie, int command, int n)
{
	int command_to_find = 0, command_to_find2 = 0, command_to_sort = 0;
	bool find = false;
	switch (command) {
	case 1: {
		printf("\n\nCommand accepted.\nNow choose aim of searching:\nTo find in film names type '1'\nTo find in director names/surnames/dadnames type '2'\nTo find in date type'3'\nTo find in price type '4'\nTo find in proffit type '5'\nTo find in country type '6'\nCommand: ");
		scanf_s("%d", &command_to_find);
		
		if (commandFind(Movie, command_to_find, n)) {
			printf_s("\n====================================\n");
			printf("No results!");
			printf_s("\n====================================\n");
		}
		find = false;
		break;
	}
	case 2: {
		printf_s("\nCommand accepted.\nTo sort in price type '1'\nTo sort in proffit type '2'\nTo sort in date type '3'\nCommand: ");
		scanf_s("%d", &command_to_sort);
		commandSort(Movie, command_to_sort, n);
		break;
	}
	case 3: { printFilms(Movie, n); break; }
	case 4: { printf_s("\nCommand accepted. Goodbye!\n\n"); break; }
	default: { printf("\nWrong command!\n"); }
	}
}
void commandSort(Mov *Movie, int command_to_sort, int n)
{
	switch (command_to_sort)
	{
	case 1: { sortPrice(Movie, n); break; }
	case 2: { sortProffit(Movie, n); break; }
	case 3: { sortDate(Movie, n); break; }
	}
}
void sortPrice(Mov *Movie, int n)
{
	char vs[100];
	int v;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].price > Movie[j + 1].price)
			{
				v = Movie[j].price;
				Movie[j].price = Movie[j + 1].price;
				Movie[j + 1].price = v;

				v = Movie[j].proffit;
				Movie[j].proffit = Movie[j + 1].proffit;
				Movie[j + 1].proffit = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].country);
				strcpy_s(Movie[j].country, Movie[j + 1].country);
				strcpy_s(Movie[j + 1].country, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}
}
void sortProffit(Mov *Movie, int n)
{
	int v;
	char vs[100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].proffit > Movie[j + 1].proffit)
			{
				v = Movie[j].price;
				Movie[j].price = Movie[j + 1].price;
				Movie[j + 1].price = v;

				v = Movie[j].proffit;
				Movie[j].proffit = Movie[j + 1].proffit;
				Movie[j + 1].proffit = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].country);
				strcpy_s(Movie[j].country, Movie[j + 1].country);
				strcpy_s(Movie[j + 1].country, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}
}
void sortDate(Mov *Movie, int n)
{
	int v;
	char vs[100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.year > Movie[j + 1].dt.year)
			{
				v = Movie[j].price;
				Movie[j].price = Movie[j + 1].price;
				Movie[j + 1].price = v;

				v = Movie[j].proffit;
				Movie[j].proffit = Movie[j + 1].proffit;
				Movie[j + 1].proffit = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].name);
				strcpy_s(Movie[j].name, Movie[j + 1].name);
				strcpy_s(Movie[j + 1].name, vs);

				strcpy_s(vs, Movie[j].country);
				strcpy_s(Movie[j].country, Movie[j + 1].country);
				strcpy_s(Movie[j + 1].country, vs);

				strcpy_s(vs, Movie[j].director.name);
				strcpy_s(Movie[j].director.name, Movie[j + 1].director.name);
				strcpy_s(Movie[j + 1].director.name, vs);

				strcpy_s(vs, Movie[j].director.surname);
				strcpy_s(Movie[j].director.surname, Movie[j + 1].director.surname);
				strcpy_s(Movie[j + 1].director.surname, vs);

				strcpy_s(vs, Movie[j].director.dadname);
				strcpy_s(Movie[j].director.dadname, Movie[j + 1].director.dadname);
				strcpy_s(Movie[j + 1].director.dadname, vs);
			}
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.month > Movie[j + 1].dt.month)
			{
				v = Movie[j].price;
				Movie[j].price = Movie[j + 1].price;
				Movie[j + 1].price = v;

				v = Movie[j].proffit;
				Movie[j].proffit = Movie[j + 1].proffit;
				Movie[j + 1].proffit = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].country);
				strcpy_s(Movie[j].country, Movie[j + 1].country);
				strcpy_s(Movie[j + 1].country, vs);
			}
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n - 1; j++)
		{
			if (Movie[j].dt.day > Movie[j + 1].dt.day)
			{
				v = Movie[j].price;
				Movie[j].price = Movie[j + 1].price;
				Movie[j + 1].price = v;

				v = Movie[j].proffit;
				Movie[j].proffit = Movie[j + 1].proffit;
				Movie[j + 1].proffit = v;

				v = Movie[j].dt.day;
				Movie[j].dt.day = Movie[j + 1].dt.day;
				Movie[j + 1].dt.day = v;

				v = Movie[j].dt.month;
				Movie[j].dt.month = Movie[j + 1].dt.month;
				Movie[j + 1].dt.month = v;

				v = Movie[j].dt.year;
				Movie[j].dt.year = Movie[j + 1].dt.year;
				Movie[j + 1].dt.year = v;

				strcpy_s(vs, Movie[j].country);
				strcpy_s(Movie[j].country, Movie[j + 1].country);
				strcpy_s(Movie[j + 1].country, vs);
			}
		}
}
void getFilms(Mov *Movie, int n)
{
	for (int i = 0; i < n; i++)
	{
		char s[100];
		int len;
		printf_s("\n[ %d film ]\n", i + 1);
		printf_s("\nEnter film name: ");
		fgets(s, 100, stdin);
		fgets(Movie[i].name, 100, stdin);
		len = strlen(Movie[i].name);
		Movie[i].name[len - 1] = '\0';
		printf("\nEnter country: ");
		fgets(Movie[i].country, 100, stdin);
		printf("\nEnter surname of director: ");
		fgets(Movie[i].director.surname, 100, stdin);
		printf("\nEnter name of director: ");
		fgets(Movie[i].director.name, 100, stdin);
		printf("\nEnter dadsname of director: ");
		fgets(Movie[i].director.dadname, 100, stdin);
		printf("\nEnter date: ");
		scanf_s("%d %d %d", &Movie[i].dt.day, &Movie[i].dt.month, &Movie[i].dt.year);
		printf("\nEnter film price (in mln $): ");
		scanf_s("%d", &Movie[i].price);
		printf("\nEnter film proffit (in mln $): ");
		scanf_s("%d", &Movie[i].proffit);
	}
}
void printFilms(Mov* Movie, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("\n====================================");
		printf_s("\n[ %d film ]\n", i + 1);
		printf_s("\nFilm: %s\nDate: %d.%d.%d \nCountry: %sSurname: %sName: %sDadsname: %sFilm price (in mln $): %d \nFilm proffit (in mln $): %d", Movie[i].name, Movie[i].dt.day, Movie[i].dt.month, Movie[i].dt.year, Movie[i].country, Movie[i].director.surname, Movie[i].director.name, Movie[i].director.dadname, Movie[i].price, Movie[i].proffit);
		printf("\n====================================\n");
	}
}