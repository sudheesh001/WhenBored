#include<iostream>
#include<conio>
#include<stdio>
const int MAX=5;
struct student
{
	int roll;
   char name[20];
};
class queue
{
	student a[MAX];
   int front,rear;
   public :
   	queue(){front=rear=-1;}
      void insertion()
      {
      	if(front==0 && rear==MAX-1 || front==rear+1)
         	cout<<"Queue Overflow \n";
         else
         {
         	if(rear==-1)
            	front=rear=0;
            else
            if(rear==MAX-1)
            	rear=0;
            else
            	rear++;
         	student t;
            cin>>t.roll>>t.name;
            a[rear]=t;
         }
      }
      void deletion()
      {
      	if(front==-1)
         	cout<<"Queue Underflow\n";
         else
         {
         	student t=a[front];
            if(front==rear)
            	front=rear=-1;
            else
            if(front==MAX-1)
            	front=0;
            else
            	front++;
         }
      }
      void display()
      {
      	if(front==-1)
         	cout<<"No elements in Queue\n";
         else
         {
         	for(int k=front;k!=rear+1;k++)
            {
            	k%=MAX;
               student t=a[k];
               cout<<t.roll<<","<<t.name<<endl;
            }
         }
      }
};
