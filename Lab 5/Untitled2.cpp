#include<iostream>
using namespace std;

struct symbol{
	string name;
	string value;
	string type;
};

int main()
{
	int n;
	int count=0;
	symbol table[10];
	cout<<"No of variables: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		string name,type,value;
		bool duplicate=false;
		cout<<"Enter name: ";
		cin>>name;
		cout<<"Enter type: ";
		cin>>type;
		cout<<"Enter value: ";
		cin>>value;
		
		for(int j=0;j<count;i++)
		{
			if(table[j].name==name)
			{
				cout<<"Duplicate found"<<endl;
				duplicate=true;
				break;
			}
		}
		
		if(!duplicate)
		{
			table[count].name=name;
			table[count].type=type;
			table[count].value=value;
			count++;
		}
		
		
	}
	
	cout<<"\n---Symbol Table---\n"<<endl;
	cout<<"Name\tType\tValue"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<table[i].name<<"\t";
		cout<<table[i].type<<"\t";
		cout<<table[i].value<<"\t";
		cout<<endl;
	}
	
	
	return 0;
}
