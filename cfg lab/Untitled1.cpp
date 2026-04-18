#include<iostream>
#include<cstring>
using namespace std;

char production[10][10];
char first[10];
char follow[10];
int n;

void findFirst(char c)
{
    if(!isupper(c))
    {
        cout<<c<<" ";
        return;
    }

    for(int i=0;i<n;i++)
    {
        if(production[i][0]==c)
        {
            if(production[i][2]=='$')
                cout<<"$ ";
            else
                findFirst(production[i][2]);
        }
    }
}

void findFollow(char c)
{
    if(production[0][0]==c)
        cout<<"$ ";

    for(int i=0;i<n;i++)
    {
        for(int j=2;j<strlen(production[i]);j++)
        {
            if(production[i][j]==c)
            {
                if(production[i][j+1]!='\0')
                    findFirst(production[i][j+1]);

                if(production[i][j+1]=='\0' && c!=production[i][0])
                    findFollow(production[i][0]);
            }
        }
    }
}


int main()
{
    cout<<"Enter number of productions: ";
    cin>>n;

    cout<<"Enter productions (Example: E=TR):\n";

    for(int i=0;i<n;i++)
        cin>>production[i];

    char choice;

    do
    {
        char c;
        cout<<"\nFind FIRST and FOLLOW of: ";
        cin>>c;

        cout<<"FIRST("<<c<<") = { ";
        findFirst(c);
        cout<<"}\n";

        cout<<"FOLLOW("<<c<<") = { ";
        findFollow(c);
        cout<<"}\n";

        cout<<"Continue? (y/n): ";
        cin>>choice;

    }while(choice=='y');

    return 0;
}


