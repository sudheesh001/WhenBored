#include<iostream>
using namespace std;
int main()
{
	double length,breadth,area,perimeter;
	cout<<"Enter the length of the rectangle  = ";cin>>length;
	cout<<"Enter the breadth of the rectangle = ";cin>>breadth;
	perimeter = 2*(length+breadth);
	area = length * breadth ;
	if (area>perimeter)
		cout<<"Area of rectangle is greater than the Perimeter of rectangle\n";
	else if (area<perimeter)
		cout<<"Area of rectangle is smaller than the Perimeter of rectangle\n";
	else
		cout<<"Area of rectangle is equal to the Perimeter  of rectangle\n";
	return 0;
}
