#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll min_total = 10000000000LL;
ll max_total = -10000000000LL;
vector<ll> arr;
vector<int> oper;

void solve();
void bt(int idx, ll total);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input
    cin >> n;
    for(int i = 0; i < n; i++) {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    for(int i = 0; i < 4; i++) {
        int inp;
        cin >> inp;
        oper.push_back(inp);
    }
    
    // output
    bt(1, arr[0]);
    cout << max_total << '\n' << min_total << '\n';
}

void bt(int idx, ll total) {
    if(idx == n) {
        min_total = min(min_total, total);
        max_total = max(max_total, total);
    } else {
        for(int i = 0; i < 4; i++) {
            ll oper_total = total;  // 원본 데이터를 받아와서 연산
            if(oper[i] != 0) {
                if(i == 0) oper_total += arr[idx];           // + case
                else if(i == 1) oper_total -= arr[idx];      // - case
                else if(i == 2) oper_total *= arr[idx];      // * case
                else oper_total /= arr[idx];                 // / case
                
                oper[i]--;
                bt(idx + 1, oper_total);
                oper[i]++;
            }
        }
    }
    
    return ;
}
