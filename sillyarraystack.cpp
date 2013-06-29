#include<iostream>
#include<conio>
#include<stdio>
const int MAX=5;
struct student
{
	int roll;
   char name[20];
};
class stack
{
	int top;
   student a[MAX];
   public :
   	stack(){top=-1;}
      void push()
      {
      	if(top==MAX)
         	cout<<"Overflow\n";
         else
         {
            student t;
         	cout<<"Enter roll no?"; cin>>t.roll;
            cout<<"Enter name   ?"; cin>>t.name;
            a[++top]=t;
            cout<<"Pushed\n";
         }
      }
      void pop()
      {
      	if(top==-1)
         	cout<<"Underflow\n";
         else
         {
         	student t=a[top--];
            cout<<"Popped\n";
         }
      }
      void display()
      {
      	if(top==-1)
         	cout<<"No Elements in Array\n";
         else
         {
         	for(int k=top;k>=0;k--)
            {
            	student t=a[k];
               cout<<t.roll<<","<<t.name<<endl;
            }
         }
      }
};
void main()
{
	stack obj;
   int choice;
   do
   {
   	cout<<"1. Push\n";
      cout<<"2. Pop\n";
      cout<<"3. Display\n";
      cout<<"0. EXIT\n";
      cout<<endl<<"Enter choice?"; cin>>choice;
      switch(choice)
      {
      	case 1: obj.push();break;
         case 2: obj.pop();break;
         case 3: obj.display();break;
      }
   }
   while(choice!=0);
}

