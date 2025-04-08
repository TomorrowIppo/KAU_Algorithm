#include <bits/stdc++.h>
#define MAX 9

using namespace std;

void solve();
void bt(int x, int level);
void printArr();

int n, m, cnt = 0;
bool vis[MAX];
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> n >> m;
    bt(1, 0);
}

void bt(int x, int level) {
    if(level == m) printArr();
    else {
        for(int i = 1; i <= n; i++) {
            if(!vis[i]) {
                vis[i] = true; arr.push_back(i);
                bt(x + 1, level + 1);
                vis[i] = false; arr.pop_back();
            }
        }
    }
}

void printArr() {
    for(auto item : arr)
        cout << item << ' ';
    cout << '\n';
}
