//#include <iostream>
//#include <stack>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main() {
//    // ====== Action Table ======
//    // Format: action[state][terminal] = "sX" (shift), "rY" (reduce), "acc" (accept)
//    map<int, map<string, string>> action;
//    
//    action[0]["a"] = "s3"; 
//    action[0]["b"] = "s4";
//    action[1]["$"] = "acc";
//    action[2]["a"] = "s3"; 
//    action[2]["b"] = "s4";
//    action[3]["a"] = "s3";
//    action[3]["b"] = "s4";
//    action[4]["a"] = "r3"; 
//    action[4]["b"] = "r3"; 
//    action[4]["$"] = "r3";
//    action[5]["$"] = "r1";
//    action[6]["a"] = "r2";
//    action[6]["b"] = "r2"; 
//    action[6]["$"] = "r2";
//
//    // ====== Goto Table ======
//    
//map<int, map<string, int>> goTo;
//    goTo[0]["E"] = 1; 
//    goTo[0]["T"] = 2;
//    goTo[2]["T"] = 5;
//    goTo[3]["T"] = 6;
//
//    // ====== Production lengths (for reduction) ======
//    // prodLen[production number] = number of symbols on RHS
//    
//map<int, int> prodLen;
//    prodLen[1] = 2; // E ? T T
//    prodLen[2] = 2; // T ? a T
//    prodLen[3] = 1; // T ? b
//
//    // ====== Input ======
//   
// vector<string> input;
//    string symbol;
//    cout << "Enter input string (space separated, end with $): ";
//    while (cin >> symbol) {
//        input.push_back(symbol);
//        if (symbol == "$") break;
//    }
//
//    // ====== Stack for LR(0) Parser ======
//    
//    stack<int> st;
//    st.push(0); // initial state
//
//    int i = 0; // input pointer
//
//    cout << "\n=== Parsing Steps ===\n";
//    while (true) {
//        int state = st.top();
//        string curr = input[i];
//
//        if (action[state][curr] == "") {
//            cout << "Error: Invalid input at symbol " << curr << endl;
//            break;
//        }
//
//        string act = action[state][curr];
//
//        if (act[0] == 's') { // Shift
//            int nextState = stoi(act.substr(1));
//            st.push(nextState);
//            cout << "Shift '" << curr << "', push state " << nextState << endl;
//            i++;
//        }
//        else if (act[0] == 'r') { // Reduce
//            int prodNo = stoi(act.substr(1));
//            int len = prodLen[prodNo];
//            for (int j = 0; j < len; j++) st.pop(); // pop RHS symbols
//            int topState = st.top();
//            string lhs;
//            if (prodNo == 1) lhs = "E";
//            else lhs = "T";
//            st.push(goTo[topState][lhs]); // push goto state
//            cout << "Reduce by production " << prodNo << " (" << lhs << " ? ";
//            if (prodNo == 1) cout << "T T";
//            else if (prodNo == 2) cout << "a T";
//            else cout << "b";
//            cout << "), push state " << st.top() << endl;
//        }
//        else if (act == "acc") { // Accept
//            cout << "Input Accepted \n";
//            break;
//        }
//    }
//
//    return 0;
//}


#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main() {

    // ====== Action Table ======
    map<int, map<string, string>> action;

    action[0]["a"] = "s3";
    action[0]["b"] = "s4";

    action[1]["$"] = "acc";

    action[2]["c"] = "s6";
    action[2]["d"] = "s7";

    action[3]["a"] = "s3";
    action[3]["b"] = "s4";

    action[4]["a"] = "r3";
    action[4]["b"] = "r3";
    action[4]["c"] = "r3";
    action[4]["d"] = "r3";
    action[4]["$"] = "r3";

    action[5]["$"] = "r1";

    action[6]["c"] = "s6";
    action[6]["d"] = "s7";

    action[7]["a"] = "r5";
    action[7]["b"] = "r5";
    action[7]["c"] = "r5";
    action[7]["d"] = "r5";
    action[7]["$"] = "r5";

    action[8]["a"] = "r2";
    action[8]["b"] = "r2";
    action[8]["c"] = "r2";
    action[8]["d"] = "r2";
    action[8]["$"] = "r2";

    action[9]["a"] = "r4";
    action[9]["b"] = "r4";
    action[9]["c"] = "r4";
    action[9]["d"] = "r4";
    action[9]["$"] = "r4";


    // ====== Goto Table ======
    map<int, map<string, int>> goTo;

    goTo[0]["S"] = 1;
    goTo[0]["A"] = 2;
    goTo[2]["B"] = 5;
    goTo[3]["A"] = 8;
    goTo[6]["B"] = 9;


    // ====== Production lengths ======
    map<int, int> prodLen;

    prodLen[1] = 2; // S ? A B
    prodLen[2] = 2; // A ? a A
    prodLen[3] = 1; // A ? b
    prodLen[4] = 2; // B ? c B
    prodLen[5] = 1; // B ? d


    vector<string> input;
    string symbol;

    cout << "Enter input string (space separated, end with $): ";
    while (cin >> symbol) {
        input.push_back(symbol);
        if (symbol == "$") break;
    }


    stack<int> st;
    st.push(0);

    int i = 0;

    cout << "\n=== Parsing Steps ===\n";

    while (true) {
        int state = st.top();
        string curr = input[i];

        if (action[state][curr] == "") {
            cout << "Error: Invalid input at symbol " << curr << endl;
            break;
        }

        string act = action[state][curr];

        if (act[0] == 's') {
            int nextState = stoi(act.substr(1));
            st.push(nextState);
            cout << "Shift '" << curr << "', push state " << nextState << endl;
            i++;
        }
        else if (act[0] == 'r') {
            int prodNo = stoi(act.substr(1));
            int len = prodLen[prodNo];

            for (int j = 0; j < len; j++) st.pop();

            int topState = st.top();
            string lhs;

            if (prodNo == 1) lhs = "S";
            else if (prodNo == 2 || prodNo == 3) lhs = "A";
            else lhs = "B";

            st.push(goTo[topState][lhs]);

            cout << "Reduce by production " << prodNo << ", push state " << st.top() << endl;
        }
        else if (act == "acc") {
            cout << "Input Accepted\n";
            break;
        }
    }

    return 0;
}

