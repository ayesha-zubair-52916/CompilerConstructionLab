#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

char production[10][10];
int n;

// Arrays to store FIRST and FOLLOW (A-Z)
char first[26][20];
int firstCount[26] = {0};
char follow[26][20];
int followCount[26] = {0};

// Helper: get index of non-terminal
int idx(char c) { return c - 'A'; }

// Check if character exists in array
bool exists(char arr[], int cnt, char c) {
    for(int i=0; i<cnt; i++)
        if(arr[i]==c) return true;
    return false;
}

// Compute FIRST of a non-terminal
void computeFirst(char c) {
    int i = idx(c);

    // Already computed
    if(firstCount[i]>0) return;

    for(int p=0; p<n; p++) {
        if(production[p][0]==c) {
            char *rhs = production[p]+2; // skip X=
            if(rhs[0]=='$') { // epsilon
                if(!exists(first[i], firstCount[i], '$'))
                    first[i][firstCount[i]++] = '$';
            } else {
                for(int j=0; rhs[j]; j++) {
                    char sym = rhs[j];
                    if(!isupper(sym)) { // terminal
                        if(!exists(first[i], firstCount[i], sym))
                            first[i][firstCount[i]++] = sym;
                        break;
                    } else { // non-terminal
                        computeFirst(sym);
                        bool hasEpsilon = false;
                        for(int k=0; k<firstCount[idx(sym)]; k++) {
                            char f = first[idx(sym)][k];
                            if(f!='$' && !exists(first[i], firstCount[i], f))
                                first[i][firstCount[i]++] = f;
                            if(f=='$') hasEpsilon = true;
                        }
                        if(!hasEpsilon) break;
                        if(rhs[j+1]=='\0' && hasEpsilon && !exists(first[i], firstCount[i], '$'))
                            first[i][firstCount[i]++] = '$';
                    }
                }
            }
        }
    }
}

// Compute FOLLOW of a non-terminal
void computeFollow(char c) {
    int i = idx(c);
    if(production[0][0]==c && !exists(follow[i], followCount[i], '$'))
        follow[i][followCount[i]++] = '$'; // start symbol

    for(int p=0; p<n; p++) {
        char *rhs = production[p]+2;
        for(int j=0; rhs[j]; j++) {
            if(rhs[j]==c) {
                bool epsilonAfter = true;
                for(int k=j+1; rhs[k]; k++) {
                    char next = rhs[k];
                    if(!isupper(next)) { // terminal after
                        if(!exists(follow[i], followCount[i], next))
                            follow[i][followCount[i]++] = next;
                        epsilonAfter = false;
                        break;
                    } else { // non-terminal after
                        computeFirst(next);
                        for(int m=0; m<firstCount[idx(next)]; m++) {
                            char f = first[idx(next)][m];
                            if(f!='$' && !exists(follow[i], followCount[i], f))
                                follow[i][followCount[i]++] = f;
                        }
                        if(exists(first[idx(next)], firstCount[idx(next)], '$'))
                            epsilonAfter = true;
                        else {
                            epsilonAfter = false;
                            break;
                        }
                    }
                }
                if(epsilonAfter && rhs[j]!=production[p][0]) { // add FOLLOW of LHS
                    computeFollow(production[p][0]);
                    for(int m=0; m<followCount[idx(production[p][0])]; m++) {
                        char f = follow[idx(production[p][0])][m];
                        if(!exists(follow[i], followCount[i], f))
                            follow[i][followCount[i]++] = f;
                    }
                }
            }
        }
    }
}

// Print FIRST of a non-terminal
void printFirst(char c) {
    int i = idx(c);
    cout<<"FIRST("<<c<<") = { ";
    for(int j=0; j<firstCount[i]; j++)
        cout<<first[i][j]<<" ";
    cout<<"}\n";
}

// Print FOLLOW of a non-terminal
void printFollow(char c) {
    int i = idx(c);
    cout<<"FOLLOW("<<c<<") = { ";
    for(int j=0; j<followCount[i]; j++)
        cout<<follow[i][j]<<" ";
    cout<<"}\n";
}

int main() {
    cout<<"Enter number of productions: ";
    cin>>n;
    cout<<"Enter productions (Example: E=TR):\n";
    for(int i=0;i<n;i++)
        cin>>production[i];

    char choice;
    do {
        char c;
        cout<<"\nFind FIRST and FOLLOW of: ";
        cin>>c;

        computeFirst(c);
        printFirst(c);

        computeFollow(c);
        printFollow(c);

        cout<<"Continue? (y/n): ";
        cin>>choice;
    } while(choice=='y');

    return 0;
}
