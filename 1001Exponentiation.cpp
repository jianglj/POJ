#include <stdio.h>
#include <math.h>

void longmultip(short r[], int n, short a[], short b[], int ka, int kb)
{
	int i,j,k;
	for(k=0; k<n-1; k++)
	{
		for(i = 0; i < ka; i++)
		{
			for(j = 0; j < kb; j++)
			{
				r[i + j] = r[i + j] + a[i] * b[j];
				r[i + j +1] = r[i + j +1] + r[i + j]/10;
				r[i + j] = r[i + j] % 10;
			}
		}
		for(i = 0; i<ka; i++)
		{
			a[i] = r[i];
			r[i] = 0;
		}
	}
}

int main_1001()
{
	char s[6]={0};
	short r[150] = {0}, a[150] = {0}, b[6]={0};
	int n,fNum,fValue,fzeroNum;
	while (scanf("%s%d",s,&n) == 2)
	{
		fNum = 0;
		fValue = 0;
		for(int i=0; i<150; i++)
		{
			r[i] = 0;
			a[i] = 0;
			if(i<6)
				b[i]=0;
		}
		fzeroNum = 0;
		int k=0;
		bool fflag = true;
		for(int i=5; i>=0; i--)
		{
			if (s[i] == '0' && fflag)
				fzeroNum ++;
			else if(s[i] == '.')
			{
				fNum = 5-i-fzeroNum;
				fflag = false;
			}
			else
			{
				b[k] = (int)s[i]-'0';
				a[k++] = (int)s[i]-'0';
				fflag = false;
			}
		}
		longmultip(r, n, a, b, (k*n), 5-fzeroNum);
		k=k*n;
		fflag = true;
		while(k>=0)
		{
			if(k == fNum*n-1)
			{
				printf(".");
				fflag = false;
			}
			if(fflag && a[k]==0)
				k--;
			else 
			{
				printf("%d",a[k--]);
				fflag = false;
			}
		}
		printf("\n");
	}
	return 0;
}