//#include <iostream>
//#include <stack>
//#include <vector>
//#include <map>
//using namespace std;
//
//int main(){
//    // ====== Action table ======
//    map<int,map<string,string>> action;
//    action[0]["a"]="s3"; 
//    action[0]["b"]="s4";
//    action[1]["$"]="acc";
//    action[2]["a"]="s3";
//    action[2]["b"]="s4";
//    action[3]["a"]="s3"; 
//    action[3]["b"]="s4";
//    action[4]["a"]="r4"; 
//    action[4]["b"]="r4"; 
//    action[4]["$"]="r4";
//    action[5]["$"]="r2";
//    action[6]["a"]="r3";
//    action[6]["b"]="r3";
//    action[6]["$"]="r3";
//
//    // ====== Goto table ======
//    map<int,map<string,int>> goTo;
//    goTo[0]["E"]=1; 
//    goTo[0]["T"]=2;
//    goTo[2]["T"]=5; 
//    goTo[3]["T"]=6;
//
//    // ====== Production lengths ======
//    map<int,int> prodLen;
//    prodLen[1]=1; // E' ? E
//    prodLen[2]=2; // E ? T T
//    prodLen[3]=2; // T ? a T
//    prodLen[4]=1; // T ? b
//
//    vector<string> input;
//    string sym;
//    cout << "Enter input string (space separated, end with $): ";
//    while(cin >> sym){
//        input.push_back(sym);
//        if(sym=="$") break;
//    }
//
//    stack<int> st;
//    st.push(0);
//    int i=0;
//    cout << "\n=== Parsing Steps ===\n";
//    while(true){
//        int state = st.top();
//        string curr = input[i];
//        string act = action[state][curr];
//        if(act==""){ cout<<"Error: invalid input at "<<curr<<endl; break; }
//
//        if(act[0]=='s'){ // shift
//            int next = stoi(act.substr(1));
//            st.push(next);
//            cout<<"Shift '"<<curr<<"', push state "<<next<<endl;
//            i++;
//        }
//        else if(act[0]=='r'){ // reduce
//            int p = stoi(act.substr(1));
//            int len = prodLen[p];
//            for(int j=0;j<len;j++) st.pop();
//            int top = st.top();
//            string lhs;
//            if(p==1) lhs="E"; // E' ? E
//            else if(p==2) lhs="E"; // E ? T T
//            else lhs="T"; // T ? aT or T?b
//            st.push(goTo[top][lhs]);
//            cout<<"Reduce by production "<<p<<", push state "<<st.top()<<endl;
//        }
//        else if(act=="acc"){
//            cout<<"Input Accepted \n";
//            break;
//        }
//    }
//    return 0;
//}
//


#include <iostream>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int main(){

    // ====== Action table ======
    map<int,map<string,string>> action;

    action[0]["a"]="s3"; 
    action[0]["b"]="s4";

    action[1]["$"]="acc";

    action[2]["c"]="s6"; 
    action[2]["d"]="s7";

    action[3]["a"]="s3"; 
    action[3]["b"]="s4";

    action[4]["c"]="r3"; 
    action[4]["d"]="r3";

    action[5]["$"]="r1";

    action[6]["c"]="s6"; 
    action[6]["d"]="s7";

    action[7]["$"]="r5";

    action[8]["c"]="r2"; 
    action[8]["d"]="r2";

    action[9]["$"]="r4";


    // ====== Goto table ======
    map<int,map<string,int>> goTo;

    goTo[0]["S"]=1;
    goTo[0]["A"]=2;
    goTo[2]["B"]=5;
    goTo[3]["A"]=8;
    goTo[6]["B"]=9;


    // ====== Production lengths ======
    map<int,int> prodLen;

    prodLen[1]=2; // S ? A B
    prodLen[2]=2; // A ? a A
    prodLen[3]=1; // A ? b
    prodLen[4]=2; // B ? c B
    prodLen[5]=1; // B ? d


    vector<string> input;
    string sym;

    cout << "Enter input string (space separated, end with $): ";
    while(cin >> sym){
        input.push_back(sym);
        if(sym=="$") break;
    }


    stack<int> st;
    st.push(0);

    int i=0;

    cout << "\n=== Parsing Steps ===\n";

    while(true){

        int state = st.top();
        string curr = input[i];

        string act = action[state][curr];

        if(act==""){
            cout<<"Error: invalid input at "<<curr<<endl;
            break;
        }

        if(act[0]=='s'){ // SHIFT
            int next = stoi(act.substr(1));
            st.push(next);
            cout<<"Shift '"<<curr<<"', push state "<<next<<endl;
            i++;
        }

        else if(act[0]=='r'){ // REDUCE
            int p = stoi(act.substr(1));
            int len = prodLen[p];

            for(int j=0;j<len;j++) st.pop();

            int top = st.top();
            string lhs;

            if(p==1) lhs="S";
            else if(p==2 || p==3) lhs="A";
            else lhs="B";

            st.push(goTo[top][lhs]);

            cout<<"Reduce by production "<<p<<", push state "<<st.top()<<endl;
        }

        else if(act=="acc"){
            cout<<"Input Accepted\n";
            break;
        }
    }

    return 0;
}
