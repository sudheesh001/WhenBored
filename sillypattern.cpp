#include<iostream>
#include<conio>
void main()
{
	/*
   REQUIRED PATTERN
   ----------------

   XXXXXXXXXXXXXXX
    XXXXXXXXXXXXX
     XXXXXXXXXXX
      XXXXXXXXX
       XXXXXXX
        XXXXX
         XXX
          X
         XXX
        XXXXX
       XXXXXXX
      XXXXXXXXX
     XXXXXXXXXXX
    XXXXXXXXXXXXX
   XXXXXXXXXXXXXXX

  ------------------
  */
  for(int k=7;k>=0;k--)
  {
  		for(int j=k;j>=0;j++)
      	cout<<" ";
  		for(int i=(2*k)-1;i>=0;i=i-2)
      	cout<<"X";
      for(int j=0;j<=k;j++)
      	cout<<" ";
      cout<<endl;
	}
   getch();
}

