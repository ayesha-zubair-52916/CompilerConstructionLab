#include<iostream>
using namespace std;
int main()
{
	string input;
	cout<<"Enter a sentence: ";
	getline(cin,input);
	
	string token="";
	
	for(int i=0;i<input.length();i++)
	{
		if(input[i] != ' ')
		token+=input[i];
		
		else
		{
			cout<<"Token: "<<token<<endl;
			token="";

		}
		
	}
	
}
