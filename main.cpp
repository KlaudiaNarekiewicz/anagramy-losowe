#include <iostream>
#include <fstream>
#include <string>
using namespace std;

bool isAnagram(string linia11, string linia22)
{
    if(linia11.length() != linia22.length()) 
    return false; 
    for (int i=0; i<linia11.length(); i++) 
    {
     	if (linia11[i] = linia22[i])
	return true;
    }
}
string stringSort(string s)
{
	string napis(s);
	int dlugosc = napis.length();
	for(int i=0; i<dlugosc-1; i++)
   	{
        	for(int j=0; j<dlugosc-1; j++)
        	{
           		if(napis[j]>napis[j+1])
           		{
                		char litera = napis[j];
                		napis[j] = napis[j+1];
                		napis[j+1] = litera;
           		}
		}
	}
return napis;
}
int main(int argc, char** argv) 
{
	ifstream plik1;
	ofstream plik2;
	
	string linia1;
        string linia2;
	
	string linia11;
        string linia22;
	
	plik1.open("1.txt");
   	plik2.open("2.txt");   	
	plik2<<"["<<endl;  
	
        while(!plik1.eof())
	{	
		getline(plik1,linia1);  
		for(int i=0;i<2;i++)
		{
    			getline(plik1,linia2);       
			linia11 = stringSort(linia1);
			linia22 = stringSort(linia2);        
   			if(isAnagram(linia11,linia22))
   			{			
   				cout<<"{\"slowo\": \""<<linia1<<"\", \"anagram\":"<<"\""<<linia11<<"\"},";
				cout<<"{\"slowo\": \""<<linia2<<"\", \"anagram\":"<<"\""<<linia22<<"\"}"<<endl;
			}
			linia2 = linia1;
		}
	}
   	plik2<<"]";  		
   	plik1.close();
   	plik2.close();
return 0;
}
