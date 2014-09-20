#include <stdio.h>
using namespace std;

int main_1004()
{
	float aver=0,input=0;
	for(int i=0;i<12;i++)
	{
		scanf("%f",&input);
		aver += input;
	}

	printf("$%.2f",aver/12.0);

	return 0;
}