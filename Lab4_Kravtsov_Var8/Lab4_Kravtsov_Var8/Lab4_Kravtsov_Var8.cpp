/*
Кравцов Владислав Дмитриевич
Лабораторная работа №4.
Вариант №8
Задание:Написать программу, которая во вводимом тексте удалит все пробелы,
знаки табуляции и выведет количество удаленных символов на экран.
*/


#include"stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <conio.h>
#include <cstring>
#define _CRT_SECURE_NO_WARNINGS


void SearchWords(char *words) // получение указателя на массив
{
	char *p; // указатель на массив
	for (int i = 0; i < strlen(words); i++)	// в цикле рассматривает все слова
	{
		if (words[i] == '\n') 		// проверят по строкам 
		{
			words[i] = ' ';		// если встречаем символ перехода на новую строку (\n) заменяем на пробел. 			
		}						// То есть все слова из разных строк записываются в одну 
	}
	int count = 0;
	p = strtok(words, " ");
	FILE *Output = fopen("Output.txt", "w");
	while (p != NULL) // пока не законяатся слова
	{
		int count = 0; // колличество M в слове
		for (int i = 0; i<strlen(p); i++)			//поиск в слове "М"
		{											//
			if ((p[i] != ' ') || (p[i] != '\v') || (p[i] != '\t'))		//
			{										//
				fprintf(Output, "%c", p[i]);	
				count++;
			}										//
		}											//
		//p = strtok(NULL, " "); // перейти к следующему слову
	}
	fprintf(Output, "\n Count of deleted: %d", count);
	fclose(Output); // закрыли указатель 
}

int main(void)
{
	char *words; // указатель на массив 
	int TextLength = 0; // длина всего текста(кол-во символов)
	FILE *Inp = fopen_s("Input.txt", "r"); // создали указатель и открыли файл для чтения
	if (Inp == NULL) // если в файле ничего нет, то выдаст сообщение "нет данных
	{
		printf("No data!");
		return 0;
	}
	fscanf_s(Inp, "%d", &TextLength); // считывает количество символов из файла
	words = (char*)malloc((TextLength) * sizeof(char)); // выделение памяти на массив
	fread(words, sizeof(char), TextLength, Inp); // считывает все слова из файла
	fclose(Inp); //закрывает указатель 
	SearchWords(words); // вызов функции
	return 0;
}