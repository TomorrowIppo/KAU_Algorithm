#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> heights;
vector<int> prefix_sum;

void input();
void solve();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();

    return 0;
}

void input() {
    cin >> N >> M;
    for(int i = 0; i < N; i++) {    
        int height; cin >> height;
        heights.push_back(height);
    }

    // PrefixSum
    prefix_sum = vector<int>(N + 1, 0);
    for(int i = 0; i < M; i++) {
        int a, b, k; cin >> a >> b >> k;
        prefix_sum[a - 1] += k;
        prefix_sum[b] -= k;
    }
}

void solve() {
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum += prefix_sum[i];
        heights[i] += sum;
        cout << heights[i] << ' ';
    }
}