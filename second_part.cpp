#include <stdio.h>
#include <stdlib.h>
#include <time.h>




void random(int*a,int k) {
	for (int i = 0;i < k;i++)
	{
		a[i] = rand() % k + 1;
	}
}


void narost(int*b,int k) {
	for (int i = 1;i < k;i++)
	{
		b[i] = b[i - 1] + 1;
	}
}


void nerost(int*c,int k) {
	for (int i = 1;i < k;i++)
	{
		c[i] = c[i - 1] - 1;
	}
}


void triada(int*d,int k) {
	for (int i = 1;i < k;i++)
	{
		if (i < (k / 2 + 1))
			d[i] = d[i - 1] + 1;
		else
			d[i] = d[i - 1] - 1;
	}
}


void shell(int* items, int count)
{

	int i, j, x, gap, k;
	for (k = 0; k < count; k++) {
		gap = items[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}


void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;


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
}

int comp(const void* i, const void* j)
{
	return *(int*)i - *(int*)j;
}





int main() {

	int k = 100;
	double shel[4],qsrt[4],qsrt1[4];
	clock_t start, end;
	srand(time(NULL));
	int* a;
	int* b;
	int* c;
	int* d;

	FILE* f;
	char name[] = "Sort.txt";
	fopen_s(&f,name, "w+");

	for (int si = 0;si < 3;si++)
	{
		a = (int*)malloc(k * sizeof(int));
		b = (int*)malloc(k * sizeof(int));
		c = (int*)malloc(k * sizeof(int));
		d = (int*)malloc(k * sizeof(int));

		b[0] = 1;
		c[0] = k;
		d[0] = 1;

		random(a, k);
		start = clock();
		shell(a, k);
		end = clock();
		shel[0] = (double)(end - start) / CLOCKS_PER_SEC;

		random(a, k);
		start = clock();
		qs(a, a[0], a[1]);
		end = clock();
		qsrt[0] = (double)(end - start) / CLOCKS_PER_SEC;

		random(a, k);
		start = clock();
		qsort(a, k, sizeof(int), comp);
		end = clock();
		qsrt1[0] = (double)(end - start) / CLOCKS_PER_SEC;






		narost(b, k);
		start = clock();
		shell(b, k);
		end = clock();
		shel[1] = (double)(end - start) / CLOCKS_PER_SEC;

		random(b, k);
		start = clock();
		qs(b, b[0], b[1]);
		end = clock();
		qsrt[1] = (double)(end - start) / CLOCKS_PER_SEC;

		random(b, k);
		start = clock();
		qsort(b, k, sizeof(int), comp);
		end = clock();
		qsrt1[1] = (double)(end - start) / CLOCKS_PER_SEC;





		nerost(c, k);
		start = clock();
		shell(c, k);
		end = clock();
		shel[2] = (double)(end - start) / CLOCKS_PER_SEC;

		random(c, k);
		start = clock();
		qs(c, c[0], c[1]);
		end = clock();
		qsrt[2] = (double)(end - start) / CLOCKS_PER_SEC;

		random(c, k);
		start = clock();
		qsort(c, k, sizeof(int), comp);
		end = clock();
		qsrt1[2] = (double)(end - start) / CLOCKS_PER_SEC;





		triada(d, k);
		start = clock();
		shell(d, k);
		end = clock();
		shel[3] = (double)(end - start) / CLOCKS_PER_SEC;


		random(d, k);
		start = clock();
		qs(d, d[0], d[1]);
		end = clock();
		qsrt[3] = (double)(end - start) / CLOCKS_PER_SEC;

		random(d, k);
		start = clock();
		qsort(d, k, sizeof(int), comp);
		end = clock();
		qsrt1[3] = (double)(end - start) / CLOCKS_PER_SEC;

		fprintf(f,"%d\n", k);
		fprintf(f, "array     shell             qs            quicksort\n");
		for (int i = 0;i < 4;i++) {
			if (i == 0)
				fprintf(f, "r       %f     %f     %f\n", shel[i],qsrt[i],qsrt1[i]);
			if (i == 1)
				fprintf(f, "+       %f     %f     %f\n", shel[i], qsrt[i], qsrt1[i]);
			if (i == 2)
				fprintf(f, "-       %f     %f     %f\n", shel[i], qsrt[i], qsrt1[i]);
			if (i == 3)
				fprintf(f, "^       %f     %f     %f\n", shel[i], qsrt[i], qsrt1[i]);
		}
		fprintf(f,"\n", k);

		k *= 10;
		free(a);
		free(b);
		free(c);
		free(d);

	}
	fclose(f);
}