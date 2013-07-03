#include<iostream>
using namespace std;
int main()
{
	cout<<"Displaying Armstrong Numbers between 1 and 500 \n";
	int k=1;
	while(k<=500)
	{
		int t=k;
		int prod=0;
		while(t!=0)
		{	
			int digit=t%10;
			prod += digit*digit*digit;
			t/=10;
		}
		if(prod==k)
			cout<<k<<endl;
		prod=0;
		k++;
	}
	cout<<"\nYour Required Armstrong numbers have been displayed\n";
	return 0;
}
		
