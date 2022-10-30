#include <stdio.h>
#include <stdlib.h>
#include <time.h>



unsigned int a[100][100], b[100][100], c[100][100], elem_c;


int main(void)
{
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	clock_t start = clock();
	int i = 0, j = 0, r;
	int k = 100;
	srand(time(NULL));
	while (i < k)
	{
		while (j < k)
		{
			a[i][j] = rand() % 100 + 1; 
			j++;
		}
		i++;
	}
	srand(time(NULL)); 
	i = 0; j = 0;
	while (i < k)
	{
		while (j < k)
		{
			b[i][j] = rand() % 100 + 1; 
			j++;
		}
		i++;
	}

	for (i = 0;i < k;i++)
	{
		for (j = 0;j < k;j++)
		{
			elem_c = 0;
			for (r = 0;r < k;r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	printf("Program time is - %f", seconds);
	return(0);
}

