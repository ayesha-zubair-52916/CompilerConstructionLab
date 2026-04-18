#include <iostream>
using namespace std;

string input;
int i = 0;

void S() {
    if(input[i] == 'a') {
        i++;       
        S();       
        if(input[i] == 'b') {
            i++;    
        } else {
            cout << "Error\n";
            exit(0);
        }
    }
    
}

int main() {
    cout << "Enter string: ";
    cin >> input;
	S();

    if(i == input.length())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}
