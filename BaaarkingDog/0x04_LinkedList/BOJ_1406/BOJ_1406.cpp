#include <bits/stdc++.h>

using namespace std;

int M;
string str;
list<char> ls;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> str;
    cin >> M;
    
    for(auto c : str) ls.push_back(c);
    list<char>::iterator t = ls.end();
    
    for(int i = 0; i < M; i++) {
        char inp;
        cin >> inp;
        
        if(inp == 'P') {
            char c;
            cin >> c;
            
            ls.insert(t, c);
        } else if(inp == 'L') {
            if(t != ls.begin()) t--;
        } else if(inp == 'D') {
            if(t != ls.end()) t++;
        } else {    // B
            if(t != ls.begin()) {
                t--;
                t = ls.erase(t);
            }
        }
    }
    
    for(auto item : ls) cout << item;
    cout << '\n';
    
    return 0;
}
