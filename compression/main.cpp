#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
using namespace std;
void exectime()
{
	int start_s=clock();
	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;
}
// File extension found.
char * findextension(char string[])
{
	int len=strlen(string);
	char rev_string[5];
	i=1;
	int found=0;
	while(found!=1)
	{
		if(string[len-i]!='.')
		{
			rev_string[i-1]=string[len-i];
			i++;
		}
		else
			found=1;
		len--;
	}
	return strrev(rev_string);
}
//Check if extension is somewhere in .DAT / .TXT
//==========================================================================================================================
void read_file(char filename[]) // Character compression (more over i feel its expansion :O)
{
	char ext[]=findextension(filename);
	//Now the extension is found. Time to figure out and then read file
	if(stricmp(ext)=="TXT")
	{
		ifstream fin(filename,ios::app|ios::out);
		char _bin_bit;
		ofstream fout("Temp.txt",ios::app|ios::in|ios::out);
		while(fin>>_bin_bit)
		{
			if(_bin_bit>='A' && _bin_bit<='Z')
				fout<<int(_bin_bit)-(int('A')-1)<<" ";//This makes 'A' as 1 /......
			if(_bin_bit>='a' && _bin_bit<='z')
				fout<<(int(_bin_bit)-(int('a')))+27<<" ";//Storing 'a' these from 27 /......
			if(_bin_bit>='1' && _bin_bit<='9')
				fout<<(int(_bin_bit)-int('1'))+53<<" ";//storing '1' at 53 , '9' at 61 /......
			// Super Buggy code
			// Ooops problem begins ... spacing out issues -.-, what to do in case of a real space ? o.O
			// Ignore special characters, no problem
		}
	}
	if(stricmp(ext)=="DAT")
	{
		ifstream fin(filename,ios::app|ios::out|ios::binary);
		char _bin_bit;
		ofstream fout("Temp.txt",ios::app|ios::in|ios::out|ios::binary);
		while(fin>>_bin_bit)
		{
			if(_bin_bit>='A' && _bin_bit<='Z')
				fout<<int(_bin_bit)-(int('A')-1)<<" ";//This makes 'A' as 1 /......
			if(_bin_bit>='a' && _bin_bit<='z')
				fout<<(int(_bin_bit)-(int('a')))+27<<" ";//Storing 'a' these from 27 /......
			if(_bin_bit>='1' && _bin_bit<='9')
				fout<<(int(_bin_bit)-int('1'))+53<<" ";//storing '1' at 53 , '9' at 61 /......
			// Super Buggy code
			// Ooops problem begins ... spacing out issues -.-, what to do in case of a real space ? o.O
		}
	}
}
//==========================================================================================================================
// Maybe need to try out a dictionary approach so that it could be easier and hence end up fixing more issues related
// to compression and other factors. Will change code soon.
//==========================================================================================================================
