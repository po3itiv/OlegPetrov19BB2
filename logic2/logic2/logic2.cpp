#include <ctime>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
void shell(int* items, int count);
void qs(int* items, int left, int right);

void shell(int* items, int count)
{
	clock_t start1 = clock();
	setlocale(LC_ALL, "russian");
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
	clock_t start2 = clock();

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

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
	clock_t end2 = clock();
	
	int result2 = end2 - start2;
	printf("Время, затраченное на выполнение быстрой сортировки: %d \n", result2);
}
int main()
{
	int a[5], b[5];
	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;
	int* items = a, count = 5, left = 0, right = count - 1;
	shell(items, 10);
	qs(b, 10, 10);
	return 0;
	_getch();
}