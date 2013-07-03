#include<iostream>
using namespace std;
int main()
{
	double x1,x2,x3,y1,y2,y3;
	cout<<"Enter the coordinates of the (x1,y1) seperated by a space without the parenthesis = ";
	cin>>x1>>y1;
	cout<<"Enter the coordinates of the (x2,y2) seperated by a space without the parenthesis = ";
	cin>>x2>>y2;
	cout<<"Enter the coordinates of the (x3,y3) seperated by a space without the parenthesis = ";
	cin>>x3>>y3;
	double slope1=(y2-y1)/(x2-x1);
	double slope2=(y3-y2)/(x3-x2);
	double slope3=(y3-y1)/(x3-x1);
	if(slope1==slope2 && slope2==slope3)
	{
		cout<<"The three coordinates i.e ("<<x1<<','<<y1<<") , ("<<x2<<','<<y2<<") , ("<<x3<<','<<y3<<")\n";
		cout<<"Are in the same line\n";
	}
	else
		cout<<"The three coordinates are not in the same line\n";
	return 0;
}
