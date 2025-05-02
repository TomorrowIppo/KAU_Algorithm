#include <bits/stdc++.h>

using namespace std;

int n;
int cur;
stack<int> sequence;
vector<char> answer;

void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}

void solve() {
    cin >> n;
    sequence.push(cur++);

    int inp;
    for(int i = 0; i < n; i++) {
        cin >> inp;

        while(sequence.top() < inp) {
            sequence.push(cur++);
            answer.push_back('+');
        } 
        if(sequence.top() == inp) {
            sequence.pop();
            answer.push_back('-');
        } else { cout << "NO\n"; return ; }
    }

    for(auto c : answer) cout << c << '\n';
}