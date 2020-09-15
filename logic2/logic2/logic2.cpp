#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <conio.h>

int compare(const void* x1, const void* x2);
void shell(int* items, int count);
void qs(int* items, int left, int right);
void zapolnenie_um();
void zapolnenie_rand();
void zapolnenie_uv();
void zapolnenie_uv_um();

int a[10000], b[10000], c[10000];

int main(void)
{
	setlocale(LC_ALL, "russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	int* items, count = 10000, left = 0, right = count - 1;
	clock_t start1 = clock(); // объявляем переменные для определения времени выполнения

	int i = 0, j = 0, r = 0;
	int elem_c;

	/*
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 10000)
	{
		a[i] = rand() % 100 + 1; // заполняем массив случайными числами

		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 10000)
	{

		b[i] = rand() % 100 + 1; // заполняем массив случайными числами

		i++;
	}

	//clock_t start2 = clock();
	for (i = 0; i < 10000; i++)
	{

			elem_c = 0;

			elem_c = elem_c + a[i] * b[r];
			c[i] = elem_c;
			r++;

	}
	clock_t end = clock();
	//int result1 = end - start1;
	//int result2 = end - start2;
	//printf("Время, затраченное на выполнение всей программы: %d \n", result1);
	//printf("Время, затраченное на выполнение третьего цикла: %d \n", result2);
	*/

	//zapolnenie_um();
	//zapolnenie_uv();
	//zapolnenie_rand();
	zapolnenie_uv_um();


	shell(a, count);

	clock_t start2 = clock();
	qs(b, left, right);
	clock_t end2 = clock();
	int result2 = end2 - start2;
	printf("Время, затраченное на выполнение быстрой сортировки: %d \n", result2);

	clock_t start3 = clock();
	qsort(c, 10000, sizeof(int), compare);
	clock_t end3 = clock();
	int result3 = end3 - start3;
	printf("Время, затраченное на сортировку стандартной функцией qsort: %d \n", result3);

	getch();
	return(0);
}

void shell(int* items, int count)
{
	clock_t start1 = clock();
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
	clock_t end1 = clock();
	int result1 = end1 - start1;
	printf("Время, затраченное на выполнение сортировки Шелла: %d \n", result1);
}



void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;


	setlocale(LC_ALL, "russian");
	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j)
		qs(items, left, j);
	if (i < right)
		qs(items, i, right);

}

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

void zapolnenie_um() {

	int sch = 3330000;

	for (int i = 0; i < 10000; i++) {

		a[i] = b[i] = c[i] = sch - 250;
		sch = sch - 333;

	}

}

void zapolnenie_rand() {

	int i = 0;

	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 10000)
	{
		a[i] = b[i] = c[i] = rand() % 100000 + 1; // заполняем массив случайными числами

		i++;
	}
}


void zapolnenie_uv() {

	int i = 0;
	int cplus = 0;
	int sum = 10;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 10000)
	{

		a[i] = b[i] = c[i] = rand() % 10 + cplus; // заполняем массив случайными числами
		i++;
		cplus = cplus + 10;


	}
}

void zapolnenie_uv_um() {

	int i = 0;
	int cplus = 0;
	int sum = 10;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	while (i < 5000)
	{

		a[i] = b[i] = c[i] = rand() % 10 + cplus; // заполняем массив случайными числами
		i++;
		cplus = cplus + 10;


	}

	int sch = cplus;

	for (int i = 5000; i < 10000; i++) {

		a[i] = b[i] = c[i] = sch - 4;
		sch = sch - 10;

	}

}