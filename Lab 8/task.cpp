#include <iostream>
#include <string>
using namespace std;

string input;
int i = 0;

void error()
{
    cout << "String Rejected (Syntax Error)" << endl;
    exit(0);
}

void match(char c)
{
    if (input[i] == c)
        i++;
    else
        error();
}

void S();  // Function for non-terminal S

// S = a S b | e
void S()
{
    if (input[i] == 'a')
    {
        match('a');
        S();
        match('b');
    }
    
}

int main()
{
    cout << "Enter input: ";
    cin >> input;

    S();

    if (input[i] == '\0')
        cout << "String Accepted" << endl;
    else
        cout << "String Rejected" << endl;

    return 0;
}
