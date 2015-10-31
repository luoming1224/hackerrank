// Save Quantumland.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

int calculate(int T[], int N)
{
	int count = 0;
	int index = 0, begin = -1, end;
	for (; index < N; index++)
	{
		if (0 == T[index])
		{
			continue;
		}
		end = index;
		int need = (end - begin - 1)/2;
		count += need;
		begin = end;
	}
	end = index;
	int need = (end - begin - 1)/2;
	count += need;
	return count;
}

int main()
{
	int t, N;
	int *data;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		scanf("%d", &N);
		data = (int *)malloc(N*sizeof(int));
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &data[i]);
		}
		int count = calculate(data, N);
		printf("%d\n", count);
		delete data;
		data = NULL;
	}
	system("pause");
	return 0;
}

