// Emma's Notebook.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	long long num;
	if (t%2==0)
	{
		long long tmp = t>>1;
		long long num1 = (1+tmp)*tmp/2;
		long long num2 = (2+(tmp+1))*tmp/2;
		num = num1 + num2;
	}
	else
	{
		long long tmp = (t>>1) + 1;
		long long num1 = (1+tmp)*tmp/2;
		long long num2 = (2+tmp)*(tmp-1)/2;
		num = num1 + num2;
	}
	cout<<num <<endl;
//	printf("%lld\n", num);
	system("pause");
	return 0;
}

