/*
 O(N) 로직으로 구현해야 한다 (1 <= N <= 10^6)
 각 자리수를 분해해서 판단하면 될 듯 (1, 10, 100, 1000, 10000, 100000, 1000000)
 */

#include <bits/stdc++.h>

using namespace std;

void solve();
int get_clap_cnt(int n);
void test();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //test();
    solve();
    
    return 0;
}

void solve() {
    int n;
    cin >> n;
    
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        //int tmp = get_clap_cnt(i);
        //if(tmp != 0) cout << i << ' ';
        
        ans += get_clap_cnt(i);
    }
    
    cout << ans << '\n';
}


int get_clap_cnt(int n) {
    int ret = 0;
    
    string tmp = to_string(n);
    for(auto num : tmp) {
        int ctoi = num - '0';
        
        if((ctoi % 3) == 0 && ctoi != 0) ret++;
    }
    
    return ret;
}

void test() {
    int t;
    cin >> t;
    
    while(t--) {
        solve();
    }
}
