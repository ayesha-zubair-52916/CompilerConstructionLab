#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Production {
    string lhs;
    string rhs;
};

vector<Production> prods;
int n;

// Store FIRST and FOLLOW for each non-terminal A-Z
vector<string> first[26], follow[26];
bool firstComputed[26] = {false};

// Helper: index
int idx(char c) { return c - 'A'; }

// Check if symbol is non-terminal
bool isNonTerminal(string s) {
    return (s[0]>='A' && s[0]<='Z');
}

// Add to vector if not already present
void addUnique(vector<string> &v, string s) {
    if (find(v.begin(), v.end(), s) == v.end())
        v.push_back(s);
}

// Compute FIRST of a symbol
void computeFirst(string symbol) {
    if (!isNonTerminal(symbol)) return;
    int i = idx(symbol[0]);
    if (firstComputed[i]) return;
    firstComputed[i] = true;

    for (int pi = 0; pi < prods.size(); pi++) {
        Production p = prods[pi];
        if (p.lhs == symbol) {
            if (p.rhs == "$") {
                addUnique(first[i], "$");
            } else {
                for (size_t j=0; j<p.rhs.size(); j++) {
                    string s;
                    // Handle E' or multi-char terminals like id
                    if (isupper(p.rhs[j]) && j+1<p.rhs.size() && p.rhs[j+1]=='\'') {
                        s = p.rhs.substr(j,2);
                        j++;
                    } else if (!isupper(p.rhs[j]) && j+1<p.rhs.size() && p.rhs.substr(j,2)=="id") {
                        s = "id"; j++;
                    } else s = string(1,p.rhs[j]);

                    if (!isNonTerminal(s)) {
                        addUnique(first[i], s);
                        break;
                    } else {
                        computeFirst(s);
                        int si = idx(s[0]);
                        for (int k=0; k<first[si].size(); k++) {
                            if (first[si][k]!="$") addUnique(first[i], first[si][k]);
                        }
                        if (find(first[si].begin(), first[si].end(), "$") == first[si].end())
                            break;
                        if (j==p.rhs.size()-1) addUnique(first[i], "$");
                    }
                }
            }
        }
    }
}

// Compute FOLLOW sets
void computeFollow(string symbol) {
    int i = idx(symbol[0]);
    if (symbol == prods[0].lhs) addUnique(follow[i], "$");

    for (int pi=0; pi<prods.size(); pi++) {
        Production p = prods[pi];
        for (size_t j=0; j<p.rhs.size(); j++) {
            string s;
            if (isupper(p.rhs[j]) && j+1<p.rhs.size() && p.rhs[j+1]=='\'') {
                s = p.rhs.substr(j,2); j++;
            } else if (!isupper(p.rhs[j]) && j+1<p.rhs.size() && p.rhs.substr(j,2)=="id") {
                s = "id"; j++;
            } else s = string(1,p.rhs[j]);

            if (s != symbol) continue;

            bool epsilonAfter = true;
            for (size_t k=j+1; k<p.rhs.size(); k++) {
                string next;
                if (isupper(p.rhs[k]) && k+1<p.rhs.size() && p.rhs[k+1]=='\'') {
                    next = p.rhs.substr(k,2); k++;
                } else if (!isupper(p.rhs[k]) && k+1<p.rhs.size() && p.rhs.substr(k,2)=="id") {
                    next = "id"; k++;
                } else next = string(1,p.rhs[k]);

                if (!isNonTerminal(next)) {
                    addUnique(follow[i], next);
                    epsilonAfter = false;
                    break;
                } else {
                    int ni = idx(next[0]);
                    if (first[ni].empty()) computeFirst(next);
                    for (int fidx=0; fidx<first[ni].size(); fidx++) {
                        if (first[ni][fidx]!="$") addUnique(follow[i], first[ni][fidx]);
                    }
                    if (find(first[ni].begin(), first[ni].end(), "$") == first[ni].end()) {
                        epsilonAfter = false;
                        break;
                    }
                }
            }

            if (epsilonAfter && p.lhs != symbol) {
                int li = idx(p.lhs[0]);
                if (follow[li].empty()) computeFollow(p.lhs);
                for (int fidx=0; fidx<follow[li].size(); fidx++)
                    addUnique(follow[i], follow[li][fidx]);
            }
        }
    }
}

// Print vector
void printVector(vector<string> v) {
    cout << "{ ";
    for (int i=0; i<v.size(); i++) cout << v[i] << " ";
    cout << "}\n";
}

int main() {
    cout << "Enter number of productions: ";
    cin >> n;
    cin.ignore();
    cout << "Enter productions (Example: E=TE'):\n";

    for (int i=0;i<n;i++) {
        Production p;
        string line;
        getline(cin,line);
        size_t eq = line.find('=');
        p.lhs = line.substr(0,eq);
        p.rhs = line.substr(eq+1);
        prods.push_back(p);
    }

    char choice;
    do {
        string c;
        cout << "\nFind FIRST and FOLLOW of: ";
        cin >> c;

        computeFirst(c);
        cout << "FIRST("<<c<<") = "; printVector(first[idx(c[0])]);

        computeFollow(c);
        cout << "FOLLOW("<<c<<") = "; printVector(follow[idx(c[0])]);

        cout << "Continue? (y/n): ";
        cin >> choice;
    } while(choice=='y');

    return 0;
}
