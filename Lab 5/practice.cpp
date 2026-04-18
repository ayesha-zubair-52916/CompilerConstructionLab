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
	symbol table[10];
	cout<<"No of variables: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Name: ";
		cin>>table[i].name;
		cout<<"Datatype: ";
		cin>>table[i].type;
		cout<<"Value: ";
		cin>>table[i].value;
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
