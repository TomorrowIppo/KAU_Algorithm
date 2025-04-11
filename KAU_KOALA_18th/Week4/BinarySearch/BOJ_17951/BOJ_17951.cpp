#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> score;

void input();
void solve();
int get_sum(int from, int to, vector<int>& arr);    // index기준 from부터 to 위치까지 접근

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    input();
    solve();

    return 0;
}

void input() {
    cin >> N >> K;
    for(int i = 0; i < N; i++) {
        int inp; cin >> inp;
        score.push_back(inp);
    }
}

void solve() {
    // Parametric Search
    int start = 0, end = 0;
    for(int i = 0; i < N; i++) end += score[i];

    while(start <= end) {
        int mid = (start + end) / 2;
        int sum = 0, cnt = 0;
        for(int i = 0; i < N; i++) {
            sum += score[i];

            if(sum >= mid) {
                cnt++;
                sum = 0;
            }
        }
        if(cnt < K) end = mid - 1;
        else start = mid + 1;
    }
    cout << end;
}