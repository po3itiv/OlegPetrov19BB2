﻿#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <locale.h>

void zad1();
void zad2();
void zad3();
void zad4();

#define INFTY INT_MAX
int** M1, ** M2, ** M3;
int** m, ** m2;

int N = 5;


void main() {

	zad1();
	zad2();
	zad3();


	for (int i = N; i > 0; i--) {
		free(m[i]);

	}

	free(m);

	for (int i = N - 1; i > 0; i--) { // очищение памяти
		free(M1[i]);
		free(M2[i]);


	}
	free(M1);
	free(M2);


	for (int i = N - 2; i > 0; i--) {
		free(m2[i]);

	}

	free(m2);

}

void zad1() {

	setlocale(LC_ALL, "russian");

	printf("\n Укажите размер матрицы N*N: ");
	scanf_s("%d", &N);

	M1 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M1[i] = (int*)malloc(N * sizeof(int));
	}

	M2 = (int**)malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++)
	{
		M2[i] = (int*)malloc(N * sizeof(int));
	}


	srand(time(NULL));
	for (int i = 0; i < N; i++) // генерация матрицы M1
	{
		M1[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			M1[i][j] = rand() % 2;
			M1[j][i] = M1[i][j];


		}
	}

	for (int i = 0; i < N; i++) // генерация матрицы M2
	{
		M2[i][i] = 0;

		for (int j = i + 1; j < N; j++)
		{

			M2[i][j] = rand() % 2;
			M2[j][i] = M2[i][j];


		}
	}


	printf("\n 1. Вывод сгенерированных матриц смежности неореентированных графов\n ");

	for (int i = 0; i < N; i++) { // вывод матриц смежности

		printf("\n ");

		for (int j = 0; j < N; j++) {
			printf("%d", M1[i][j]);
		}


	}

	printf("\n ");

	for (int i = 0; i < N; i++) {

		printf("\n ");

		for (int j = 0; j < N; j++) {
			printf("%d", M2[i][j]);
		}


	}


	_getch();
}

void zad2()
{


	setlocale(LC_ALL, "russian");

	int c = 0, c2 = 0, bolsh = 0, mensh = 0;

	m = (int**)malloc((N + 1) * sizeof(int*)); // дублирование матрицы для редактирования
	for (int i = 0; i < (N + 1); i++)
	{
		m[i] = (int*)malloc((N + 1) * sizeof(int));
	}

	m2 = (int**)malloc((N - 1) * sizeof(int*)); // укороченная матрица 
	for (int i = 0; i < (N - 1); i++)
	{
		m2[i] = (int*)malloc((N - 1) * sizeof(int));
	}




	printf("\n\n 2. Какие вершины второй матрицы отождествить?\n");
	printf(" ");
	scanf_s("%d %d", &c, &c2);

	c = c - 1;
	c2 = c2 - 1;

	int i1 = 0, j = 0, j1 = 1, sch = 0;


	for (int i = 0; i < N; i++) // заполнение матрицы для редактирования элементами второй
	{
		for (int j = 0; j < N; j++)
		{
			m[i][j] = M2[i][j];
		}
	}


	for (int i = 0; i < N; i++) // отождествление
	{

		if ((bolsh + 1) >= N)
			break;

		if (i == 0)
		{
			for (int j = 0; j < N; j++)
			{
				if (c < c2)
				{
					m[c][j] = m[c][j] || m[c2][j]; // если второе значение больше первого
					m[j][c] = m[c][j];				// производится перенос из второго в первое
					bolsh = c2;
					m[c][c] = 1;						// устанавливаем связь самим с собой

				}

				else
				{
					m[c2][j] = m[c][j] || m[c2][j]; // иначе наоборот
					m[j][c2] = m[c2][j];
					bolsh = c;
					m[c2][c2] = 1;

				}
			}
		}


		else
		{


			for (i1 = bolsh; j < N; j++) // перенос в большую строку следующей строки
			{

				m[i1][j] = m[i1 + 1][j];

			}

			j = bolsh;

			for (i1 = 0; i1 < N; i1++) // перенос в больший столбец следующего столбца
			{

				m[i1][j] = m[i1][j + 1];

			}
			j = 0;

			bolsh++; // и так до талого
		}
	}



	for (int i = 0; i < (N - 1); i++) // заносим отредактированную матрицу в укороченную
	{
		for (j = 0; j < (N - 1); j++)
		{
			m2[i][j] = m[i][j];
		}
	}


	for (int i = 0; i < (N - 1); i++) // вывод
	{

		printf("\n ");

		for (int j = 0; j < (N - 1); j++)
		{
			printf("%d", m2[i][j]);
		}

	}


	//////////////////////////////////////////////////////////////////

	printf("\n\n 2. Какое ребро второй матрицы стянуть?\n");
	printf(" ");
	scanf_s("%d %d", &c, &c2);

	c = c - 1;
	c2 = c2 - 1;
	bolsh = 0;
	j = 0;

	if (M2[c][c2] == 0)

		printf("\n Стянуть ребро невозмножно. Нет связи.");

	else {


		for (int i = 0; i < N; i++) // по прошлой схеме
		{
			for (int j = 0; j < N; j++)
			{
				m[i][j] = M2[i][j];
			}
		}


		for (int i = 0; i < N; i++)
		{

			if ((bolsh + 1) >= N)
				break;

			if (i == 0)
			{
				for (int j = 0; j < N; j++)
				{
					if (c < c2)
					{
						m[c][j] = m[c][j] || m[c2][j]; // но без связи с собой
						m[j][c] = m[c][j];
						bolsh = c2;
						m[c][c] = 0;

					}

					else
					{
						m[c2][j] = m[c][j] || m[c2][j];
						m[j][c2] = m[c2][j];
						bolsh = c;
						m[c2][c2] = 0;

					}
				}
			}


			else
			{


				for (i1 = bolsh; j < N; j++)
				{

					m[i1][j] = m[i1 + 1][j];

				}

				j = bolsh;

				for (i1 = 0; i1 < N; i1++)
				{

					m[i1][j] = m[i1][j + 1];

				}
				j = 0;

				bolsh++;
			}
		}



		for (int i = 0; i < (N - 1); i++)
		{
			for (j = 0; j < (N - 1); j++)
			{
				m2[i][j] = m[i][j];
			}
		}


		for (int i = 0; i < (N - 1); i++)
		{

			printf("\n ");

			for (int j = 0; j < (N - 1); j++)
			{
				printf("%d", m2[i][j]);
			}

		}
	}

	///////////////////////////////////////////////////

	int N2 = N + 1;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			m[i][j] = M2[i][j];
		}
	}

	for (int i = 0; i < N2; i++) // заполнение нулями новой вершины
	{
		for (int j = 0; j < N2; j++)
		{
			if (m[i][j] < 0 || m[i][j] > 1)
				m[i][j] = 0;
		}
	}

	printf("\n\n 2. Какую вершину второй матрицы расщепить?\n");
	printf(" ");
	scanf_s("%d", &c);

	c = c - 1;
	int i = c;
	for (; i < N2; i++) // с места пересечения вершины матрицы
	{						// переносим все "1" в новую вершину
		if (m[c][i] == 1)
		{
			m[N2 - 1][i] = m[i][N2 - 1] = 1; //найденная "1" переносится в новую вершину
			m[c][i] = m[i][c] = 0;			// старый путь стирается

		}
		else
			m[N2 - 1][i] = m[i][N2 - 1] = 0;
	}


	m[N2 - 1][c] = m[c][N2 - 1] = 1; // связываем новую вершину со старой

	for (int i = 0; i < N2; i++) // вывод
	{

		printf("\n ");

		for (int j = 0; j < N2; j++)
		{
			printf("%d", m[i][j]);
		}

	}

	_getch();
}

