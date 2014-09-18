#include <stdio.h>

int main_1003()
{
	float c=1,num[20];
	int len=0,leftnum;
	while(c > 0.005)
	{
		scanf("%f",&c);
		num[len++] = c;
	}
	
	len -= 1;
	int *flags=new int [len];

	for (int i=0; i<len; i++)
	{
		flags[i] = 0;
	}

	leftnum = len;
	int cardNum=0;
	
	while (leftnum > 0)
	{
		c += (1.0 / (++cardNum+1));
		for(int i=0; i<len; i++)
		{
			if (num[i]<=c && flags[i] == 0)
			{
				flags[i] = cardNum;
				leftnum--;
			}
		}
	}

	for (int i=0; i<len; i++)
	{
		printf("%d card(s)\n",flags[i]);
	}
	return 0;
}