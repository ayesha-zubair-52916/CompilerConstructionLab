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
	int count=0;
	symbol table[10];
	
	cout<<"Enter no of variables: ";
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		bool duplicate=false;
		string name, type, value;
		
		cout<<"Variable name: ";
		cin>>name;
		cout<<"Datatype: ";
		cin>>type;
		cout<<"Value: ";
		cin>>value;
		
		for(int j=0;j<count;j++)
		{
			if(table[j].name==name)
			{
				duplicate=true;
				cout<<"Duplicate name"<<endl;
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
		cout<<endl;
		
	cout<<"\n---Symbol Table---\n"<<endl;
	cout<<"Name\tType\tValue"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<table[i].name<<"\t";
		cout<<table[i].type<<"\t";
		cout<<table[i].value<<"\t";

		cout<<endl;
	}	
	
	}

	/*cout<<"\n---Symbol Table---\n"<<endl;
	cout<<"Name\tType\tValue"<<endl;
	
	for(int i=0;i<n;i++)
	{
		cout<<table[i].name<<"\t";
		cout<<table[i].type<<"\t";
		cout<<table[i].value<<"\t";

		cout<<endl;
	}	*/
	
}
