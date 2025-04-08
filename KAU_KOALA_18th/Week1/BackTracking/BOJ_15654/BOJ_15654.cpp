#include <bits/stdc++.h>
#define MAX 9

using namespace std;

void solve();
void bt(int idx, int level);
void printArr();

int n, m;
vector<int> arr;
vector<int> inp;
bool vis[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        inp.push_back(num);
    }
    sort(inp.begin(), inp.end());
    
    // solve
    bt(0, 0);
}

/*
 N과 M(2) 15650에서 구현한 Combination에서 1 ~ n의 숫자를 inp[0] ~ inp[n - 1]로 변환하면 됨
 */
void bt(int idx, int level) {
    if(level == m) printArr();
    else {
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                vis[i] = true; arr.push_back(inp[i]);
                bt(idx + 1, level + 1);
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
