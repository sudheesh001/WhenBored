#include<iostream>
using namespace std;
//Multiplication table upto 20
int main()
{
	int tablenumber;
	cout<<"Enter the number for which you want a multiplication table = ";cin>>tablenumber;
	for(int i=1;i<=20;i++)
		cout<<tablenumber<<" * "<<i<<" = "<<(tablenumber*i)<<endl;
	return 0;
}
