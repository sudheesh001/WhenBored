#include<iostream>
using namespace std;
int main()
{
	int number;
	cout<<"Enter an integer = ";cin>>number;
	int ref1=1,ref2=0;
	while(number>=0)
	{
		if (number==ref1)
			cout<<"Odd Number\n";
		else
		if (number==ref2)
			cout<<"Even Number\n";
		number=number-2;
	}
	return 0;
}
