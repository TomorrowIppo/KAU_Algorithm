#include <bits/stdc++.h>
#define INF 987654321

using namespace std;

int N;
vector<int> solution;

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
    cin >> N;
    for(int i = 0; i < N; i++) {
        int num; cin >> num;
        solution.push_back(num);
    }
    // solution[i - 1] <= solution[i]를 보장하므로 sort 필요 X
}

void solve() {
    // Two-Pointer
    int ans = INF;
    int left = 0, right = solution.size() - 1;
    while(left < right) {
        int dist = solution[left] + solution[right];

        if(abs(dist) < abs(ans)) ans = dist;
        
        if(dist == 0) break;
        else if(dist < 0) left++;
        else right--;
    }
    cout << ans;
}