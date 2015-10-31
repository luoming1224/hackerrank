// Counting Triangles.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int acute_count = 0;
int right_count = 0;
int obtuse_count = 0;

void calculate(int T[], int N)
{
	unsigned int a, b, c;
	int i, j, k;
	for (i = 0; i < N-2; i++)
	{
		for (j = i+1; j < N-1; j++)
		{
			for (k = j+1; k < N; k++)
			{
				a = T[i];
				b = T[j];
				c = T[k];
				if (T[i] + T[j] <= T[k])
				{
					break;
				}
				a = T[i]*T[i];
				b = T[j]*T[j];
				c = T[k]*T[k];
				if (a + b > c)
				{
					acute_count++;
//					printf("acute:%d %d %d %d %d %d\n",T[i],T[j],T[k],a,b,c);
				}
				else if (a + b < c)
				{
					obtuse_count++;
//					printf("obtuse:%d %d %d %d %d %d\n",T[i],T[j],T[k],a,b,c);
				}
				else
				{
					right_count++;
//					printf("right:%d %d %d %d %d %d\n",T[i],T[j],T[k],a,b,c);
				}
			}
		}
	}
}

int main()
{
	int N;
	scanf("%d", &N);
	int *data = (int *)malloc(N*sizeof(N));
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &data[i]);
	}
	calculate(data, N);
	printf("%d %d %d\n", acute_count, right_count, obtuse_count);

	system("pause");
	return 0;
}

