#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cin >> input;

    int state = 0;

    for (int i = 0; i < input.length(); i++) {

        char c = input[i];

        if (state == 0) {
            if (c == '0')
                state = 1;
            else
                state = 0;
        }

        else if (state == 1) {
            if (c == '1')
                state = 2;
            else
                state = 1;
        }

        else if (state == 2) {
            if (c == '0')
                state = 1;
            else
                state = 0;
        }
    }

    if (state == 2)
        cout << "Accepted";
    else
        cout << "Rejected";

    return 0;
}
