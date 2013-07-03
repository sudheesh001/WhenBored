#include<iostream>
using namespace std;
int main()
{
	double number;
	cout<<"Enter number for which the computer needs to find the absolute : ";cin>>number;
	if(number>=0)
		cout<<"Absolute Value of "<<number<<" is "<<number<<endl;
	else
	{
		//This means it is negative. so the following algorithm should work
		//negative number -(negative number + negative number)
		double temp=number;
		number=number-(number+number);
		cout<<"Absolute value of "<<temp<<" is "<<number<<endl;
	}
	return 0;
}

