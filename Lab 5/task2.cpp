#include<iostream>
using namespace std;

struct symbol{
	string name;
	string type;
	string value;
};

int main()
{
	int n;
	cout<<"Enter number of variables: ";
	cin>>n;
	string search;
	symbol table[10];
	
	for(int i=0;i<n;i++)
	{
		cout<<"Variable Name: ";
		cin>>table[i].name;
		cout<<"Datatype: ";
		cin>>table[i].type;
		cout<<"Value: ";
		cin>>table[i].value;
		cout<<endl;
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
	cout<<endl;
	
	cout<<"Enter name to search: ";
	cin>>search;
	cout<<endl;
	
	for(int i=0;i<n;i++)
	{
		if(table[i].name==search)
		{
			cout<<"Name found!"<<endl;
			break;
		}
		else
		{
			cout<<"Not found."<<endl;
		}
	}
	
	return 0;
}
