#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void PercDown(double A[], int B[], int i, int n)
{
	double tmp = A[i];
	int tmpindex = B[i];
	int p = 2 * i + 1;
	while (p < n)
	{
		if (p+1 < n && A[p+1] > A[p])
		{
			p = p + 1;
		}
		if (A[p] > tmp)
		{
			A[i] = A[p];
			B[i] = B[p];
			i = p;
			p = 2 * i + 1;
		}
		else
			break;
	}
	A[i] = tmp;
	B[i] = tmpindex;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
	scanf("%d", &N);
	unsigned int *B = new unsigned int[N];
	unsigned int *E = new unsigned int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d  %d", &B[i], &E[i]);
	}
	scanf("%d", &K);
	int *T = new int[K];
	double *A = new double[K];

	for (int j = 0; j < K; j++)
	{
		A[j] = E[j] * log10((double)B[j]);
		T[j] = j;
	}
	for (int i = K/2-1; i >= 0; i--)
	{
		PercDown(A, T, i, K);
	}

	for (int t = K; t < N; t++)
	{
		if ((E[t] * log10((double)B[t])) < A[0])
		{
			A[0] = (E[t] * log10((double)B[t]));
			T[0] = t;
			PercDown(A, T, 0, K);
		}
	}
	printf("%d %d\n",B[T[0]], E[T[0]]);
	
    return 0;
}
