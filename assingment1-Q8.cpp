#include<iostream>
//Display ASCII chart
using namespace std;
int main()
{
	cout<<"Displaying ASCII chart\n";
	int i=0;
	while(i<=255)
	{
		cout<<(i)<<" "<<char(i)<<endl;
		i++;
	}
	return 0;
}
