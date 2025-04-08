#include <bits/stdc++.h>

using namespace std;

vector<int> arr;

void solve();
void print_loc(size_t x, size_t y, int s);
int get_sum(size_t x, size_t y);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input & init
    int n, m, cnt = 0;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++) {
        int inp; cin >> inp;
        arr.push_back(inp);
    }
    
    // two-pointer
    size_t front = 0, back = 0;
    int sum = 0;
    while(back != n) {
        sum = get_sum(front, back);
        if(sum >= m) {
            if(sum == m) {
                cnt++;
                //print_loc(front, back, sum);
            }
            front++;
        } else back++;
    }
    cout << cnt;
}

void print_loc(size_t x, size_t y, int s) {
    cout << "front : " << x << ", back : " << y << ", sum : " << s << '\n';
}

int get_sum(size_t x, size_t y) {
    int ret = 0;
    if(x == y) ret = arr[x];
    else
        for(size_t i = x; i <= y; i++) ret += arr[i];
    
    return ret;
}
