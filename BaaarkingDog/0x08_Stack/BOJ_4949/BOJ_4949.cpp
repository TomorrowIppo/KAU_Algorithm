#include <bits/stdc++.h>

using namespace std;

void solve();
void check_bracket(string str);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    while(true) {
        string inp;
        getline(cin, inp);
        
        if(inp == ".") return ; // 종료조건
        
        check_bracket(inp);
    }
}

void check_bracket(string str) {
    stack<char> s;
    
    for(auto cur : str) {
        switch (cur) {
            case '(': case '[':
                s.push(cur);
                break;
            case ')': case ']': { // 스택이 비었으면 종료
                if(s.empty()) {
                    cout << "no" << '\n';
                    return ;
                }
                char prev = s.top(); s.pop();
                
                // 짝이 안 맞으면 종료
                if((prev != '(' && cur == ')') ||
                   (prev != '[' && cur == ']')) {
                    cout << "no" << '\n';
                    return ;
                }
                break;
            }
            default:
                // pass
                break;
        }
    }
    if(!s.empty()) cout << "no" << '\n';    // stack이 비어있지 않다는 것은 닫히지 않은 괄호가 남아있다는 것
    else cout << "yes" << '\n';
}
