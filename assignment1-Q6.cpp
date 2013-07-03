#include<iostream>
using namespace std;
int main()
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	int employees[10];
	int no_of_hours;
	int hours[10];
	double extrapay[10];
	for(int i=0;i<10;i++)
	{
		int temp;
		cout<<"Enter the number of hours employee "<<(i+1)<<" has worked \n";
		cin>>temp;
		hours[i]=temp;
	}
	for(int i=0;i<10;i++)
	{
		int extrahours;
		if(hours[i]>40)
		{
			extrahours=hours[i]-40;
			extrapay[i]=(extrahours*12.00);
		}
		else
			extrapay[i]=0;
	}
	//display cost
	double sum;
	for(int x=0;x<10;x++)
		sum+=extrapay[x];
	cout<<"You have to pay a total of "<<sum<<" rupees to the employees\n";
	for(int x=0;x<10;x++)
		cout<<"Employee "<<(x+1)<<" to be paid "<<extrapay[x]<<endl;
	return 0;
}
			
			
