#include<iostream>
using namespace std;

struct symbol{
	string name;
	string value;
	string type;
	int size;
};

int main()
{
	int n;
	symbol table[10];
	cout<<"No of variables: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cout<<"Variable name: ";
		cin>>table[i].name;
		cout<<"Datatype: ";
		cin>>table[i].type;
		cout<<"Value: ";
		cin>>table[i].value;
		
		if(table[i].type=="int")
		table[i].size=4;
		
		else if(table[i].type=="float")
		table[i].size=4;
		
		else if(table[i].type=="char")
		table[i].size=1;
		cout<<endl;
	}
	
	cout<<"\n---Symbol Table---\n"<<endl;
	cout<<"Name\tType\tValue\tSize"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<table[i].name<<"\t";
		cout<<table[i].type<<"\t";
		cout<<table[i].value<<"\t";
		cout<<table[i].size<<"\t";

		cout<<endl;
	}
	
	
	return 0;
}
