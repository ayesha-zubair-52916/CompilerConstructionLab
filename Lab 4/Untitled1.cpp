#include<iostream>
#include<string>
using namespace std;
/*int main()
{
	string input;
	cin>>input;
	int state=0;
	
	for(int i=0;i<input.length();i++)
	{
		char c=input[i];
		
		if(state==0)
		{
			if(c=='0')
			state=1;
			
			else
			state=2;
		}
		
		else if(state==1)
		{
			if(c=='0')
			state=1;
			
			else
			state=0;
		}
		
		else if(state==2)
		{
			if(c=='1')
			state=1;
			
			else
			state=0;
		}
	}
	
	if(state==1 || state==2)
	cout<<"Accepted\n";
	else
	cout<<"Rejected";
	
	return 0;
}*/


/*int main() // start end same
{
	string input;
	cout<<"Enter string:";
	cin>>input;
	int state=0;
	
	for(int i=0;i<input.length();i++)
	{
		char c=input[i];
		
		if(state==0)
		{
			if(c=='0')
			state=1;
			
			else
			state=3;
		}
		
		else if(state==1)
		{
			if(c=='0')
			state=1;
			
			else 
			state=2;
		}
		
		else if(state==2)
		{
			if(c=='1')
			state=2;
			
			else
			state=1;
		}
		
		else if(state==3)
		{
			if(c=='1')
			state=3;
			
			else
			state=4;
		}
		
		else if(state==4)
		{
			if(c=='0')
			state=4;
			
			else
			state=3;
		}
	}
	
	if(state==1||state==3)
	cout<<"Accepted";
	else
	cout<<"Rejected";
	
	
	
	
	
	
	
	
	
	return 0;
}*/

int main()
{
	string input;
	cout<<"Enter string:";
	cin>>input;
	int state=0;
	
	for(int i=0;i<input.length();i++)
	{
		char c=input[i];
		
		if(state==0)
		{
			if(c=='b')
			state=1;
			else
			state=0;
		}
		
		else if(state==1)
		{
			if(c=='b')
			state=2;
			else 
			state=0;
		}
		
		else if(state==2)
		{
			if(c=='b')
			state=2;
			else
			state=2;
		}
	}
	
	if(state==0||state==1)
	cout<<"Accepted";
	else
	cout<<"Rejected";
	
}
