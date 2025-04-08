#include <bits/stdc++.h>
#define MAX 9

using namespace std;

void solve();
void bt(int x, int level);
void printArr();

int n, m;
vector<int> arr;
bool vis[MAX];

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

/*
 N과 M(1) BOJ_15659 경우는 Permutation을 구하는 것이기에
 for(i=1 to n)까지에서 재방문 제외하고 재귀함수를 진행했다면
 
 현 문제는 Combination을 구하는 것이기에
 for(i=x to n)까지에서 재방문 제외하고 재귀함수를 진행하면 된다.
 x=n일 때는 어짜피 그 다음 방문에서 n + 1이 되므로 알아서 걸러진다.
 */
void bt(int x, int level) {
    if(level == m) printArr();
    else {
        for(int i = x; i <= n; i++) {
            if(!vis[i]) {
                vis[i] = true; arr.push_back(i);
                bt(i + 1, level + 1);
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
