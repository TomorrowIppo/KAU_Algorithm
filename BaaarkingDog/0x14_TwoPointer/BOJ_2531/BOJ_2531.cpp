#include <bits/stdc++.h>

using namespace std;

int N, d, k, c;
vector<int> arr;

void solve();
void log(vector<int> win, size_t cnt);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    // input & init
    cin >> N >> d >> k >> c;
    for(int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        arr.push_back(inp);
    }
    
    // sliding-window
    size_t pin = 0;
    vector<int> window;
    
    size_t ret = 0;
    while(true) {
        if(pin == N) break;
        
        window.clear();
        vector<bool> vis(3001, false); // 윈도우 내에서의 중복 판별용
        
        size_t idx = pin;
        for(int i = 0; i < k; i++) {
            if(idx == N) idx = 0;   // 끝점에 오면 다시 원점으로
            window.push_back(arr[idx]);
            idx++;
        }
        window.push_back(c);    // 쿠폰도 추가해서 연산
        
        size_t item_cnt = k + 1;
        for(auto item : window) {
            if(vis[item]) {
                item_cnt--;
            } else vis[item] = true;
        }
        
        //log(window, item_cnt);
        ret = max(ret, item_cnt);
        pin++;
    }
    cout << ret << '\n';
}

void log(vector<int> win, size_t cnt) {
    cout << "Window item : ";
    for(auto item : win) cout << item << ' ';
    cout << ", cnt : " << cnt << '\n';
}
