#include <iostream>
#include <math.h>
using namespace std;

struct position {
	float x,y;
};

int main()
{
	int num=0,i=0;
	double f=0;
	cin >> num;
	position *a = new position[num];

	while(i<num)
	{
		cin >> a[i].x;
		cin >> a[i].y;
		i++;
	}
	i=0;
	while(i<num)
	{
		float f = 0.031415926 * (a[i].x*a[i].x + a[i].y*a[i].y);
		cout<< "Property "<< i << ": This property will begin eroding in year " <<ceil(f)<<"."<<endl;
		i++;
	}
	cout<<"END OF OUTPUT.";
	return 0;
}