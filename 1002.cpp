#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	int t=0,j=0;
	int num,k,sameN=0;
	cin.sync_with_stdio(false);
	cin >> num;
	int* a = new int[num];
	memset(a,0,sizeof(int)*num);

	for (int i=0; i<num; i++)
	{
		cin >> s;
		k=0;
		j=0;
		while (k<7)
		{
			if(s[j]>='A' && s[j]<='P')
			{
				a[i] = a[i]*10 + (s[j]-'A')/3 + 2;
				k++;
			}
			else if(s[j]>='R' && s[j]<='Y')
			{
				a[i] = a[i]*10 + (s[j]-'Q')/3 + 7;
				k++;
			}
			else if(s[j]>='0' && s[j]<='9')
			{
				a[i] = a[i]*10 + s[j] - '0';
				k++;
			}
			j++;
		}
	}
	sort(a, a+num);
	k=0;
	for(int i=1; i<num; i++)
	{
		if (a[i-1] == a[i])
		{
			k++;
		}
		if (a[i-1]!=a[i] || i==num-1)
		{
			if(k>0) 
			{
				sameN++;
				cout << setw(3) << setfill('0') << a[i-1] / 10000 << '-' << setw(4) << setfill('0') << a[i-1]%10000 << " " << k+1 <<endl;
			}
			k=0;
		}
	}
	if(sameN==0) cout << "No duplicates. " << endl;
	return 0;
}