void zad3()
{


	setlocale(LC_ALL, "russian");

	/*int m[5][5] = { { 0,1,0,0,1 },{ 1,0,1,1,1 },{ 0,1,0,1,1 },{ 0,1,1,0,0 },{ 1,1,1,0,0 } };
	int m2[5][5] = { { 0,1,0,0,1 },{ 1,0,1,1,1 },{ 0,1,0,1,1 },{ 0,1,1,0,0 },{ 1,1,1,0,0 } };
	int m3[5][5] = { { 0,1,0,0,1 },{ 1,0,1,1,1 },{ 0,1,0,1,1 },{ 0,1,1,0,0 },{ 1,1,1,0,0 } };*/


	printf("\n\n 3. Объединение графов 1 и 2\n"); // через логическое "или" объединяем

	for (int i = 0; i < N; i++)
	{
		printf("\n ");
		for (int j = 0; j < N; j++)
		{
			m[i][j] = M1[i][j] || M2[i][j];
			printf("%d", m[i][j]);
		}
	}

	printf("\n\n 3. Пересечение графов 1 и 2\n"); // через логическое "и" находим пересечение

	for (int i = 0; i < N; i++)
	{
		printf("\n ");
		for (int j = 0; j < N; j++)
		{
			m[i][j] = M1[i][j] & M2[i][j];
			printf("%d", m[i][j]);
		}
	}

	printf("\n\n 3. Кольцевая сумма графов 1 и 2\n"); // через "исключающее или" находим кольцевую сумму
														// 1 ^ 1 = 0
	for (int i = 0; i < N; i++)
	{
		printf("\n ");
		for (int j = 0; j < N; j++)
		{
			m[i][j] = M1[i][j] ^ M2[i][j];
			printf("%d", m[i][j]);
		}
	}

	_getch();
}

void zad4() {

	setlocale(LC_ALL, "russian");

	int m[3][3] = { { 0,1,0, },{ 1,0,1 },{ 0,1,0 } };
	int m2[2][2] = { { 0,1 },{ 1,0 } };



	_getch();
}
