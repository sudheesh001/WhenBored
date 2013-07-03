#include<iostream>
using namespace std;
int main()
{
	int linecount=0;
	for (int i=65;i<=71;i++)
		cout<<char(i)<<" ";
	for(char k=70;k>=65;k--)
		cout<<char(k)<<" ";
	cout<<endl;
	while(linecount!=6)
	{
	for(int i=65;i<72;i++)
		if(i<=71-linecount-1)
			cout<<char(i)<<" ";
		else
			cout<<"  ";
	for(int line=0;line<=2*linecount-1;line++)
		cout<<" ";
	for(int i=70-linecount;i>=65;i--)
		cout<<char(i)<<" ";
	linecount++;
	cout<<endl;
	}
	return 0;
}
	
