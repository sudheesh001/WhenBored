# include <stdio.h>
# include <conio.h>
# include <iostream>
# include <fstream>
int printPermutations(char *str,int size, int pos)
{
	  fstream f("PermutationList.txt",ios::app|ios::out|ios::in);
     int i;
     int total=0;
     if(pos==(size-1))
     {
     		puts(str);
         f<<str<<endl;
         return 1;
     }
     total+=printPermutations(str,size,pos+1);
     for(i=pos+1;i<size;i++)
     {
     		int j;
         for(j=pos;j<i;j++)
         if(*(str+j)==*(str+i))
                   break;
         if(j==i)
         {
             char tmp=*(str+pos);
             *(str+pos)=*(str+i);
             *(str+i)=tmp;
             total+=printPermutations(str,size,pos+1);
             tmp=*(str+pos);
             *(str+pos)=*(str+i);
             *(str+i)=tmp;
         }
     }
     return total;
     f.close();
}
int main()
{
    char str[100];
    int size,total;
    printf("Enter the string: ");
    gets(str);
    size=strlen(str);
    printf("\n\nAll permutations of the input string are:\n");
    total=printPermutations(str,size,0);
    printf("\n\nThe total number of permutations of the given string is %d",total);
    getch();
    return 0;
}
