#include <iostream>
using namespace std;

string input;
int i = 0;

void E();
void Eprime();
void T(); 
void Tprime();
void F();

void match(char c) {
    if(input[i] == c)
        i++;
    else {
        cout << "Error\n";
        exit(0);
    }
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if(input[i] == '-') {
        match('-');
        T();
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if(input[i] == '*') {
        match('*');
        F();
        Tprime();
    }
}

void F() {
    if(input[i] == 'i') {
        match('i');
    }
    else if(input[i] == '(') {
        match('(');
        E();
        match(')');
    }
    else {
        cout << "Error\n";
        exit(0);
    }
}

int main() {
    cout << "Enter expression: ";
    cin >> input;

    E();

    if(i == input.length())
        cout << "Accepted\n";
    else
        cout << "Rejected\n";
}

/*
E  = T E'
E' = - T E' | e

T  = F T'
T' = * F T' | e

F  = i | (E)

*/

