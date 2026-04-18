#include<iostream>
#include<string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int state = 0;

    //for (char c : s) {
    	
    for (int i = 0; i < s.length(); i++) {

        char c = s[i];
	
    	
        if (state == 0) {
            if (c == 'a') state = 1;
        }
        else if (state == 1) {
            if (c == 'b') state = 2;
            else state = 1;
        }
        else if (state == 2) {
            if (c == 'b') state = 3;
            else state = 1;
        }
    }

    if (state == 3)
        cout << "Accepted";
    else
        cout << "Rejected";
}

