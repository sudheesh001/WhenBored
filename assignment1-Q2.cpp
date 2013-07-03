#include<iostream>
using namespace std;
int main()
{
	double angle1,angle2,angle3;
	cout<<"Enter Angle 1 of the triangle ? ";cin>>angle1;
	cout<<"Enter Angle 2 of the triangle ? ";cin>>angle2;
	cout<<"Enter Angle 3 of the triangle ? ";cin>>angle3;
	double sum_of_angles=angle1+angle2+angle3;
	if(sum_of_angles==180)
		cout<<"Valid Triangle\n";
	else
		cout<<"Invalid Triangle\n";
	return 0;
}
