#include<iostream>
using namespace std;
int main()
{
	string input;
	cout<<"Enter a sentence:";
	getline(cin,input);
	string token="";
	for(int i=0;i<input.length();i++)
	{
		if(input[i] != ' ')
		token+=input[i];
		
		else
		{
			if(token=="int"||token=="float")
			cout<<token<<" : Keyword\n";
			
			else if(token[0]>='0' && token[0]<='9')
			cout<<token<<" : Number\n";
			
			else if(token=="+"||token=="=")
			cout<<token<<" : Operator\n";
			
			else if(token==";")
			cout<<token<<" : Terminator\n";
			
			else
			cout<<token<<" : Identifier\n";
			
			token="";
			
		}
	}
	
}
