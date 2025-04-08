#include <bits/stdc++.h>
#define MAX 2000000000

using namespace std;

int N, M;
vector<int> arr;
void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input & init
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    sort(arr.begin(), arr.end());
    
    // two-pointer
    size_t left = 0;
    size_t right = 0;
    
    int ret = MAX;
    while(right != N) {
        int diff = abs(arr[left] - arr[right]);
        if(diff >= M) {
            left++;
            ret = min(ret, diff);
            if(diff == 0) break;
            else if(left == right) right++;
            
        } else right++;
    }
    cout << ret;
}
